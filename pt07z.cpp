#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
int dfs(set<int>* adjList, int v, int n, int& maxLen, bool* visited) {
    visited[v] = true;
    int mValue1 = 0;
    int mValue2 = 0;
    for(set<int>::iterator itr=adjList[v].begin();itr != adjList[v].end();++itr) {
        if(visited[*itr]) {
            continue;
        }
        int depth = dfs(adjList, *itr, n, maxLen, visited);
        depth++;
        if(depth > mValue1) {
            mValue2 = mValue1;
            mValue1 = depth;
        } else if(depth > mValue2) {
            mValue2 = depth;
        }
    }
    int c = mValue1 + mValue2;
    if(c > maxLen) {
        maxLen = c;
    }
    int ret = mValue1;
    if(maxLen < ret) {
        maxLen = ret;
    }
    return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    set<int>* adjList = new set<int>[n];
    for(int i=0;i<n-1;++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        adjList[u].insert(v);
        adjList[v].insert(u); 
    }
    int maxLen = 0;
    bool* visited = new bool[n];
    memset(visited, 0, sizeof(bool) * n);
    dfs(adjList, 0, n, maxLen, visited);
    delete [] adjList;
    delete [] visited;
    printf("%d\n", maxLen);
}
