#include<cstdio>
#include<cstring>
struct Bag {
    int weight;
    int value;
};
int dp[10001][50];
int compute(int k, int m, Bag* bags) {
    // if bag m is chosen
    if(k == 0) {
        return 0;
    }
    if(m < 0) {
        return 0;
    }
    if(dp[k][m] != -1) {
        return dp[k][m];
    } else {
        int maxVal = 0;
        if(k - bags[m].weight >= 0) {
            maxVal = compute(k - bags[m].weight, m-1, bags) + bags[m].value;
        }
        int candidateVal = compute(k, m-1, bags);
        maxVal = maxVal < candidateVal?candidateVal: maxVal;
        dp[k][m] = maxVal;
        return maxVal;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int k, m;
        scanf("%d %d", &k, &m);
        memset(dp, -1, sizeof(dp));
        Bag* bags = new Bag[m];
        for(int i=0;i<m;++i) {
            scanf("%d %d", &bags[i].weight, &bags[i].value);
        }
        int value = compute(k, m-1, bags);
        printf("Hey stupid robber, you can get %d.\n", value);
    }
}
