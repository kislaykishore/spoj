#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
long long getMaxCoins(long long val, map<long long, long long>& mp);
int main() {
    int n;
    while(cin >>n) {
        map<long long, long long> mp;
        // n is the number of coin
        long long val = getMaxCoins(n, mp);
        printf("%lld\n", val);
    }
}

long long getMaxCoins(long long val, map<long long, long long>& mp) {
    if(val < 12) {
        return val;
    }
    if(mp.find(val) != mp.end()) {
        return mp[val];
    }
    long long sum = 0;
    sum += getMaxCoins(val/2, mp);
    sum += getMaxCoins(val/3, mp);
    sum += getMaxCoins(val/4, mp);
    mp[val] = sum;
    return sum;
}
