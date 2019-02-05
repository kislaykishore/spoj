#include<cstdio>
#include<cstring>
char computeVal(int k, int l, char* dp, int m) {
    if(dp[m] != 0) {
        return dp[m];
    }
    if(m == 1 || m == k || m == l) {
         dp[m] = 'A';
    } else {
        if(computeVal(k, l, dp, m-1) == 'B') {
            dp[m] = 'A';
        }
        else if(m > k && computeVal(k, l, dp, m-k) == 'B') {
            dp[m] = 'A';
        } else if(m > l && computeVal(k, l, dp, m-l) == 'B') {
            dp[m] = 'A';
        } else {
            dp[m] = 'B';
        }
    }
    return dp[m];
}
int main() {
    int k, l, m;
    scanf("%d %d %d", &k, &l, &m);
    int *tests = new int[m];
    int maxVal = -1;
    for(int i=0;i<m;++i) {
        scanf("%d", tests + i);
        if(tests[i] > maxVal) {
            maxVal = tests[i];
        }
    }
    char *dp = new char[maxVal + 1];
    memset(dp, 0, sizeof(char) * (maxVal + 1));
    computeVal(k, l, dp, maxVal);
    char *str = new char[m+1];
    str[m] = '\0';
    for(int i=0;i<m;++i) {
        str[i] = computeVal(k, l, dp, tests[i]);
    }
    delete [] dp;
    printf("%s\n", str);
    delete [] str;
}
