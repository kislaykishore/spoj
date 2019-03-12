#include<cstdio>
#include<set>
#include<cstring>
using namespace std;

struct Node {
    int parent;
    int rank;
};

int find(Node* array, int idx) {
    if(array[idx].parent != -1) {
        array[idx].parent = find(array, array[idx].parent);
    } else {
        return idx;
    }
}

void unin(Node* array, int a, int b) {
    int p1 = find(array, a);
    int p2 = find(array, b);
    if(p1 == p2) {
        return;
    }
    Node& n1 = array[p1];
    Node& n2 = array[p2];
    if(n1.rank < n2.rank) {
        n1.parent = p2;
    } else if(n2.rank < n1.rank) {
        n2.parent = p1;
    } else {
        n2.parent = p1;
        n1.rank++;
    }
}
int abs(int a) {
    return a<0?-a:a;
}
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int n;
        scanf("%d", &n);
        // This array keeps track of the nodes involved
        int indegree[26];
        int outdegree[26];
        memset(indegree, 0, sizeof(indegree));
        memset(outdegree, 0, sizeof(outdegree));
        Node array[26];
        memset(array, -1, sizeof(array));
        set<int> chars;
        for(int i=0;i<n;++i) {
            char str[1001];
            scanf("%s", str);
            int lastIndex = strlen(str) - 1;
            outdegree[str[0] - 'a']++;
            indegree[str[lastIndex] - 'a']++;
            chars.insert(str[0] - 'a');
            chars.insert(str[lastIndex] - 'a');
            unin(array, str[0] - 'a', str[lastIndex] - 'a');
        }
        // For an Eulerian path to be present,  all indegrees and outdegrees should
        // be same except for two nodes where it should differ by 1
        bool found = true;
        int count = 0;
        for(int i=0;i<26 && found;++i) {
            if(indegree[i] != outdegree[i]) {
                if(abs(indegree[i] - outdegree[i]) != 1) {
                    found = false;
                }
                count++;
            }
       }
       int begin = -1;
       for(set<int>::iterator itr=chars.begin();found && itr != chars.end();++itr) {
           int tmpParent = find(array, *itr);
           if(begin == -1) {
               begin = tmpParent;
           } else if(begin != tmpParent) {
               found = false;
           }
       }
       printf("%s\n", !found || (count != 2 && count != 0)?"The door cannot be opened.":"Ordering is possible.");
        
    }
}
