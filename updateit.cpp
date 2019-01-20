#include<cstdio>
#include<cstring>
// using segment tree
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n, u;
        scanf("%d %d", &n, &u);
        int* diffArray = new int[n+1];
        memset(diffArray, '\0', sizeof(int) * (n+1));
        for(int i=0;i<u;++i) {
            int l,r,val;
            scanf("%d %d %d", &l, &r, &val);
            diffArray[l] += val;
            diffArray[r + 1] -= val;
        }

        // Compute the cumulative array sum
        int* array = new int[n];
        memset(array, '\0', sizeof(int) * n);
        array[0] = diffArray[0];
        for(int i=1;i<n;++i) {
            array[i] = diffArray[i] + array[i-1];
        }

        delete [] diffArray;

        int q;
        scanf("%d", &q);
        while(q--) {
            int idx;
            scanf("%d", &idx);
            printf("%d\n", array[idx]);
        }
        delete [] array;
    }
}
