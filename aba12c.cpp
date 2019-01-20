#include<cstdio>
#include<map>
#include<list>
using namespace std;
int compute(int n, int k, list<pair<int, int> >&weightPriceList, map<pair<int, int>, int>& mp);
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n, k;
        scanf("%d %d", &n, &k);
        list<pair<int, int> > weightPriceList;
        for(int i=0;i<k;++i) {
            int price;
            scanf("%d", &price);
            if(price != -1) {
                pair<int, int> pr;
                pr.first = i + 1;
                pr.second = price;
                weightPriceList.push_back(pr);
            }
        }
        map<pair<int, int>, int>mp;
        int minPrice = compute(n, k, weightPriceList, mp);
        printf("%d\n", minPrice);   
    }
}

int compute(int n, int k, list<pair<int, int> >&weightPriceList, map<pair<int, int>, int>& mp) {
    if(k == 0) {
        return 0;
    }
    if(k < 0) {
        return -1;
    }
    pair<int, int> key;
    key.first = n;
    key.second = k;
    if(mp.count(key)) {
        return mp[key];
    } else {
        // It needs further computation
        int minPrice = -1;
        for(list<pair<int, int> >::iterator itr=weightPriceList.begin();itr != weightPriceList.end();++itr) {
            int candidatePrice = compute(n-1, k - (*itr).first, weightPriceList, mp);
            if(candidatePrice != -1) {
                candidatePrice += (*itr).second;
                if(minPrice == -1 || minPrice > candidatePrice) {
                    minPrice = candidatePrice;
                }
            }
        }
        mp[key] = minPrice;
        return minPrice;
    }
}
