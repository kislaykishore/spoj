#include<cstdio>
int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}
int main() {
    int test;
    scanf("%d", &test);
    for(int i=1;i<=test;++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int g = gcd(a, b);
        if(c % g == 0) {
            printf("Case %d: Yes\n", i);
        } else {
            printf("Case %d: No\n", i);
        }
    }
    return 0;
}
