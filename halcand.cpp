#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int* array = new int[n];
        for(int i=0;i<n;++i) {
            scanf("%d", array + i);
        }
        sort(array, array + n);

        int index = 0;
        bool cont = true;
        int sum = 0;
        while(cont && index < n) {
            if(array[index] == 0) {
                index++;
                continue;
            }
            int val = array[index];
            array[index] = 0;
            for(int i=index+1;i - index < k;++i) {
                if(i == n) {
                    cont = false;
                    break;
                }
                array[i] -= val;
            }
            if(cont) { 
                sum += val;
            }

        }
        delete [] array;
        printf("%d\n", sum);
    }
}
