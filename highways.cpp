#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

// dijkstra
struct Node {
    int vertex;
    int dist;
    bool isVisited;
    bool operator < (const Node& rhs) const {
        return dist > rhs.dist;
    }
};

struct Edge {
    int targetVertex;
    int dist;
};


int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n, m, s, e;
        scanf("%d %d %d %d", &n, &m, &s, &e);
        s--, e--;
        vector<Edge>* adjList = new vector<Edge>[n];
        for(int i=0;i<m;++i) {
            int v1, v2, dist;
            scanf("%d %d %d", &v1, &v2, &dist);
            v1--, v2--;
            Edge edge;
            edge.targetVertex = v2;
            edge.dist = dist;
            adjList[v1].push_back(edge);
            edge.targetVertex = v1;
            adjList[v2].push_back(edge);
        }

        // start vertex - s
        Node* status = new Node[n];
        for(int i=0;i<n;++i) {
            Node& node = status[i];
            node.vertex = i;
            node.dist = -1;
            node.isVisited = false;
        }
        priority_queue<Node> pq;
        Node startNode;
        startNode.vertex = s;
        startNode.dist = 0;
        status[s].dist = 0;
        pq.push(startNode);
        while(!pq.empty()) {
            Node node = pq.top();
            int vertex = node.vertex;
            pq.pop();
            if(status[vertex].isVisited) {
                continue;
            }
            status[vertex].isVisited = true;
            if(vertex == e) {
                break;
            }
            for(vector<Edge>::iterator itr=adjList[vertex].begin();itr != adjList[vertex].end();++itr) {
                int targetVertex = itr->targetVertex;
                int d = itr->dist;
                if(!status[targetVertex].isVisited && (status[targetVertex].dist == -1 || status[targetVertex].dist > status[vertex].dist + d)) {
                    status[targetVertex].dist = status[targetVertex].dist == -1?0:status[targetVertex].dist;
                    status[targetVertex].dist = status[vertex].dist + d;
                    Node next;
                    next.vertex = targetVertex;
                    next.dist = status[targetVertex].dist;
                    pq.push(next);
                }
            }
        }
        if(!status[e].isVisited) {
            printf("NONE\n");
        } else {
            printf("%d\n", status[e].dist);
        }
        delete [] status;
        delete [] adjList;
    }
}
