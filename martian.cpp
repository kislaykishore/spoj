#include<cstdio>
#include<utility>
int compute(int cells[501][501][2], int m, int n, int* northArray, int* westArray, int row) {
    // for north, if the value is calculated, return it
    if(r == m) {
        return 0;
    }
    // case 1: corner is pointing north
    // then all the columns of that row
    // will be pointing north
    // and till some point, the first column
    // elements will be pointing north
    // and then west

    // the value in such a case will be the maximum
    // of all the cases

    int valNorth = 0;
    for(int i=0;i<m;++i) {
        valNorth += cells[row][i][1];
    }
    int valWest = 0;
    int incNorth = 0;
    int runningAmt = 0;
    int maxAmt = max(westArray[row+1], northArray[row+1]);
    
       
}
int main() {
    int cells[501][501][2];
    int northArray[501][501];
    int westArray[501][501];
    while(true) {
        int n, m;
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) {
            return 0;
        }
        memset(northArray, -1, sizeof(northArray));
        memset(westArray, -1, sizeof(westArray));
        for(int x=0;x<2;++x) {
            for(int i=1;i<=n;++i) {
                for(int j=1;j<=m;++j) {
                    scanf("%d", &cells[i][j][x]);
                }
            }
        }
    }
}
