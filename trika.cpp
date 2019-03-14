#include<cstdio>
int min(int x, int y) {
    return x < y? x : y;
}
int computeDist(int** power, int x, int y, int n, int m, int initX, int initY, int** dist) {
    if(x < initX || y < initY) {
        return -1;
    }
    if(x == initX && y == initY) {
        return 0;
    }
    if(dist[x][y] != -1) {
        return dist[x][y];
    }
    int valDist = computeDist(power, x-1, y, n, m, initX, initY, dist);
    int minDist2 = computeDist(power, x, y -1, n, m, initX, initY, dist);
    if(valDist == -1) {
        valDist = minDist2;
    } else if(minDist2 == -1) {
        valDist = valDist;
    } else {
        valDist = min(valDist, minDist2);
    }
    valDist += power[x][y];
    dist[x][y] = valDist;
    return valDist;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    int** power = new int*[n];
    int** dist = new int*[n];
    for(int i=0;i<n;++i) {
        power[i] = new int[m];
        dist[i] = new int[m];
        for(int j=0;j<m;++j) {
            scanf("%d", &power[i][j]);
            dist[i][j] = -1;
        }
    }
    // objective: reach p[n-1][m-1]
    int hisPower = power[x][y];
    power[x][y] = 0;
    int distVal = computeDist(power, n-1, m-1, n, m, x, y, dist);
    if(distVal <= hisPower) {
        printf("Y %d\n", hisPower - distVal);
    } else {
        printf("N\n");
    }
    for(int i=0;i<n;++i) {
        delete [] dist[i];
        delete [] power[i];
    }
    delete [] dist;
    delete [] power;
}
