#include<cstdio>
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int n;
        scanf("%d", &n);
        double sum = 0;
        for(int i=1;i<=n;++i) {
            sum += 1.0/i;
        }
        sum *= n;
        printf("%.2f\n", sum);
    }
}
