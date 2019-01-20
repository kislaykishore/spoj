#include<cstdio>
unsigned long long rev(unsigned long long num) {
    unsigned long long t = num;
    unsigned long long val = 0;
    while(t != 0) {
        val = val * 10 + (t % 10);
        t /= 10;
    }
    return val;
}
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        unsigned long long int a, b;
        scanf("%llu %llu", &a, &b);
        unsigned long long sum = rev(rev(a) + rev(b));
        printf("%llu\n", sum);
    }
}
