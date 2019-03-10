#include<cstdio>
#include<cstring>

#define max(x, y) ((x) > (y)?(x):(y))

int abs(int x) {
    return x < 0?-x:x;
}
struct Node {
    int lengthTop;
    int breadthTop;
};

Node computeMaxLine(int* lengths, int* breadths, int idx) {
    Node node;
    if(idx == 0) {
        // max length = top value
        node.lengthTop = lengths[idx];
        node.breadthTop = breadths[idx];
    } else {
        Node val = computeMaxLine(lengths, breadths, idx - 1); 
        // Previous lengthTop configuration
        // Current lengthTop configuration
        // height to add
        int p1 = abs(breadths[idx-1] - breadths[idx]) + lengths[idx] + val.lengthTop;
        int p2 = abs(lengths[idx-1] - breadths[idx]) + lengths[idx] + val.breadthTop;
        // Current breadthTop configuration
        int p3 = abs(breadths[idx-1] - lengths[idx]) + breadths[idx] + val.lengthTop;
        int p4 = abs(lengths[idx-1] - lengths[idx]) + breadths[idx] + val.breadthTop;

        node.lengthTop = max(p1, p2);
        node.breadthTop = max(p3, p4);
    }
    return node;
}

int main() {
    int n;
    scanf("%d", &n);
    int* lengths = new int[n];
    int* breadths = new int[n];
    for(int i=0;i<n;++i) {
        scanf("%d %d", lengths + i, breadths + i);
    }

    Node node = computeMaxLine(lengths, breadths, n - 1);
    printf("%d\n", max(node.lengthTop, node.breadthTop));
    delete [] lengths;
    delete [] breadths;
}
