#include<cstdio>
int main() {
    int contri[8];
    bool isInc[8];
    int sum = 0;
    for(int i=0;i<8;++i) {
        scanf("%d", contri + i);
        isInc[i] = true;
        sum += contri[i];
    }
}
