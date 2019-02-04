#include<cstdio>
int main() {
    long long num;
    scanf("%lld", &num);
    bool val = (num & (num-1)) == 0;
    printf("%s\n", val?"TAK":"NIE");
}
