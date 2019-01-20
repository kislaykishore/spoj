#include<cstdio>
int main() {
    int test;
    int array[12] = {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};
    scanf("%d", &test);
    while(test--) {
        int val;
        scanf("%d", &val);
        int count = 0;
        for(int i=0;i<12;++i) {
            count += val / array[i];
        }
        printf("%d\n", count);
    }
}
