#include<cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int val = 0;
    while(n--) {
        int t;
        scanf("%d", &t);
        val ^= t;
    }
    printf("%d\n", val);
}
