#include<cstdio>
#include<cstring>
#define max(x, y) x > y?x:y
int computeCost(int **dp, int lIndex, int rIndex, int* numArray, int* cumSumArray) {
    if(lIndex == rIndex) {
        return numArray[lIndex];
    }
    if(dp[lIndex][rIndex] != -1) {
        return dp[lIndex][rIndex];
    }

    int c1 = computeCost(dp, lIndex + 1, rIndex, numArray, cumSumArray) + cumSumArray[rIndex] - cumSumArray[lIndex] + numArray[lIndex];
    int prevsum = lIndex == 0?0:cumSumArray[lIndex-1];
    int c2 = computeCost(dp, lIndex, rIndex - 1, numArray, cumSumArray) + cumSumArray[rIndex-1] - prevsum + numArray[rIndex];
    int cost = max(c1, c2);
    dp[lIndex][rIndex] = cost;
    return cost;
}
int main() {
    int n;
    scanf("%d", &n);
    int **dp = new int*[n + 1];
    for(int i=0;i<=n;++i) {
        dp[i] = new int[n+1];
        memset(dp[i], -1, sizeof(int) * (n+1));
    }

    int *numArray = new int[n];
    int *cumSumArray = new int[n];
    int cumSum = 0;
    for(int i=0;i<n;++i) {
        scanf("%d", numArray + i);
        cumSum += numArray[i];
        cumSumArray[i] = cumSum;
    }

    int cost = computeCost(dp, 0, n - 1, numArray, cumSumArray);
    printf("%d\n", cost);

    for(int i=0;i<=n;++i) {
        delete [] dp[i];
    }
    delete [] dp;
}
