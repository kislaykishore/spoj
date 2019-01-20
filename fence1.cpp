#include<cstdio>
#include<cmath>
int main() {
    while(true) {
        int l;
        scanf("%d", &l);
        if(l == 0) {
            return 0;
        }
        printf("%.2f\n", l * l / (2 * M_PI));
    }
}
