#include<cstdio>
#define max(x, y) x>y?x:y
int computeMaxSum(int* array1, int idx1, int len1, int* array2, int idx2, int len2) {
    int sum1 = 0, sum2 = 0;
    int curSum = 0;
    while(idx1 < len1 && idx2 < len2) {
        if(array1[idx1] == array2[idx2]) {
            // we have reached one intersection point
            sum1 += array1[idx1];
            sum2 += array2[idx2];
            idx1++;
            idx2++;
            curSum += max(sum1, sum2);
            sum1 = sum2 = 0;
        } else if(array1[idx1] < array2[idx2]) {
            sum1 += array1[idx1];
            idx1++;
        } else {
            sum2 += array2[idx2];
            idx2++;
        }
    }
    while(idx1 < len1) {
        sum1 += array1[idx1];
        idx1++;
    }
    while(idx2 < len2) {
        sum2 += array2[idx2];
        idx2++;
    }
    curSum += max(sum1, sum2);
    return curSum;
        
}
int main() {
    while(true){
    int n1;
    scanf("%d", &n1);
    if(n1 == 0) {
        return 0;
    }
    int* array1 = new int[n1];
    for(int i=0;i<n1;++i) {
        scanf("%d", array1 + i);
    }
    int n2;
    scanf("%d", &n2);
    int* array2 = new int[n2];
    for(int i=0;i<n2;++i) {
        scanf("%d", array2 + i);
    }
    int ptr1=0, ptr2=0;
    int maxVal = computeMaxSum(array1, 0, n1, array2, 0, n2);
    delete [] array1;
    delete [] array2;
    // create dp array
    printf("%d\n", maxVal);
    }
}
