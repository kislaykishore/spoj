#include<cstdio>
#include<cmath>
int main() {
    while(true) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a==-1 && b == -1) {
            return 0;
        }
        if(b > a) {
            a ^= b;
            b ^= a;
            a ^= b;
        }

        printf("%d\n", (int)ceil((a*1.0)/(b+1)));
    }
}
