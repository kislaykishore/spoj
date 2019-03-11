#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int ng, nm;
        scanf("%d %d", &ng, &nm);
        int* ngArray = new int[ng];
        int* nmArray = new int[nm];
        for(int i=0;i<ng;++i) {
            scanf("%d", ngArray + i);
        }
        for(int i=0;i<nm;++i) {
            scanf("%d", nmArray + i);
        }
        sort(ngArray, ngArray + ng);
        sort(nmArray, nmArray + nm);
        int p = 0, q = 0;
        while(p<ng && q < nm) {
            if(ngArray[p] < nmArray[q]) {
                p++;
            } else if(ngArray[p] >= nmArray[q]) {
                q++;
            }
        }
        if(p < ng) {
            printf("Godzilla\n");
        } else {
            printf("MechaGodzilla\n");
        }
        delete [] nmArray;
        delete [] ngArray;
    }
}
