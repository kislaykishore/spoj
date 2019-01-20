#include<cstdio>
#include<cstring>
using namespace std;
int main() {
    int tests;
    scanf("%d", &tests);
    int idx = 0;
    while(tests--) {
        idx++;
        int n, m;
        scanf("%d %d", &n, &m);
        int *array = new int[n];
        bool b[1025];
        memset(b, 0, sizeof(b));
        for(int i=0;i<n;++i) {
            scanf("%d", array + i);
        }
        for(int i=0;i<m;++i) {
            int x;
            scanf("%d", &x);
            b[x] = true;
        }
        int** dp = new int*[n+1];
        for(int i=0;i<=n;++i) {
            dp[i] = new int[1025];
            memset(dp[i], 0, 1025);
        } 
        dp[0][0] = 1;

        // dp[i][j] = dp[i-1][j] + dp[i-1][j^a]

        // for i = 0, dp[0][*] = 0

        int mod = 100000007;
        for(int i=1;i<=n;++i) {
            for(int j=0;j<1024;++j) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j ^ array[i-1]];
                if(dp[i][j] >= mod) {
                    dp[i][j] -= mod;
                }
            }
        }

        int sum = 0;
        for(int i=0;i<1024;++i) {
            if(!b[i]) {
                sum += dp[n][i];
                if(sum >= mod) {
                    sum -= mod;
                }
            }
        }
        printf("Case %d: %d\n", idx, sum);
        delete [] array;
        for(int i=0;i<=n;++i) {
            delete dp[i];
        }
        delete [] dp;

    }
}
