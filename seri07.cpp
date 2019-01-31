#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    // generate primes
    int len = 350380;
    bool* array = new bool[len];
    memset(array, 0, sizeof(bool) * len);
    array[0] = array[1] = true;
    int sq = sqrt(len);
    for(int i=3;i <= sq;i+=2) {
        if(array[i]) {
            continue;
        }
        for(int j=i;;++j) {
            int prod = i * j;
            if(prod >= len) {
                break;
            }
            array[prod] = true;
        }
    }
    vector<int> primes;
    primes.reserve(30000);
    primes.push_back(2);
    for(int i=3;i<len;i += 2) {
        if(!array[i]) {
            primes.push_back(i);
        }
    }
    delete [] array;
    int test;
    scanf("%d", &test);
    while(test--) {
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;++i) {
            long long v1 = primes[3*i];
            v1 *= primes[3*i + 1];
            v1 += primes[3*i + 2];
            if(i != n-1) {
                printf("%lld ", v1);
            }
            else {
                printf("%lld\n", v1);
            }
        }
    }
}
