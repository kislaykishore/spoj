#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Log {
    int time;
    bool isEntry;
};
bool compareLog(Log i1, Log i2) 
{ 
    return (i1.time < i2.time); 
} 
int main() {
    int tests;
    scanf("%d", &tests);
    Log array[200];
    while(tests--) {
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;++i) {
            int entry, exit;
            scanf("%d %d", &entry, &exit);
            Log entryLog;
            entryLog.time = entry;
            entryLog.isEntry = true;
            Log exitLog;
            exitLog.time = exit;
            exitLog.isEntry = false;
            array[2*i] = entryLog;
            array[2*i+1] = exitLog;
        }
        sort(array, array + (2*n), compareLog);
        int runningSum = 0;
        int maxSum= 0;
        for(int i=0;i<2*n;++i) {
            if(array[i].isEntry) {
                runningSum++;
                if(maxSum < runningSum) {
                    maxSum = runningSum;
                }
            } else {
                runningSum--;
            }
        }
        printf("%d\n", maxSum);
    }
}
