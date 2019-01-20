#include<cstdio>
#include<map>
using namespace std;
unsigned long long computeWays(int *array, int n);
unsigned long long computeWays(int *array, int n, int index, int bitmask, map<int, unsigned long long>& mp);
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n;
        scanf("%d", &n);
        int *array = new int[n];
        for(int i=0;i<n;++i) {
            int x = 0;
            for(int j=0;j<n;++j) {
                int t;
                scanf("%d", &t);
                x = (x << 1) | t;
            }
            array[i] = x;
        }

        unsigned long long val = computeWays(array, n);
        delete [] array;
        printf("%llu\n", val);

    }
}

unsigned long long computeWays(int *array, int n) {
    map<int, unsigned long long>mp;
    int bitmask = 0;
    return computeWays(array, n, 0, bitmask, mp);
}

unsigned long long computeWays(int *array, int n, int index, int bitmask, map<int, unsigned long long>& mp) {
    if(index == n) {
        return 1;
    }
    if(mp.find(bitmask) != mp.end()) {
        return mp[bitmask];
    }
    int availableSubs = array[index] & (~bitmask);
    long long sum = 0;
    for(int i=0;i<n && availableSubs;++i) {
        if(availableSubs & 1) {
            sum += computeWays(array, n, index + 1, bitmask | (1 << i), mp);
        }
        availableSubs >>= 1;
    }
    mp[bitmask] = sum;
    return sum;
}
