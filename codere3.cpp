#include<cstdio>
#include<cstring>
#define max(x, y) (x >y?x:y)
int computeMaxIncSubseq(int* array, int idx, int* dp) {
    if(idx < 0) {
        return 0;
    }
    if(dp[idx] != -1) {
        return dp[idx];
    }
    // assuming that idx value is part of the subsequence
    int maxLength = 0;
    for(int i=idx-1;i>=0;i--) {
        if(array[i] < array[idx]) {
            // it can be part of subsequence
            // we have to find the max length
            int length = computeMaxIncSubseq(array, i, dp);
            maxLength = length > maxLength?length:maxLength;
        }
    }
    dp[idx] = maxLength + 1;
    return dp[idx];
}

int computeMaxDecSubseq(int* array, int idx, int* dp, int n) {
    if(idx >= n) {
        return 0;
    }
    if(dp[idx] != -1) {
        return dp[idx];
    }
    int maxLength = 0;
    for(int i=idx+1;i<n;++i) {
        if(array[i] < array[idx]) {
            int length = computeMaxDecSubseq(array, i, dp, n);
            maxLength = maxLength > length?maxLength:length;
        }
    }
    dp[idx] = maxLength + 1;
    return dp[idx];
}


int computeMaxSubseq(int* array, int n) {
    int maxLen = 0;
    int* dpInc = new int[n+1];
    int* dpDec = new int[n+1];
    memset(dpInc, -1, sizeof(int) * (n+1));
    memset(dpDec, -1, sizeof(int) * (n+1));
    int maxLength = 0;
    for(int i=-1;i<n;++i) {
        int lengthInc = computeMaxIncSubseq(array, i, dpInc);
        int val = i<0?-1:array[i];
        for(int j=i+1;j<n;++j) {
            if(array[j] == val) {
                continue;
            }
            int lengthDec = computeMaxDecSubseq(array, j, dpDec, n);
            if(lengthInc + lengthDec > maxLength) {
                maxLength = lengthInc + lengthDec;
            }
        }
    }
    delete [] dpInc;
    delete [] dpDec;
    return maxLength;
}
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int n;
        scanf("%d", &n);
        int* array = new int[n];
        for(int i=0;i< n;++i) {
            scanf("%d", array+i);
        }
        int val = computeMaxSubseq(array, n);
        delete [] array;
        printf("%d\n", val);
    }
}

