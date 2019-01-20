#include<cstdio>
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        long long k;
        scanf("%lld", &k);
        int suffix;
        int rem = (k - 1) % 4;
        switch(rem) {
            case 0:
                suffix = 192;
                break;
            case 1:
                suffix = 442;
                break;
            case 2:
                suffix = 692;
                break;
            case 3:
                suffix = 942;
                break;
        }

        long long val = (k - 1) / 4;
        if(val != 0) {
            printf("%lld", val);
        }
        printf("%d\n", suffix);
    }
    return 0;
}
