#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;
struct Edge {
    int dist;
    int v1;
    int v2;
    bool operator < (const Edge& rhs) const {
        return dist > rhs.dist;
    }
};
struct Node {
    int parent;
    int rank;
};

// union find
int find(Node* array, int v) {
    if(array[v].parent == -1) {
        return v;
    }
    array[v].parent = find(array, array[v].parent);
}

void unin(Node* array, int n1, int n2) {
    int p1 = find(array, n1);
    int p2 = find(array, n2);
    if(p1 == p2) {
        return;
    }
    Node& val1 = array[p1];
    Node& val2 = array[p2];
    if(val1.rank > val2.rank) {
        val2.parent = p1;
    } else if(val1.rank < val2.rank) {
        val1.parent = p2;
    } else {
        val2.parent = p1;
        val1.rank++;
    }
}
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        char str[20];
        int n;
        scanf("%d", &n);
        priority_queue<Edge> pq;
        for(int i=0;i<n;++i) {
            // Read and ignore the name
            scanf("%s", str);
            int num;
            scanf("%d", &num);
            for(int j=0;j<num;++j) { 
                Edge edge;
                edge.v1 = i;
                scanf("%d %d", &edge.v2, &edge.dist);
                edge.v2--;
                pq.push(edge);
            }
        }
        Node* node = new Node[n];
        for(int i=0;i<n;++i) {
            node[i].parent = -1;
            node[i].rank = 0;
        }
        unsigned int totalDist = 0;
        while(!pq.empty()) {
            Edge top = pq.top();
            pq.pop();
            int v1 = top.v1;
            int v2 = top.v2;
            int p1 = find(node, v1);
            int p2 = find(node, v2);
            if(p1 != p2) {
                unin(node, p1, p2);
                totalDist += top.dist;
            }
        }
        printf("%u\n", totalDist);
        delete [] node;
    }
}
