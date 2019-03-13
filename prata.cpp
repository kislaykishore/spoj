#include<cstdio>
#include<cmath>
bool isValid(int time, int p, int* array, int l) {
    int sum = 0;
    for(int i=0;i<l;++i) {
        int rank = array[i];
        sum += (-1 + sqrt((rank + (8*time))/rank))/2;
        
    }
    return sum >= p; 
}
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int p;
        scanf("%d", &p);
        int l;
        scanf("%d", &l);
        int minRank = -1;
        int* array = new int[l];
        int maxRank = -1;
 
        for(int i=0;i< l;++i) {
            scanf("%d", array + i);
            if(array[i] > maxRank) {
                maxRank = array[i];
            }
        }
        
        int maxTime = ((p * (p+1))/ 2) * maxRank;
        int minTime = 0;
        // use binary search to figure out the min time
        while(minTime < maxTime) {
            int mid = (minTime + maxTime)/2;
            if(isValid(mid, p, array, l)) {
                maxTime = mid;
            } else {
                minTime = mid + 1;
            }
        }
        printf("%d\n", minTime);
        delete [] array;
    }
}
