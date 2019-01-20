#include<cstdio>
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int r, c;
        scanf("%d %d", &r, &c);
        for(int i=0;i<r;++i) {
            for(int j=0;j<c;++j) {
                if((i & 1) ^  (j & 1)) {
                    printf(".");
                } else {
                    printf("*");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

}
