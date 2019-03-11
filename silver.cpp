#include<cstdio>
int logn(int n) {
    while(n & (n-1) != 0) {
        n -= n & (-n);
    }
    int count = -1;
    while(n) {
        n >>= 1;
        count++;
    }
    return count;
}
int main() {
    int n;
    while(true) {
        scanf("%d", &n);
        if(n == 0) {
            return 0;
        }
        printf("%d\n", logn(n));
    }
}
