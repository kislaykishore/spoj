#include<cstdio>
#include<map>
#include<utility>
using namespace std;
struct Bag {
    int value;
    int weight;
};
int computeMaxVal(Bag* bags, int idx, int k, map<pair<int, int>, int>& mp) {
    if(idx < 0) {
        return 0;
    }
    if(k <= 0) {
        return 0;
    }
    pair<int, int> pr;
    pr.first = idx;
    pr.second = k;
    if(mp.find(pr) != mp.end()) {
        return mp[pr];
    }
    // either select idx
    int val1 = 0;
    if(bags[idx].weight <= k) {
        val1 = computeMaxVal(bags, idx-1, k-bags[idx].weight, mp) + bags[idx].value;
    }
    int val2 = computeMaxVal(bags, idx-1, k, mp);
    int maxVal = val1 > val2?val1:val2;
    mp[pr] = maxVal;
    return maxVal;
}
int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    Bag* bags = new Bag[n];
    for(int i=0;i<n;++i) {
        scanf("%d %d", &bags[i].value, &bags[i].weight);
    }
    map<pair<int, int>, int> mp;
    int maxValue = computeMaxVal(bags, n-1, k, mp);
    printf("%d\n", maxValue);
    delete [] bags;
}
