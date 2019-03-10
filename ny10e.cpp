#include<cstdio>
#include<cstring>
long long dp[65][10];
long long computeN(int n, int firstDigit) {
    if(n == 1) {
        return 1;
    }
    if(dp[n][firstDigit] != -1) {
        return dp[n][firstDigit];
    }
    long long sum = 0;
    for(int i=0;i<=firstDigit;++i) {
        sum += computeN(n-1, i);
    }
    dp[n][firstDigit] = sum;
    return sum;
}
int main() {
    int tests;
    scanf("%d", &tests);
    memset(dp, -1, sizeof(dp));
    while(tests--) {
        int n, scenario;
        scanf("%d %d", &scenario, &n);
        long long val = 0;
        for(int i=0;i<10;++i) {
            val += computeN(n, i);
        }
        printf("%d %lld\n", scenario, val);
    }
}
