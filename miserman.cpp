#include<cstdio>
#define min(x, y) (x < y?x:y)
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int** fares = new int*[n];
    for(int i=0;i<n;++i) {
        fares[i] = new int[m];
        for(int j=0;j<m;++j) {
            scanf("%d", fares[i] + j);
        }
    }
    int **dp = new int*[n];
    for(int i=0;i<n;++i) {
        dp[i] = new int[m];
        for(int j=0;j<m;++j) {
            dp[i][j] = -1;
        }
    }

    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(i == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j];
                if(j != 0) { 
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
                if(j != m-1) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
                }
            }
            dp[i][j] += fares[i][j];
        }
    }
    int minima = dp[n-1][0];
    for(int j=0;j<m;++j) {
        if(dp[n-1][j] < minima) {
            minima = dp[n-1][j];
        }
    }
    printf("%d\n", minima);

    for(int i=0;i<n;++i) {
        delete [] dp[i];
        delete [] fares[i];
    }
    delete [] dp;
    delete [] fares;

}
