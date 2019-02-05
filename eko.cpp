#include<cstdio>
int compare(long long ht, long long* htArray, int len, long long expected) {
    long long sum = 0;
    for(int i=0;i<len && sum <= expected;++i) {
        if(htArray[i] > ht) {
            sum += htArray[i] - ht;
        }
    }
    if(sum > expected) {
        return 1;
    } else if(sum == expected) {
        return 0;
    } else {
        return -1;
    }
}
int main() {
    unsigned long long n, m;
    scanf("%lld %lld", &n, &m);
    long long* height = new long long[n];
    long long sum = 0;
    long long maxHeight = 0;
    for(int i=0;i<n;++i) {
        scanf("%lld", height + i);
        if(height[i] > maxHeight) {
            maxHeight = height[i];
        }
    }
    // Reducing by 1 so that at least one mtr gets cut
    maxHeight--;
    long long minHeight = 0;
    long long ans;
    while(true) {
        long long mid = (minHeight + maxHeight)/2;
        long long cmp = compare(mid, height, n, m);
        if(cmp == 0) {
            ans = mid;
            break;
        } else if(cmp == -1) {
            // need to decrease height
            maxHeight = mid - 1;
        } else {
            if(minHeight == mid) {
                cmp = compare(maxHeight, height, n, m);
                if(cmp == -1) {
                    ans = minHeight;
                    break;
                } else {
                    ans = maxHeight;
                    break;
                }
            }
            minHeight = mid;
        }
    }
    delete [] height;
    printf("%lld\n", ans);
    
}
