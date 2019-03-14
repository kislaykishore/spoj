#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Info {
    int tallerCount;
    int height;
    bool operator < (const Info& rhs) const {
        if(height == rhs.height) {
            return tallerCount < rhs.tallerCount;
        } else {
            return height < rhs.height;
        }
    }
};
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int n;
        scanf("%d", &n);
        Info* infoArray = new Info[n];
        for(int i=0;i<n;++i) {
            scanf("%d", &infoArray[i].height);
        }
        for(int i=0;i<n;++i) {
            scanf("%d", &infoArray[i].tallerCount);
        }
        sort(infoArray, infoArray + n);
        int *positions = new int[n];
        memset(positions, -1, sizeof(int) * n);
        for(int i=0;i<n;++i) {
            Info& info = infoArray[i];
            int pos = info.tallerCount;
            int count = 0;
            for(int j=0;j<n;++j) {
                if(positions[j] == -1) {
                    count++;
                }
                if(count == pos + 1) {
                    positions[j] = info.height;
                    break;
                }
            }
        }
        for(int i=0;i<n;++i) {
            printf("%d ", positions[i]);
        }
        printf("\n");
        delete [] positions;
        delete [] infoArray;
    }
}
