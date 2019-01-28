#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int array[100];
    memset(array, 0, sizeof(array));
    set<int>* adjList = new set<int>[n];
    for(int i=0;i<m;++i) {
        int t, k;
        scanf("%d %d", &t, &k);
        for(int j=0;j<k;++j) {
            int dep;
            scanf("%d", &dep);
            adjList[dep - 1].insert(t - 1);
            array[t-1]++;
        }
    }
    vector<int> output;
    bool found = false;
    for(int i=0;i<n;) {
        if(array[i] == 0){
            output.push_back(i);
            array[i] = -1;
            for(set<int>::iterator itr=adjList[i].begin();itr != adjList[i].end();++itr) {
                array[*itr]--;
            }
            i = 0;
        } else {
            i++;
        }
    }
    for(int i=0;i<output.size();++i) {
        if(i == output.size() - 1) {
            printf("%d\n", output[i]+1);
        } else {
            printf("%d ", output[i] + 1);
        }
    }
}
