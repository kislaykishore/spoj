#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node {
    char str[40];
    bool operator < (const Node& rhs) const {
        return strcmp(str, rhs.str) < 0;
    }

    bool operator == (const Node& rhs) const {
        return strcmp(str, rhs.str) == 0;
    }
};
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int num;
        scanf("%d", &num);
        Node* node = new Node[num];
        for(int i=0;i<num;++i) {
            scanf(" %[^\n]", node[i].str);
        }
        sort(node, node+ num);
        Node& tmp = node[0];
        int count = 1;
        for(int i=1;i<num;++i) {
            Node& nextVal = node[i];
            if(nextVal == tmp) {
                count++;
            } else {
                printf("%s%d\n", tmp.str, count);
                tmp = nextVal;
                count = 1;
            }
        }
        printf("%s%d\n", tmp.str, count);
        delete [] node;
    }
}
