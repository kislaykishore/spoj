#include<cstdio>
#define MODULO 1000007
int main() {
    int tests;
    scanf("%d", &tests);
    int *cache = new int[1000001];
    cache[1] = 2;
    long long cardsCount = 2;
    for(int i=2;i<=1000000;++i) {
        // level i will have i * 2 cards + i-1 cards
        cardsCount += i*2 + i -1;
        if(cardsCount > MODULO) {
            cardsCount %= MODULO;
        }
        cache[i] = cardsCount;
    }
    while(tests--) {
        int level = 1;
        int n;
        scanf("%d", &n);
        printf("%d\n", cache[n]);
    }
    delete [] cache;
}
