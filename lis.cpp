/* Longest Increasing Subsequence
 * dp[i]: lis end at index i 
 * Init:  dp[i] = 1
 * Rec:   dp[i] = dp[j] + 1 if a[j] < a[i]  (0<= j < i < len)
 * Ans:   max(dp[i] 0<=i<len)
 */

#include <iostream>
#include <algorithm>

using namespace std;

int a[] = {3,10,4,9,8,6};
int dp[100];

int main(void)
{
    int i, j, len, max;
    
    len = sizeof(a)/sizeof(int);
    max = 1;
       
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

    return 0;
}
