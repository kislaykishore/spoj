#include<cstdio>
#include<set>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    set<int> st;
    set<int> frnds;
    for(int i=0;i<n;++i) {
        int frndId;
        scanf("%d", &frndId);
        frnds.insert(frndId);
        int num;
        scanf("%d", &num);
        for(int j=0;j<num;++j) {
            int id;
            scanf("%d", &id);
            st.insert(id);
        }
    }
    for(set<int>::iterator itr=frnds.begin();itr != frnds.end();++itr) {
        st.erase(*itr);
    }
    printf("%d\n", st.size());

}
