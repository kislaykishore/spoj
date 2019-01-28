#include<cstdio>
#include<cstring>
struct Node {
    int parent;
    int rank;
};
void unin(Node* disjointSet, int a1, int b1) {
    Node* a = disjointSet + a1;
    Node* b = disjointSet + b1;
    if(disjointSet[a1].rank > disjointSet[b1].rank) {
        b->parent = a1;
    } else if(disjointSet[a1].rank < disjointSet[b1].rank) {
        a->parent = b1;
    } else {
        b->parent = a1;
        disjointSet[a1].rank++;
    }
}
int find(Node* disjointSet, int a) {
    Node* n = disjointSet + a;
    if(n->parent != -1) {
        n->parent = find(disjointSet, n->parent);
        return n->parent;
    } else {
        return a;
    }
}

int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n;
        scanf("%d", &n);
        int* degree = new int[n + 1];
        Node *disjointSet = new Node[n+1];
        for(int i=1;i<=n;++i) {
            disjointSet[i].parent = -1;
            disjointSet[i].rank = 0;
        }
        memset(degree, 0, sizeof(int) * (n+1));
        int k;
        scanf("%d", &k);
        for(int i=0;i<k;++i) {
            int s, d, m;
            scanf("%d %d %d", &s, &d, &m);
            if(s == d) {
                continue;
            }
            degree[s] += m;
            degree[d] += m;
            unin(disjointSet, s, d);
        }
        // check if graph is connected
        int st = find(disjointSet, 1);
        bool connected = true;
        for(int i=1;i<=n;++i) {
            if(find(disjointSet, i) != st) {
                connected = false;
                break;
            }
        }
        delete [] disjointSet;
        if(!connected) {
            printf("NO\n");
            delete [] degree;
            continue;
        }
        int oddNode = 0;
        int oddCount = 0;
        
        for(int i=1;i<=n;++i) {
            if(degree[i] & 1) {
                oddCount++;
                if(oddNode == 0) {
                    oddNode = i;
                }
            }
        }
        if(oddCount == 0) {
            printf("YES 1\n");
        } else if(oddCount == 2) {
            printf("YES %d\n", oddNode);
        } else {
            printf("NO\n");
        }
        delete [] degree;
    }
}
