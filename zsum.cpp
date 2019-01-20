#include<cstdio>
const int MODULO = 10000007;
long long power(long long n, long long k);
int main() {
    while(true) {
        int n, k;
        scanf("%d %d", &n, &k);
        if(n == 0) {
            return 0;
        }
        long long sum = 0;
        if(k< n) {
            sum = (((2 * (power(n-1, k) * (1 + power(n-1, n-k-1)))%MODULO))%MODULO)+ (power(n, k)*(1 + power(n, n-k)))%MODULO;
        } else {
            sum = ((2*((power(n-1, n-1) * (1 + power(n-1, k-n+1)))%MODULO))%MODULO) + (power(n, n)*(1+power(n, k- n)))%MODULO;
        }
        sum %= MODULO;
        printf("%lld\n", sum);
    }
}
long long power(long long n, long long k) {
    if(n == 1 || k == 0) {
        return 1;
    }
    if(k == 1) {
        return n;
    }
    if(k % 2 == 0) {
        long long val = power(n, k/2) % MODULO;
        return (val * val) % MODULO;
    } else {
        long long val = power(n, k/2) % MODULO;
        long long val1 = (val * n) % MODULO;
        return (val * val1)  % MODULO;
    }
}
