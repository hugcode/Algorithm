/* Longest Increasing Subsequence
 * O(n^2)
 * dp[i]: lis end at index i 
 * Init:  dp[i] = 1
 * Rec:   dp[i] = dp[j] + 1 if a[j] < a[i]  (0<= j < i < len)
 * Ans:   max(dp[i] 0<=i<len)
 *
 * O(nlogn)
 * tail[i]: the minimum tail number of lis(i)
 */

#include <iostream>
#include <algorithm>

using namespace std;

int a[] = {10,3, 4,9,8,6};
int dp[100];
int tail[100];

int main(void)
{
    int i, j, len, max;
    
    len = sizeof(a)/sizeof(int);
    max = 1;
    
    /* O(n^2) */   
    for (i=0; i<len; i++) {
        dp[i] = 1;
        for (j=0; j<i; j++) {
            if (a[i] > a[j] && (dp[j] + 1) > dp[i])
                dp[i] = dp[j] + 1;
        }

        if (dp[i] > max)
            max = dp[i];
    }

    for (i=0; i<len; i++)
        printf("%2d ", a[i]);
    cout << endl;

    for (i=0; i<len; i++)
        printf("%2d ", dp[i]);
    cout << endl;

    cout << max << endl;

    /* O(nlogn) */
    max = 0;
    tail[0]=a[0];
    for (i=1; i<len; i++) {
        if (a[i] > tail[max]) {
            max++;
            tail[max] = a[i];
        } else {
            *lower_bound(tail, tail+max+1, a[i]) = a[i];
        }
    }

    for (i=0; i<len; i++)
        printf("%2d ", tail[i]);
    cout << endl;

    cout << max+1 << endl;

    return 0;
}
