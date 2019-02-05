#include<cstdio>
#include<vector>
#include<cstring>
#include<set>
#include<cmath>
using namespace std;
int computeTotient(int n, vector<int>& primes) {
    if(n == 1) {
        return 1;
    }
    set<int> primeDivs;
    long long ntmp = n;
    for(int i=0;i < primes.size() && primes[i] <= ntmp;++i) {
        if(n % primes[i] == 0) {
            primeDivs.insert(primes[i]);
            while(ntmp % primes[i] == 0) {
                ntmp /= primes[i];
            }
        }
    }
    if(ntmp != 1) {
        primeDivs.insert(ntmp);
    }
    long long prod = n;
    for(set<int>::iterator itr=primeDivs.begin();itr != primeDivs.end();++itr) {
        prod *= (*itr - 1);
    }
    for(set<int>::iterator itr= primeDivs.begin();itr != primeDivs.end();++itr) {
        prod /= *itr;
    }
    return prod;
}
int main() {
    int test;
    scanf("%d", &test);
    // compute primes using sieve
    bool primeArray[1001];
    memset(primeArray, 0, sizeof(primeArray));
    primeArray[0] = primeArray[1] = true;
    int len = sizeof(primeArray)/sizeof(bool);
    int sqr = sqrt(len);
    for(int i=3;i<=sqr;i+=2) {
        if(primeArray[i]) {
            continue;
        }
        for(int j=i;j<=sqr;++j) {
            int prod = i*j;
            if(i*j < len) {
                primeArray[prod] = true;
            } else {
                break;
            }
        }
    }
    vector<int> primes;
    primes.push_back(2);
    for(int i=3;i<len;i+=2) {
        if(!primeArray[i]) {
            primes.push_back(i);
        }
    }

    while(test--) {
        int n;
        scanf("%d", &n);
        int val = computeTotient(n, primes);
        printf("%d\n", val);
    }
}
