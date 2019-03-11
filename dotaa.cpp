#include<cstdio>
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int n, m, d;
        scanf("%d %d %d", &n, &m, &d);
        int count = 0;
        for(int i=0;i<n;++i) {
            int tmp;
            scanf("%d", &tmp);
            count += (tmp-1)/d;
        }
        printf("%s\n", count >= m?"YES":"NO");
    }
}
