#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
    int tests;
    scanf("%d", &tests);
    int array[1000001];
    while(tests--) {
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;++i) {
            scanf("%d", array + i);
        }
        bool val = next_permutation(array, array + n);
        if(val) {
            for(int i=0;i<n;++i) {
                printf("%d", array[i]);
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }
}
