#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int visit(int** array, int r, int c, int n, int m) {
    if(r >= n || c >= m || r < 0 || c < 0) {
        return 0;
    }
    if(array[r][c] == 0){
        return 0;
    }
    array[r][c] = 0;
    int sum = visit(array, r+1, c, n, m);
    sum += visit(array, r-1, c, n, m);
    sum += visit(array, r, c-1, n, m);
    sum += visit(array, r, c + 1, n, m);
    return sum + 1;
}
int main() {
    while(1) {
        int n, m;
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) {
            return 0;
        } 
        int** array = new int*[n];
        for(int i=0;i<n;++i) {
            array[i] = new int[m];
            for(int j=0;j<m;++j) {
                scanf("%d", array[i] + j);
            }
        }
        map<int, int>mp;
        int count = 0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(array[i][j]) {
                    count++;
                    int size = visit(array, i, j, n, m);
                    if(mp.find(size) == mp.end()) {
                        mp[size] = 1;
                    } else {
                        mp[size] += 1;
                    }
                }
            }
        }
        vector<int> sizes;
        for(map<int, int>::iterator itr=mp.begin();itr != mp.end();++itr) {
            sizes.push_back(itr->first);
        }
        sort(sizes.begin(), sizes.end());
        printf("%d\n", count);
        for(int i=0;i<sizes.size();++i) {
            printf("%d %d\n", sizes[i], mp[sizes[i]]);
        }
        for(int i=0;i<n;++i) {
            delete [] array[i];
        }
        delete [] array;
    }
}
