#include<cstdio>
#include<set>
using namespace std;
int main() {
    // precompute
    int array[500001];
    set<int> st;
    array[0] = 0;
    st.insert(0);
    for(int i=1;i<=500000;++i) {
        int val = array[i-1] - i;
        if(val > 0 && st.find(val) == st.end()) {
            array[i] = val;
        } else {
            array[i] = array[i-1] + i;
        }
        st.insert(array[i]);
    }
    while(true) {
        int v;
        scanf("%d", &v);
        if(v == -1) {
            return 0;
        }
        printf("%d\n", array[v]);
    }
}

