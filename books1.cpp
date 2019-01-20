#include<cstdio>
#include<list>
using namespace std;
long long find_min(long long *books, long long lowerBound, long long upperBound, int m, int k);
bool validate(long long *books, long long maxVal, int size, int k);
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int m, k;
        scanf("%d %d", &m, &k);
        long long *books = new long long[m];
        long long maxnum = 0;
        long long sum = 0;
        for(int i=0;i<m;++i) {
            scanf("%lld", books + i);
            maxnum = books[i] > maxnum?books[i]:maxnum;
            sum += books[i];
        }
        long long lowerBound = maxnum;
        long long upperBound = sum;

        long long minima = find_min(books, lowerBound, upperBound, m, k);
        // based on minima, we need to categorize

        list<long long> *distribution = new list<long long>[k];
        // from the last, we start adding values
        int bookIndex = m-1;
        int count = 0;
        for(int i=k-1;bookIndex >= 0;) {
            list<long long>* l = distribution + i;
            if(bookIndex >= 0) {
                count += books[bookIndex];
                if(count <= minima) {
                    l->push_front(books[bookIndex]);
                    bookIndex--;
                } else {
                   count = 0;
                   i--;
                }
            }
        }
        for(int i=0;i<k && distribution[i].size() == 0;++i) {
            for(int j=i+1;j<k;++j) {
                if(distribution[j].size() != 0) {
                    int front = distribution[j].front();
                    distribution[j].pop_front();
                    distribution[i].push_back(front);
                    break;
                }
            }
        }
        for(int i=0;i<k;++i) {
            int sz = distribution[i].size();
            count = 1; 
            for(list<long long>::iterator itr=distribution[i].begin();itr != distribution[i].end();++itr, ++count) {
                if(count == sz && i == k-1) {
                    printf("%lld\n", *itr);
                } else {
                    printf("%lld ", *itr);
                } 
            }
            if(i != k -1) {
                printf("/ ");
            }
        }
        delete [] books;
        delete [] distribution; 
         
        
    }
}
long long find_min(long long *books, long long lowerBound, long long upperBound, int m, int k) {
    if(lowerBound == upperBound) {
        return lowerBound;
    }
    long long mid = (lowerBound + upperBound)/2;

    // check if the distribution is valid

    bool isValid = validate(books, mid, m, k);
    if(isValid) {
        // try reducing the upper bound
        return find_min(books, lowerBound, mid, m, k);
    } else {
        return find_min(books, mid + 1, upperBound, m, k);
    }
}


bool validate(long long *books, long long maxVal, int size, int k) {
    bool isValid = true;
    int bookIndex = 0;
    int curSum = 0;
    int count = 0;
    while(bookIndex < size && count <= k) {
        if(curSum == 0) {
            count++;
        }
        if(curSum + books[bookIndex] > maxVal) {
            curSum = 0;
        } else {
            curSum += books[bookIndex];
            bookIndex++;
        }
    }
    if(bookIndex != size || count > k) {
        return false;
    } else {
        return true;
    }
}
