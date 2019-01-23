#include<cstdio>
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int x, y;
        scanf("%d %d", &x, &y);
        int y1 = x;
        int y2 = x-2;
        int val;
        if(x & 1) {
            // odd x
            if(y == y1) {
                val = (x * 2) - 1;
            } else if(y == y2) {
                val = (x * 2) - 3;
            } else {
                printf("No Number\n");
                continue;
            }
        } else {
            if(y == y1) {
                val = 2*x;
            } else if(y == y2) {
                val = 2 * (x - 1);
            } else {
                printf("No Number\n");
                continue;
            }
        }
        if(val < 0) {
            printf("No Number\n");
        } else {
            printf("%d\n", val);
        }
    }
}
