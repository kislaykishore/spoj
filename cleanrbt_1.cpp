#include<cstdio>
#include<utility>
#include<map>
using namespace std;
const int MAX_VALUE = 10000000;
bool isDirty(pair<int, int>& robLocation, int mask, map<pair<int, int>, int>& dirtyMap) {
    printf("Roblocation: %d %d\n", robLocation.first, robLocation.second);
    if(dirtyMap.find(robLocation) != dirtyMap.end()) {
        int idx = dirtyMap[robLocation];
        return mask & (1<<idx) == 0;
    }
    return false;
}
int computeMinDist(char **array, pair<int, int> robLocation, int r, int c, int mask, map<pair<int, int>, int>& dirtyMap, map<pair<pair<int, int>, int>, int>& mp) {
    if(robLocation.first < 0 || robLocation.first >= r || robLocation.second < 0 || robLocation.second >= c || array[robLocation.first][robLocation.second] == 'x') {
        return MAX_VALUE;
    }
    pair<pair<int, int>, int> coordinates;
    coordinates.first = robLocation;
    coordinates.second = mask;
    if(mp.find(coordinates) != mp.end()) {
        return mp[coordinates];
    }
    int dirtyCount = dirtyMap.size();
    // if the current tile is dirty
    // figure out the number
    if(isDirty(robLocation, mask, dirtyMap)) {
        mask = mask | (1 << dirtyMap[robLocation]);
    }

    if(mask + 1 == (1 << dirtyCount)) {
        return 0;
    }

    mp[coordinates] = MAX_VALUE;
    // check if we have already had the configuration before
    pair<int, int> up;
    up.first = robLocation.first - 1;
    up.second = robLocation.second;
    int dist = computeMinDist(array, up, r, c, mask, dirtyMap, mp);
   
    pair<int, int> down;
    down.first = robLocation.first + 1;
    down.second = robLocation.second;
    int val = computeMinDist(array, down, r, c, mask, dirtyMap, mp);
    dist = val < dist?val:dist;

    pair<int, int> left;
    left.first = robLocation.first;
    left.second = robLocation.second - 1;
    val = computeMinDist(array, left, r, c, mask, dirtyMap, mp);
    dist = val <dist?val:dist;

    pair<int, int> right;
    right.first = robLocation.first;
    right.second = robLocation.second + 1;
    val = computeMinDist(array, right, r, c, mask, dirtyMap, mp);
    dist = val < dist?val:dist;
    int retDist = dist + 1;
    mp[coordinates] = retDist;
    return retDist;
}
int main() {
    while(true) {
        int w,h;
        pair<int, int> rob;
        char c;
        scanf("%d %d", &w, &h);
        scanf("%c", &c);
        char **array = new char*[h];
        int dirtyCount = 0;
        map<pair<int, int>, int> dirtyMap;
        for(int i=0;i<h;++i) {
            array[i] = new char[w];
            for(int j=0;j<w;++j) {
                scanf("%c", &array[i][j]);
                if(array[i][j] == 'o') {
                    rob.first = i;
                    rob.second = j;
                    array[i][j] = '.';
                } else if(array[i][j] == '*') {
                    pair<int, int> pr;
                    pr.first = i;
                    pr.second = j;
                    dirtyMap[pr] = dirtyCount;
                    dirtyCount++;
                }
            }
            scanf("%c", &c);
        }
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
