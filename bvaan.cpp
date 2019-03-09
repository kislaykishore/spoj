#include<cstdio>
#include<cstring>
#define max(x, y) (x>y?x:y)
int lcsc(char* str1, int idx1, char* str2, int idx2, int*** dp, int k) {
    if(k == 0) {
        return 0;
    }
    if(idx1 < 0 || idx2 < 0) {
        return -1;
    }
    if(idx1 < k-1 || idx2 < k-1) {
        return -1;
    }
    if(dp[idx1][idx2][k] != -2) {
        return dp[idx1][idx2][k];
    }
    int maxima = -1;
    if(str1[idx1] == str2[idx2]) {
        int val1 = lcsc(str1, idx1-1, str2, idx2-1, dp, k-1);
        if(val1 == -1) {
            return -1;
        } else {
            val1 += str1[idx1];
        }
        int val2 = lcsc(str1, idx1-1, str2, idx2-1, dp, k);
        maxima = max(maxima, val1);
        maxima = max(maxima, val2);
    } else {
        int val1 = lcsc(str1, idx1-1, str2, idx2, dp, k);
        int val2 = lcsc(str1, idx1, str2, idx2-1, dp, k);
        maxima = max(maxima, val1);
        maxima = max(maxima, val2);
    }

    dp[idx1][idx2][k] = maxima;
    return maxima;
}

int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        char str1[101];
        char str2[101];
        scanf("%s %s", str1, str2);
        int k;
        scanf("%d", &k);

        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int*** dp = new int**[len1];
        for(int i=0;i<len1;++i) {
            dp[i] = new int*[len2];
            for(int j=0;j<len2;++j) {
                dp[i][j] = new int[k+1];
                for(int p=0;p<=k;++p) {
                    if(p == 0) {
                        dp[i][j][p] = 0;
                    } else {
                        dp[i][j][p] = -2;
                    }
                }
            }
        }
        int val = lcsc(str1, len1-1, str2, len2-1, dp, k);
        if(val == -1) {
            val = 0;
        }
        printf("%d\n", val);

        
        for(int i=0;i<len1;++i) {
            for(int j=0;j<len2;++j) {
                delete [] dp[i][j];
            }
            delete [] dp[i];
        }
        delete [] dp;
    }
}
