#include<cstdio>
#include<cstring>
int array[1025][1025];
int rowBit[1025][1025];
void adjust(int x, int y, int delta, int n) {
    int t = y;
    for(;x <=n;x += x & (-x)) {
        for(y = t;y <= n;y += y &(-y)) {
            rowBit[x][y] += delta;
        }
    }
}

int getSum(int x, int y) {
    int sum = 0;
    int t = y;
    for(;x > 0;x -= x & (-x)) {
        for(y = t;y>0;y -= y & (-y)) {
            sum += rowBit[x][y];
        }
    }
    return sum;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        char operation[8];
        memset(array, 0, sizeof(array));
        memset(rowBit, 0, sizeof(rowBit));
        
        while(true) {
            scanf("%s", operation);
            if(operation[0] == 'E') {
                break;
            } else if(operation[1] == 'E') {
                int r, c, v;
                scanf("%d %d %d", &r, &c, &v);
                r++, c++;
                int delta = v - array[r][c];
                array[r][c] = v;
                adjust(r, c, delta, n);
            } else {
                // operation must be sum
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++, y1++, x2++, y2++;
                int sum = 0;
                // compute sum
                int s1 = getSum(x2, y2);
                int s2 = getSum(x2, y1 - 1);
                int s3 = getSum(x1-1, y2);
                int s4 = getSum(x1-1, y1 - 1);
                printf("%d\n", s1 - s2 -s3 + s4);
            }
        }
    }
}
