#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int getMaxLen(char **cArray, int r, int c);
int getMaxLength(char **cArray, int row, int col, int curRow, int curCol, int& maxLen);
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int r, c;
        char tmp;
        scanf("%d %d\n", &c, &r);
        char **cArray = new char*[r];
        for(int i=0;i<r;++i) {
            cArray[i] = new char[c];
            for(int j=0;j<c;++j) { 
                scanf("%c", cArray[i] + j);
            }
            scanf("%c", &tmp);
        }

        int maxLen = getMaxLen(cArray, r, c);
        printf("Maximum rope length is %d.\n", maxLen);
    }
}

int getMaxLen(char **cArray, int r, int c) {
    // First find out a free block
    int row = -1;
    int col = -1;
    for(int i=0;i<r && row == -1;++i) {
        for(int j=0;j<c && row == -1;++j) {
            if(cArray[i][j] == '.') {
                row = i;
                col = j;
            }
        }
    }

    if(row == -1) {
        return 0;
    }
    int maxLength=0;
    getMaxLength(cArray, r, c, row, col, maxLength);
    return maxLength;
}

int getMaxLength(char **cArray, int row, int col, int curRow, int curCol, int& maxLen) {
    cArray[curRow][curCol] = '#';
    int maxLength = 0;
    int length;
    // Go up
    int upIndex = curRow - 1;
    int lUp,lDown, lRight,lLeft;
    lUp = lDown = lRight = lLeft = 0;
    if(upIndex >= 0 && cArray[upIndex][curCol] != '#') {
        length = getMaxLength(cArray, row, col, upIndex, curCol, maxLen) + 1;
        lUp = length;
        maxLength = max(maxLength, length);
    }

    // Go down
    int downIndex = curRow + 1;
    if(downIndex < row && cArray[downIndex][curCol] != '#') {
        length = getMaxLength(cArray, row, col, downIndex, curCol, maxLen) + 1;
        lDown = length;
        maxLength = max(maxLength, length);
    }

    // Go left
    int leftIndex = curCol -1;
    if(leftIndex >= 0 && cArray[curRow][leftIndex] != '#') {
        length = getMaxLength(cArray, row, col, curRow, leftIndex, maxLen) + 1;
        lLeft = length;
        maxLength = max(maxLength, length);
    }

    // Go right
    int rightIndex = curCol + 1;
    if(rightIndex < col && cArray[curRow][rightIndex] != '#') {
        length = getMaxLength(cArray, row, col, curRow, rightIndex, maxLen) + 1;
        lRight = length;
        maxLength = max(maxLength, length);
    }
    vector<int> vect;
    vect.reserve(4);
    vect.push_back(lUp);
    vect.push_back(lDown);
    vect.push_back(lLeft);
    vect.push_back(lRight);
    sort(vect.begin(), vect.end());
    int tMax = vect[2] + vect[3];
    maxLen = max(tMax, maxLen);
    return maxLength;    
}
