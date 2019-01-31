#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
bool dfs(set<int>* adjList, int node, int* visited, int color) {
    if(visited[node]  != -1) {
        if(visited[node] != color) {
            return false;
        } else {
            return true;
        }
    }
    visited[node] = color;
    int nextColor = color == 1?2:1;
    for(set<int>::iterator itr=adjList[node].begin();itr != adjList[node].end();++itr) {
        bool val = dfs(adjList, *itr, visited, nextColor);
        if(!val) {
            return false;
        }
    }
    return true;

}
bool dfs(set<int>* adjList, int* visited, int bugsNum) {
    for(int minIndex=1;minIndex<=bugsNum;++minIndex) {
        if(visited[minIndex] == -1) {
            // start with color 1
            bool val = dfs(adjList, minIndex, visited, 1);
            if(!val) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int test;
    scanf("%d", &test);
    for(int k=1;k<=test;++k) {
        int bugsNum, interactions;
        scanf("%d %d", &bugsNum, &interactions);
        set<int>* adjList = new set<int>[bugsNum + 1];
        int* visited = new int[bugsNum + 1];
        memset(visited, -1, sizeof(int) * (bugsNum + 1));
        for(int i=0;i<interactions;++i) {
            int bug1, bug2;
            scanf("%d %d", &bug1, &bug2);
            adjList[bug1].insert(bug2);
            adjList[bug2].insert(bug1);
        }
        // we need to perform dfs
        bool val = dfs(adjList, visited, bugsNum);
        printf("Scenario #%d:\n", k);
        if(val) {
            printf("No suspicious bugs found!\n");
        } else {
            printf("Suspicious bugs found!\n");
        }
    }
}
