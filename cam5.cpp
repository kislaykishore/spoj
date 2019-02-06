#include<cstdio>
#include<cstring>
struct Node {
    int rank=0;
    int parent=-1;
};
int findParent(Node* array, int a) {
    if(array[a].parent != -1) {
        array[a].parent = findParent(array, array[a].parent);
        return array[a].parent;
    } else {
        return a;
    }
}
void unin(Node* array, int a, int b) {
    int p1 = findParent(array, a);
    int p2 = findParent(array, b);
    if(p1 == p2) {
        return;
    }
    if(array[p1].rank > array[p2].rank) {
        array[p2].parent = p1;
    } else if(array[p1].rank < array[p2].rank) {
        array[p1].parent = p2;
    } else {
        array[p2].parent = p1;
        array[p1].rank++;
    }
}
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n;
        scanf("%d", &n);
        Node *array = new Node[n+1];
        int e;
        scanf("%d", &e);
        for(int i=0;i<e;++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            unin(array, a+1, b+1);
        }
        int count =0;
        for(int i=1;i<n+1;++i) {
            if(array[i].parent == -1) {
                count++;
            }
        }
        delete [] array;
        printf("%d\n", count);
    }
}
