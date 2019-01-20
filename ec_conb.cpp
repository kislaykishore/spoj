#include<cstdio>
bool isOdd(int n) {
    return n & 1;
}
int reverse(int n) {
    int x = n;
    int val = 0;
    while(x != 0) {
        val <<= 1;
        if(isOdd(x)) {
            val += 1;
        }
        x >>= 1; 
    }
    return val;
}
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int v;
        scanf("%d", &v);
        int rev = v;
        if(!isOdd(v)) {
            rev = reverse(v);
        }
        printf("%d\n", rev);
    }
    return 0;
}
