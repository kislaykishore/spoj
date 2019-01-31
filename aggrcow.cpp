#include<cstdio>
#include<algorithm>
using namespace std;
bool isValidDist(int* stalls, int n, int minDist, int c, int minima) {
    if(minDist <= minima) {
        return true;
    }
    int prevLocation = stalls[0];
    c--;
    for(int i=1;i<n && c != 0;++i) {
        if((stalls[i] - prevLocation) >= minDist) {
            c--;
            prevLocation = stalls[i];
        }
    }
    return c == 0;
}
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n, c;
        scanf("%d %d", &n, &c);
        int* stalls = new int[n];
        for(int i=0;i<n;++i) {
            scanf("%d", &stalls[i]);
        }
        sort(stalls, stalls + n);
        // now we know that the minimum distance
        // between two cows should at most be
        // (maximum x - minimum x)/(n-1)
        // the minimum distance between two cows
        // should at least be 1
        int l = 1;
        int r = (stalls[n-1] - stalls[0])/(c-1);
        int minima = l;
        while(l < r) {
            int mid = (l+r)/2;
            if(isValidDist(stalls, n, mid, c, minima)) {
                if(isValidDist(stalls, n, mid+1, c, minima)) {
                    l = mid+1;
                } else {
                    r = mid;
                    l = mid;
                }
            } else {
                r = mid-1;
            }
        }
        delete [] stalls;
        printf("%d\n", l);
    }
}
