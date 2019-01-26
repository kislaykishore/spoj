#include<cstdio>
int power(int a, int b) {
    if(b == 0) {
        return 1;
    }
    int val = power(a, b/2);
    if(b & 1) { 
        return val * val * a;
    } else {
        return val * val;
    }
        
}
int main() {
    while(true) {
        int num = 0;
        char str[5];
        scanf("%s", str);
        num += 10 *(str[0] - '0') + (str[1] - '0');
        int z = str[3] - '0';
        num = num * power(10, z);
        if(num == 0) {
            break;
        }
        int x = num;
        int val;
        while(x) {
            val = x;
            x &= (x - 1);
        }
        int answer = (num - val) * 2 + 1;
        printf("%d\n", answer);
    }
}
