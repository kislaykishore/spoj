#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define MAX_VAL 10000001
long long sieve[MAX_VAL];

int main() {
    int tests = 0;
    scanf("%d", &tests);
    // generate prime numbers upto 3200
    int maxVal = sqrt(MAX_VAL);
    memset(sieve, 0, sizeof(sieve));
    sieve[0] = sieve[1] = 1;

    for(int i=2;i<maxVal;++i) {
        if(sieve[i]) {
            continue;
        }
        for(int j=i;;++j) {
            int prod = i*j;
            if(prod >= MAX_VAL || prod <= 0) {
                break;
            }
            if(!sieve[prod]) {
                sieve[prod] = i;
            }
        }
    }
    sieve[0] = sieve[1] = 0;
    for(int i=2;i<MAX_VAL;++i) {
        sieve[i] = sieve[i-1] + (sieve[i]?sieve[i]:i);
    }
    while(tests--) {
        int num;
        scanf("%d", &num);
        printf("%lld\n", sieve[num]);
    }
}
