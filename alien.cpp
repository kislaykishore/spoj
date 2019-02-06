#include<cstdio>
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int *stations = new int[a];
        for(int i=0;i<a;++i) {
            scanf("%d", stations + i);
        }
        int startPtr = 0;
        int endPtr = 0;
        int curSum = stations[0];
        int maxLen = 0;
        int maxFolks = 0;
        while(endPtr < a) {
            if(curSum > b) {
                curSum -= stations[startPtr];
                startPtr++;
            } else {
                int delta = endPtr - startPtr + 1;
                if(maxLen == delta && curSum < maxFolks) {
                    maxFolks = curSum;
                } else if(maxLen < delta) {
                    maxLen = delta;
                    maxFolks = curSum;
                }
                endPtr++;
                curSum += stations[endPtr];
            }
        }
        printf("%d %d\n", maxFolks, maxLen);
    }
}
