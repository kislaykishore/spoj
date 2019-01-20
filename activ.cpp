#include<cstdio>
#include<algorithm>
using namespace std;
const int MODULO = 100000000;
struct Interval {
    int startTime;
    int endTime;
};

bool compareInterval(Interval i1, Interval i2) {
    return (i1.startTime < i2.startTime);
}

int computeSubsets(Interval* intervals, int num);
int main() {
    while(true) {
        int num;
        scanf("%d", &num);
        if(num == -1) {
            return 0;
        }
        Interval *intervals = new Interval[num];
        for(int i=0;i<num;++i) {
            int startTime, endTime;
            scanf("%d %d", &startTime, &endTime);
            intervals[i].startTime = startTime;
            intervals[i].endTime = endTime;
        }
        sort(intervals, intervals + num, compareInterval);

        int subsets = computeSubsets(intervals, num);
    }
}

int computeSubsets(Interval* intervals, int num) {
    int count = 0;
    for(int i=0;i<num;++i) {
        // We are choosing the starting interval
        Interval *first = intervals + i;
        count += computeSubsets(intervals, i, i+1, num);
        count %= MODULO;
    }
    return count;
}

int computeSubsets(Interval* intervals, int prevIndex, int curIndex, int size) {
    // find the next interval
}
