#include<cstdio>
#include<queue>
using namespace std;
struct Pixel {
    bool color;
    int x;
    int y;
    int dist;
};
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int n, m;
        scanf("%d %d", &n, &m);
        queue<Pixel> q;
        Pixel** pixel = new Pixel*[n];
        char str[183];
        for(int i=0;i<n;++i) {
            pixel[i] = new Pixel[m];
            scanf("%s", str);
            for(int j=0;j<m;++j) { 
                pixel[i][j].color = str[j]=='0'?false:true;
                pixel[i][j].x = i;
                pixel[i][j].y = j;
                if(pixel[i][j].color) {
                    pixel[i][j].dist = 0;
                    q.push(pixel[i][j]);
                } else {
                    pixel[i][j].dist = -1;
                }
            }
        }
        while(!q.empty()) {
            Pixel p = q.front();
            q.pop();
            if(p.x > 0 && (pixel[p.x - 1][p.y].dist == -1 || pixel[p.x-1][p.y].dist > (p.dist + 1))) {
                pixel[p.x-1][p.y].dist = p.dist + 1;
                q.push(pixel[p.x -1][p.y]); 
            }
            if(p.x<(n-1) && (pixel[p.x+1][p.y].dist == -1 || pixel[p.x+1][p.y].dist > (p.dist+1))) {
                pixel[p.x+1][p.y].dist = p.dist + 1;
                q.push(pixel[p.x+1][p.y]);
            }
            if(p.y<(m-1) && (pixel[p.x][p.y+1].dist == -1 || pixel[p.x][p.y+1].dist > (p.dist+1))) {
                pixel[p.x][p.y+1].dist = p.dist+1;
                q.push(pixel[p.x][p.y+1]);
            }
            if(p.y>0 && (pixel[p.x][p.y-1].dist == -1 || pixel[p.x][p.y-1].dist > (p.dist+1))) {
                pixel[p.x][p.y-1].dist = p.dist+1;
                q.push(pixel[p.x][p.y-1]);
            }
        }
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                printf("%d", pixel[i][j].dist);
                if(j != (m-1)) {
                    printf(" ");
                }
            }
            printf("\n");
        }

        for(int i=0;i<n;++i) {
            delete [] pixel[i];
        }
        delete [] pixel;
    }
    
}
