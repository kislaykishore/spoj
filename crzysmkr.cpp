#include<cstdio>
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        long long n;
        scanf("%lld", &n);
        int val = ((n%11) * 8)%11;
        printf("%d\n", (11 - val) % 11);
    }
}
