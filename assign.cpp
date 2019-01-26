#include<cstdio>
#include<map>
#include<list>
#include<set>
using namespace std;
unsigned long long computeWays(int *array, int n) {
    map<int, set<int>* >levelToMask;
    map<int, unsigned long long> waysMap;
    waysMap[0] = 1;
    set<int> lst;
    lst.insert(0);
    for(int i=0;i<n;++i) {
        // assigning the i-th student a subject
        // we need to get all the masks at i-1 level
        set<int>* masks;
        if(i == 0) {
            masks = &lst;
        } else {
            masks = levelToMask[i-1];
        }
        levelToMask[i] = new set<int>();
        for(set<int>::iterator itr=masks->begin();itr != masks->end();++itr) {
            for(int j=0;j<n;++j) {
                if((((*itr) & (1 << j)) == 0) && ((array[i] & (1 << j)) != 0)) {
                    int newMask = (*itr) | (1<<j);
                    levelToMask[i]->insert(newMask);
                    unsigned long long v = waysMap[*itr];
                    waysMap[newMask] += v;
                    v = waysMap[newMask];
                    v += 1;
                }
            }
        }
    }
    unsigned long long ways = waysMap[~(-1 << n)];
    for(map<int, set<int>* >::iterator itr = levelToMask.begin();itr != levelToMask.end();++itr) {
        delete itr->second;
    }
    return ways;
}
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n;
        scanf("%d", &n);
        int *array = new int[n];
        for(int i=0;i<n;++i) {
            int val = 0;
            for(int j=0;j<n;++j) {
                int t;
                scanf("%d", &t);
                val <<= 1;
                val |= t;
                array[i] = val;
            }
        }

        unsigned long long ways = computeWays(array, n);
        delete [] array;
        printf("%llu\n", ways);

    }
}
