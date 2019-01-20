#include<cstdio>
#include<utility>
#include<map>
using namespace std;
long long computeWays(int index, pair<int, int>* limits, int n, map<pair<int, int>, int>& mp, int m) {
    if(index == m - 1) {
        if(n <= limits[index].second && n >= limits[index].first) {
            return 1;
        } else {
            return 0;
        }
    }
    pair<int, int> pr;
    pr.first = index;
    pr.second = n;
    if(mp.find(pr) != mp.end()) {
        return mp[pr];
    }
    long long sum = 0;
    for(int i=limits[index].first;i<=limits[index].second;++i) {
        sum += computeWays(index + 1, limits, n - i, mp, m);
    }
    mp[pr] = sum;
    return sum;
}
long long computeWays(pair<int, int>* limits, int n, int m) {
    map<pair<int, int>, int> mp;
    return computeWays(0, limits, n, mp, m);
}
int main() {
    while(true) {
        int m, n;
        scanf("%d %d", &m, &n);
        if(m == 0 && n == 0) {
            return 0;
        }
        pair<int, int>* limits = new pair<int, int>[m];
        for(int i=0;i<m;++i) {
            int ai, bi;
            scanf("%d %d", &ai, &bi);
            limits[i].first = ai;
            limits[i].second = bi;
        }
        long long ways = computeWays(limits, n, m);
        printf("%lld\n", ways);
        delete [] limits;
    }
}
