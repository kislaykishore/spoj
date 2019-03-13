#include<cstdio>
int main() {
    while(true) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0 && b == 0 && c == 0) {
            return 0;
        }
        if(a - b == b - c) {
            // AP
            printf("AP %d\n", c + (b - a));
        } else {
            printf("GP %d\n", c * (b/a));
        }
    }
}
