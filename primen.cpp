#include<cstdio>
#include<cstring>
#include<cmath>
int main() {
    bool primes[1001];
    memset(primes, 0, sizeof(primes));
    primes[0] = primes[1] = true;
    int val = sqrt(1001);
    for(int i=3;i<=val;++i) {
        if(primes[i] == 1) {
            continue;
        }
        for(int j=i;;j+=2) {
            int prod = i * j;
            if(prod < 1001) {
                primes[prod] = true;
            } else {
                break;
            }
        }
    }
    primes[1] = false;
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int x;
        scanf("%d", &x);
        if(x >= 1) {
            printf("1\n");
        }
        if(x >= 2) {
            printf("2\n");
        }
        for(int i=3;i<=x;i+=2) {
            if(!primes[i]) {
                printf("%d\n", i);
            }
        }
        printf("\n");
    }
}
