#include<cstdio>
#include<cstring>
#define max(x, y) x>y?x:y
long long computeMax(int* coins, long long* dpArray, int idx, int n) {
    if(idx < 0) {
        return 0;
    }
    if(dpArray[idx] != -1) {
        return dpArray[idx];
    }
    long long val1 = computeMax(coins, dpArray, idx - 1, n);
    long long val2 = computeMax(coins, dpArray, idx-2, n) + coins[idx];
    dpArray[idx] = max(val1, val2);
    return dpArray[idx];
}
int main() {
    int test;
    scanf("%d", &test);
    for(int a=1;a<=test;++a) {
        int n;
        scanf("%d", &n);
        int* coins = new int[n];
        for(int i=0;i<n;++i) {
            scanf("%d", coins + i);
        }
        long long* dpArray = new long long[n];
        memset(dpArray, -1, sizeof(long long) * n);
        long long amount = computeMax(coins, dpArray, n-1, n);
        delete [] coins;
        delete [] dpArray;
        printf("Case %d: %lld\n", a, amount);
    }
}
