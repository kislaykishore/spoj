#include<cstdio>
#include<utility>
#include<map>
#include<vector>
using namespace std;
const int MAX_VALUE = 10000000;

struct Location {
    int r;
    int c;
    int index;

    bool operator==(const Location& rhs) const {
        return (r == rhs.r) && (c == rhs.c);
    }

    bool operator<(const Location& rhs) const {
        return (r.index < rhs.index);
    }
}

void initialize(int **array, int r, int c, vector<pair<int, int> > dirtyLocations) {
    // we need to do bfs from all dirtyLocations
    for(
}

int main() {
    while(true) {
        int w,h;
        pair<int, int> rob;
        char c;
        scanf("%d %d", &w, &h);
        scanf("%c", &c);
        char **array = new char*[h];
        vector<Location>dirtyLocations;
        Location startLocation;
        for(int i=0;i<h;++i) {
            array[i] = new char[w];
            for(int j=0;j<w;++j) {
                scanf("%c", &array[i][j]);
                if(array[i][j] == 'o') {
                    .first = i;
                    rob.second = j;
                    dirtyLocations.push_back(rob);
                } else if(array[i][j] == '*') {
                    pair<int, int> pr;
                    pr.first = i;
                    pr.second = j;
                    dirtyLocations.push_back(pr);
                    dirtyMap[pr] = dirtyCount;
                }
            }
            scanf("%c", &c);
        }
        initialize(array, h, w, dirtyLocations);
        map<pair<pair<int, int>, int>, int> mp;
        int dist = computeMinDist(array, rob, h, w, 0, dirtyMap, mp);
        if(dist >= MAX_VALUE) {
            printf("-1\n");
        } else {
            printf("%d\n", dist);
        }

        for(int i=0;i<h;++i) {
            delete [] array[i];
        }
        delete [] array;
    }
}
