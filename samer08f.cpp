#include<cstdio>
int main() {
    while(true) {
        int n;
        scanf("%d", &n);
        if(n==0) {
            return 0;
        }
        printf("%d\n", (n * (n+1) * (2*n +1))/6);
    }
}
