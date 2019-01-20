#include<cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int *array = new int[n];
    for(int i=0;i<n;++i) {
        scanf("%d", array + i);
    }
    int k;
    scanf("%d", &k);
    int curMax = array[0];
    int maxIndex = 0;
    for(int i=1;i<k - 1;++i) {
        if(array[i] > curMax) {
            curMax = array[i];
            maxIndex = i;
        }
    }

    for(int i=k-1;i<n;++i) {
        int val = array[i];
        // check if previous max is in range

        int lIndex = i - (k - 1);
        if(maxIndex >= lIndex) {
            if(val > curMax) {
                curMax = val;
                maxIndex = i;
            }
        } else {
            curMax = array[lIndex];
            maxIndex = lIndex;
            for(int j=lIndex + 1;j<=i;++j) {
                if(array[j] > curMax) {
                    curMax = array[j];
                    maxIndex = j;
                }
            }
        }
        printf("%d ", curMax);
    }
    printf("\n");
}
