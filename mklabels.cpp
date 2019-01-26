#include<cstdio>
long long power(long long a, long long b) {
    if(b <= 0) {
        return 1;
    } else {
        long long val = power(a, b/2);
        if(b & 1) {
            return val * val * a;
        } else {
            return val * val;
        }
    }
}
int main() {
    for(int i=1;;++i) {
        int n;
        scanf("%d", &n);
        if(n == 0) {
            return 0;
        }
        printf("Case %d, N = %d, # of different labelings = %lld\n", i, n, power(n, n-2));
    }
}
