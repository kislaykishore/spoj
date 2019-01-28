#include<cstdio>
bool isDiffValid(int xCount, int yCount) {
    return (xCount == yCount || xCount == (yCount + 1));
}


int main() {
    char toe[3][3];
    int tests;
    scanf("%d\n", tests);
    char t;
    while(tests--) {
        int xCount, yCount;
        xCount = 0;
        yCount = 0;
        for(int i=0;i<3;++i) {
            for(int j=0;j<3;++j) {
                scanf("%c", &toe[i][j]);
                if(toe[i][j] == 'X') {
                    xCount++;
                } else if(toe[i][j] == 'O') {
                    yCount++;
                }
            }
            scanf("%c", &t);
        }
        if(isDiffValid(xCount, yCount)) {
            if(hasXWon(toe)) {
            }
        }
    }
}
