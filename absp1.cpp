#include<cstdio>
#include<vector>
using namespace std;
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int n;
        scanf("%d", &n);
        int tmp;
        scanf("%d", &tmp);
        long long sum = 0;
        int count = 1;
        int diff = 0;
        for(int i=0;i<n-1;++i) {
            int val;
            scanf("%d", &val);
                count++;
                diff = diff + (val - tmp) * (count - 1);
                sum += diff;
                tmp = val;
        }
        printf("%lld\n", sum);

    }
}
