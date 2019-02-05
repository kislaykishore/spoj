#include<cstdio>
#include<cstring>
int brk(int i) {
    if(i == 0) {
        return 0;
    } else {
        int l = i % 10;
        return (l*l) + brk(i/10);
    }
}
int isBreakable(int i, int* array) {
    if(array[i] != -1) {
        return array[i];
    } else {
        array[i] = -2;
        int val = isBreakable(brk(i), array);
        if(val == -2) {
            array[i] = val;
        } else {
            array[i] = val + 1;
        }
        return array[i];
    }
}
int main() {
    int array[811];
    memset(array, -1, sizeof(array));
    array[1] = 1;
    int n;
    scanf("%d", &n);
    int x = n;
    if(n >= 811) {
        x = brk(n);
    }
    int val = isBreakable(x, array);
    if(val == -2) {
        printf("-1\n");
    } else { 
        if(n >= 811) {
        printf("%d\n", val);
        } else {
            printf("%d\n", val -1);
        }
 
    }
}
