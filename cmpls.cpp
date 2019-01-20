#include<cstdio>
using namespace std;
int main() {

    int test;
    scanf("%d", &test);
    while(test--) {
        int s, c;
        scanf("%d %d", &s, &c);
        int **array = new int*[s+c];
        for(int i=0;i<s+c;++i) {
            array[i] = new int[s+1];
        }

        for(int i=0;i<s;++i) {
            scanf("%d", array[i]);
        }
        // apply method of differences

        bool found = false;
        int index = 0;
        int diff = 0;
        for(int i=0;i<=s && !found;++i) {
            index = i;
            found = true;
            int firstVal = array[0][i];
            diff = firstVal;
            for(int j=1;j < s-i;++j) {
                if(array[j][i] != firstVal) {
                    found = false;
                }
                array[j-1][i+1] = array[j][i] - array[j-1][i];
            }
        }
        for(int i=0;i<s+c;++i) {
            array[i][index] = diff;
        }

        // Now we have got the index. Let's use it to populate the remaining
        // items
        for(int i=index-1;i>=0;--i) {
            for(int j=s-i;j < s+c - i;++j) {
                array[j][i] = array[j-1][i] + array[j-1][i+1];
            }
        }

        for(int i=s;i<s+c;++i) {
            if(i < s+c-1)
               printf("%d ", array[i][0]);
            else
               printf("%d\n", array[i][0]);
        }
    }
    
}
