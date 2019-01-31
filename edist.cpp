#include<cstdio>
#include<cstring>
#define min(x, y) x < y?x:y

int computeEditDist(int** dp, char* str1, int idx1, char* str2, int idx2) {
    if(idx1 == 0) {
        return idx2;
    } else if(idx2 == 0) {
        return idx1;
    }
    if(dp[idx1][idx2] != -1) {
        return dp[idx1][idx2];
    }
  
    int cost; 
    if(str1[idx1-1] == str2[idx2-1]) {
        cost = computeEditDist(dp, str1, idx1-1, str2, idx2-1);
    } else {
        // delete one of the characters
        cost = computeEditDist(dp, str1, idx1-1, str2, idx2) + 1;
        int candidateCost = computeEditDist(dp, str1, idx1, str2, idx2-1) + 1;
        cost = min(candidateCost, cost);

        //replace one of the characters
        candidateCost = computeEditDist(dp, str1, idx1 - 1, str2, idx2 - 1) + 1;
        cost = min(candidateCost, cost);
    }
    dp[idx1][idx2] = cost;
    return cost;

}
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        char str1[2001];
        char str2[2001];
        scanf("%s", str1);
        scanf("%s", str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int** dp = new int*[len1+1];
        for(int i=0;i<=len1;++i) {
            dp[i] = new int[len2 + 1];
            for(int j=0;j<=len2;++j) {
                dp[i][j] = -1;
            }
        }
 
        int editDist = computeEditDist(dp, str1, len1, str2, len2);
        for(int i=0;i<=len1;++i) {
            delete dp[i];
        }
        delete [] dp;
        printf("%d\n", editDist);
    }
}
