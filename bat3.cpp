#include<cstdio>
using namespace std;

int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int *array = new int[n];
        for(int i=0;i<n;++i){
            scanf("%d", array + i);
        }
        int maxP = 0;
        int numPoliceman = 0;
        int robVal = 0;
        for(int i=0;i<n - 1;++i) {
            numPoliceman += 1;
            if(numPoliceman > maxP) {
                maxP = numPoliceman;
            }
            if(i == m) {
                robVal = numPoliceman;
            }
            if(array[i] <= array[i + 1]) {
                numPoliceman = 0; 
            }
        }

        if((m + 1) < n && array[m + 1] >= array[m]) {
            int sum = robVal;
            for(int i=m+1;i<n-1;++i) {
                sum += 1;
                if(sum > maxP) {
                    maxP = sum;
                }
                if(array[i] <= array[i + 1]) {
                    break;
                }
            }
        }
        printf("%d\n", maxP);

        

 
    }
}
