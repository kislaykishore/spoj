#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
struct Node {
    int vertex;
    int dist;
    bool operator<(const Node& rhs)const {
        return vertex < rhs.vertex;
    }
};

void updateMax(int& max1, int& max2, int val) {
    if(val >= max1) {
        max2 = max1;
        max1 = val;
    } else if(val > max2) {
        max2 = val;
    }
}
int maxLen(set<Node>* nodes, int idx, bool* visited, int n, int& maxVal) {
    visited[idx] = true;
    int max1 = 0, max2 = 0;
    for(set<Node>::iterator itr=nodes[idx].begin();itr != nodes[idx].end(); ++itr) {
        if(!visited[itr->vertex]) {
            int val = maxLen(nodes, itr->vertex, visited, n, maxVal) + itr->dist;
            updateMax(max1, max2, val);
        }
    }
    int sum = max1 + max2;
    if(sum > maxVal) {
        maxVal = sum;
    }
    return max1;
}

int maxLen(set<Node>* nodes, int n) {
    bool* visited = new bool[n];
    memset(visited, 0, sizeof(bool) * n);
    int maxVal = 0;
    for(int i=0;i<n;++i) {
        if(!visited[i]) {
            maxLen(nodes, i, visited, n, maxVal);
        }
    }
    delete [] visited;
    return maxVal;
}

int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int n;
        scanf("%d", &n);
        set<Node>* nodes = new set<Node>[n];
        for(int i=0;i<n-1;++i) {
            int v1, v2, dist;
            scanf("%d %d %d", &v1, &v2, &dist);
            v1--, v2--;
            Node node1;
            node1.vertex = v2;
            node1.dist = dist;
            nodes[v1].insert(node1);
            node1.vertex = v1;
            nodes[v2].insert(node1);
        }

        int len = maxLen(nodes, n);
        printf("%d\n", len);
        delete [] nodes; 
    }
}
