#include<cstdio>
#include<algorithm>
using namespace std;
int findLocation(int* lengths, int sum, int lIndex, int rIndex) {
    if(lIndex == rIndex) {
        if(lengths[lIndex] > sum) {
            return lIndex;
        } else {
            return lIndex + 1;
        }
    }
    int mid = (lIndex + rIndex)/2;
    if(lengths[mid] <= sum) {
        return findLocation(lengths, sum, mid + 1, rIndex);
    } else {
        return findLocation(lengths, sum, lIndex, mid);
    }
    
}
int main() {
    int lengths[2000];
    while(true) {
        int n;
        scanf("%d", &n);
        if(n == 0) {
            return 0;
        }
        for(int i=0;i<n;++i) {
            scanf("%d", lengths + i);
        }
        sort(lengths, lengths + n);

        int ways = 0;
        for(int i=0;i<n-2;++i) {
            for(int j=i+1;j<n-1;++j) {
                int cLoc = findLocation(lengths, lengths[i] + lengths[j], j+1, n-1);
                ways += n - cLoc;
            }
        }
        printf("%d\n", ways);
    }
}
