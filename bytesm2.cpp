#include<cstdio>
using namespace std;
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int h, w;
        scanf("%d %d", &h, &w);
        int **array = new int*[h];
        for(int i=0;i<h;++i) {
            array[i] = new int[w];
            for(int j=0;j<w;j++) {
                scanf("%d", array[i] + j);
            }
        }

        for(int i=1;i<h;++i) {
            for(int j=0;j<w;++j) {
                int val = array[i-1][j];
                if(j - 1 >= 0 && array[i-1][j - 1] > val) {
                    val = array[i-1][j-1];
                }
                if(j+1 < w && array[i-1][j+1] > val) {
                    val = array[i-1][j+1];
                }
                array[i][j] += val;
            }
        }
        int max = 0;
        for(int j=0;j<w;++j) {
            if(array[h-1][j] > max) {
                max = array[h-1][j];
            }
        }
        for(int i=0;i<h;++i) {
            delete [] array[i];
        }
        delete [] array;
        printf("%d\n", max);
    }    
}
