#include<cstdio>
#include<map>
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
        for(int j=0, x=1;j<n;++j,x<<=1) { 
            if((array[i] & (1 << j)) == 0) {
                continue;
            }
            for(set<int>::iterator itr=masks->begin();itr != masks->end();++itr) {
                if(((*itr) & x) == 0) {
                    int newMask = (*itr) | x;
                    levelToMask[i]->insert(newMask);
                    unsigned long long v = waysMap[*itr];
                    waysMap[newMask] += v;
                }
            }
        }
        printf("%lu\n", levelToMask[i]->size());
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
            }
            array[i] = val;
        }

        unsigned long long ways = computeWays(array, n);
        delete [] array;
        printf("%llu\n", ways);

    }
}
