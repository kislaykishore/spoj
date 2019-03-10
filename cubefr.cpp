#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
#define MAX_VAL 1000002
bool sieve[MAX_VAL];
int find(vector<int>& v, int num) {
    int lIndex = 0;
    int rIndex = v.size() - 1;
    while(lIndex < rIndex - 1) {
        if(v[rIndex] == num) {
            return rIndex;
        } else if(v[lIndex] == num) {
            return lIndex;
        } 
        int mid = (lIndex + rIndex)/2;
        if(v[mid] > num) {
            rIndex = mid;
        } else if(v[mid] < num) {
            lIndex = mid;
        } else {
            return mid;
        }
    }
    return lIndex;
}
int main() {
    memset(sieve, 0, sizeof(sieve));
    vector<int> cubers;
    cubers.reserve(100);
    for(int i=2;;++i) {
        int prod = i*i*i;
        if(prod >= MAX_VAL) { 
            break;
        }
        cubers.push_back(prod);
    }
    for(int i=0;i<cubers.size();++i) {
        int val = cubers[i];
        for(int j=1;;++j) {
            int prod = val * j;
            if(prod >= MAX_VAL) {
                break;
            }
            sieve[prod] = true;
        }
    }
    vector<int> v;
    v.reserve(168092);
    v.push_back(0);
    
    for(int i=8;i<MAX_VAL;++i) {
        if(sieve[i]) {
            v.push_back(i);
        }
    }
    int tests;
    scanf("%d", &tests);
    for(int i=1;i <= tests;++i) {
        int num;
        scanf("%d", &num);
        int idx = find(v, num);
        if(num == v[idx]) {
            printf("Case %d: Not Cube Free\n", i);
        } else {
            printf("Case %d: %d\n", i, num - idx);
        }
    }
}
