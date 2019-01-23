#include<cstdio>
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%s wins.\n", y == 0?"Airborne":"Pagfloyd");
    }
}
