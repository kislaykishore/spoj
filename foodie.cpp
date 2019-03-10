#include<cstdio>
#include<cstring>
int dp[101][1001];
int computeMax(int* items, int index, int k) {
    if(index < 0) {
        return 0;
    }
    if(k<=0) {
        return 0;
    }
    if(dp[index][k] != -1) {
        return dp[index][k];
    }
    int val1 = 0;
    if(k - items[index] >= 0) {
        val1 = computeMax(items, index - 1, k - items[index]) + items[index];
    }
    int val2 = computeMax(items, index - 1, k);
    int maxVal = val1 > val2?val1:val2;
    dp[index][k] = maxVal;
    
    return maxVal;
}
int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        memset(dp, -1, sizeof(dp));
        int n, k;
        scanf("%d %d", &n, &k);
        int* items = new int[n];
        for(int i=0;i<n;++i) {
            int cnt;
            scanf("%d", &cnt);
            int sum = 0;
            while(cnt--) {
                int tmp;
                scanf("%d", &tmp);
                sum += tmp;
            }
            items[i] = sum;
        }

        int val = computeMax(items, n-1, k);
        printf("%d\n", val);
        delete [] items;
    }
}
