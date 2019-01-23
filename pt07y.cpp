#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
bool dfs(int curNode, bool* visited, set<int>* adjList, int n) {
    visited[curNode] = true;
    for(set<int>::iterator itr=adjList[curNode].begin();itr != adjList[curNode].end();++itr) {
        int targetNode = *itr;
        if(visited[targetNode]) {
            return false;
        }
        adjList[curNode].erase(targetNode);
        bool val = dfs(targetNode, visited, adjList, n);
        if(!val) {
            return false;
        }
    }
    return true;
}
bool dfs(set<int>* adjList, int n) {
    bool* visited = new bool[n];
    memset(visited, 0, sizeof(bool) * n);
    bool isTree = dfs(0, visited, adjList, n);
    for(int i=0;i<n && isTree;++i) {
        isTree = isTree && visited[i];
    }
    return isTree;
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    set<int>* adjList = new set<int>[n];
    if(m != (n-1)) {
        printf("NO\n");
        return 0;
    }
    for(int i=0;i<m;++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        if(adjList[u].find(v) != adjList[u].end()) {
            printf("NO\n");
            return 0;
        }
        adjList[u].insert(v);
    }

    // execute dfs
    bool isTree = dfs(adjList, n);
            
    printf("%s\n", isTree?"YES":"NO");
    delete [] adjList;
}
