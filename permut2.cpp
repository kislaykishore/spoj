#include<cstdio>
int main() {
    while(true) {
        int n;
        scanf("%d", &n);
        if(n == 0) {
            return 0;
        }
        int *array = new int[n];
        for(int i=0;i<n;++i) {
            scanf("%d", array + i); 
        }
        bool isValid = true;
        for(int i=0;i<n && isValid;++i) {
            if(array[array[i] - 1] != (i+1)) {
                isValid = false;
            }
        }
        delete [] array;
        printf("%s\n", isValid?"ambiguous":"not ambiguous");
    }
}
