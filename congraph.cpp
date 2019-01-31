#include<cstdio>
#include<cstring>
struct Node {
    int parent;
    int rank;
};
int find(Node* array, int a); 
void unin(Node* array, int a, int b) {
    int p1 = find(array, a);
    int p2 = find(array, b);
    if(p1 == p2) {
        return;
    }
    Node* parent1 = array + p1;
    Node* parent2 = array + p2;
    if(parent1->rank > parent2->rank) {
        parent2->parent = p1;
    } else if(parent1->rank < parent2->rank) {
        parent1->parent = p2;
    } else {
        parent2->parent = p1;
        parent1->rank++;
    }
}

int find(Node* array, int a) {
    int parent = array[a].parent;
    if(parent == -1) {
        return a;
    } else {
        array[a].parent = find(array, parent);
        return array[a].parent;
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Node *array = new Node[n];
    for(int i=0;i<n;++i) {
        array[i].parent = -1;
        array[i].rank = 0;
    }
    while(m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        unin(array, a, b);
    }
    // find distinct parents
    bool* present = new bool[n];
    memset(present, 0, sizeof(bool) * n);
    for(int i=0;i<n;++i) {
        int val = find(array, i);
        present[val] = true;
    }
    delete [] array;
    int count = 0;
    for(int i=0;i<n;++i) {
        if(present[i]) { 
            count++;
        }
    }
    delete [] present;
    printf("%d\n", count - 1);
}
