#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int k, n;
        scanf("%d %d", &n, &k);
        int* heights = new int[n];
        for(int i=0;i<n;++i) {
            scanf("%d", heights + i);
        }
        sort(heights, heights + n);
        int minDist = -1;
        int maxIdx = n-k;
        for(int i=0;i<=maxIdx;++i) {
            int dist = heights[i+k-1] - heights[i];
            if(minDist == -1 || dist < minDist) {
                minDist = dist;
            }
        }
        delete [] heights;
        printf("%d\n", minDist);
    }

}
