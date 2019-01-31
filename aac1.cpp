#include<cstdio>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n, m;
        scanf("%d %d", &n, &m);
        set<int>* adjList = new set<int>[n+1]; 
        bool* visited = new bool[n+1];
        memset(visited, 0, sizeof(bool) * (n+1));
        for(int i=0;i<m;++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            adjList[x].insert(y);
            adjList[y].insert(x);
        }
        queue<int> q;
        q.push(1);
        q.push(-1);
        int runningDist = 0;
        int dist = -1;
        while(!q.empty()) {
            int val = q.front();
            q.pop();
            if(val == -1) {
                runningDist++;
                if(!q.empty())
                    q.push(-1);
            }
            else if(!visited[val]) {
                visited[val] = true;
                if(val == n) {
                    dist = runningDist;
                    break;
                }
                for(set<int>::iterator itr=adjList[val].begin();itr != adjList[val].end();++itr) {
                    q.push(*itr);
                }
            }
        }
        delete [] adjList;
        printf("%d\n", dist);
    }
}
