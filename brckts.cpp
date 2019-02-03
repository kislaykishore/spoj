#include<cstdio>
bool check(bool* bitArray, int len) {
    int count = 0;
    for(int i=0;i<len;++i) {
        if(bitArray[i]) {
            count++;
        } else {
            count--;
            if(count < 0) {
                return false;
            }
        }
    }
    return count == 0;
}
int main() {
    int test = 10;
    for(int a=1;a<=test;++a) {
        printf("Test %d:\n", a);
        int len;
        int countDiff = 0;
        scanf("%d\n", &len);
        bool *bitArray = new bool[len];
        char str[30001];
        scanf("%s", str);
        for(int i=0;i<len;++i) {
            bitArray[i] = '(' == str[i];
            if(bitArray[i]) {
                countDiff++;
            }
        }
        countDiff = countDiff - (len - countDiff);
        int m;
        scanf("%d", &m);
        while(m--) {
            int op;
            scanf("%d", &op);
            if(op > 0) {
                int idx = op-1;
                bool val = bitArray[idx];
                if(val) {
                    countDiff -= 2;
                } else {
                    countDiff += 2;
                }
                bitArray[idx] = !bitArray[idx];
            } else if(countDiff != 0) {
                printf("NO\n");
            } else if(check(bitArray, len)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
}
