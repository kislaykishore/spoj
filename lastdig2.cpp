#include<cstdio>
int main() {
int test;
scanf("%d", &test);
while(test--) {
int a, b;
scanf("%d %d", &a, &b);
if(a == 0) {
printf("0\n");
continue;
}
int pow[10];
int val = 1;
for(int i=0;i<10;++i) {
pow[i] = val;
val *= a;
val %= 10;
}
int period = -1;
int firstIndex = -1;
for(int i=1;i<10 && period == -1;++i) {
for(int j=0;j<i && period == -1;++j) {
if(pow[i]==pow[j]) {
period=i-j;
firstIndex = j;
}
}
}
        if(b < firstIndex) {
            printf("%d\n", pow[b]);
        } else {
            int x = (b - firstIndex) % period;
            printf("%d\n", pow[firstIndex + x]);
        }
    }
}
