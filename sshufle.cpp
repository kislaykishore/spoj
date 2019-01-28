#include<cstdio>
#include<cstring>
long long computeWays(char* str1, int idx1, char* str2, int idx2, char* str3, int idx3, long long dpArray[60][60][60]) {
    if(str3[idx3] == '\0') {
        return 1;
    }
    if(dpArray[idx1][idx2][idx3] != -1) {
        return dpArray[idx1][idx2][idx3];
    }
    long long ways = 0;
    for(int i=0;str1[idx1 + i];++i) {
        if(str1[idx1 + i] == str3[idx3]) {
            ways += computeWays(str1, idx1+i+1, str2, idx2, str3, idx3+1, dpArray);
        }
    }
    for(int i=0;str2[idx2 + i];++i) {
        if(str2[idx2 + i] == str3[idx3]) {
            ways += computeWays(str1, idx1, str2, idx2 + i + 1, str3, idx3 + 1, dpArray);
        }
    }
    dpArray[idx1][idx2][idx3] = ways;
    return ways;
}
int main() {
    int tests;
    scanf("%d", &tests);
    char str1[61];
    char str2[61];
    char str3[61];
    long long dpArray[60][60][60];
    while(tests--) {
        memset(dpArray, -1, sizeof(dpArray));
        scanf("%s %s %s", str1, str2, str3);
        printf("%lld\n", computeWays(str1, 0, str2, 0, str3, 0, dpArray));
    }
}
