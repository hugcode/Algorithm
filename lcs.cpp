/* Longest Common Subsequence
 * dp[i][j]: lcs at a[i]b[j] 
 * Init:  dp[0][j] = 0 (0<=j<=n)
 *        dp[i][0] = 0 (0<=i<=n)
 * Rec:   dp[i][j] = max(dp[i][j-1], dp[i-1][j])  if a[i-1]!=b[j-1]
 *        dp[i][j] = dp[i-1][j-1]+1               if a[i-1]==b[j-1]
 * Ans:   dp[i][j]
 */

#include <iostream>
#include <algorithm>

using namespace std;

int a[] = {3,4,11,4,9,8,6};
int b[] = {4,9,12,6};
int dp[100][100];

int main(void)
{
    int i, j, len_i, len_j;
    
    len_i = sizeof(a)/sizeof(int);
    len_j = sizeof(b)/sizeof(int);

    for (i=0; i<=len_i; i++)
        dp[i][0] = 0;
    for (j=0; j<=len_j; j++)
        dp[0][j] = 0;

    for (i=1; i<=len_i; i++) {
        for (j=1; j<=len_j; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);            
        }
    }

    cout << "      ";
    for (i=0; i<len_i; i++)
        printf("%2d ", a[i]);
    cout << endl;
    for (j=0; j<=len_j; j++) {
        if (j==0)
            cout << "   ";
        else
            printf("%2d ", b[j-1]);

        for (i=0; i<=len_i; i++)
            printf("%2d ", dp[i][j]);
        cout << endl;
    }

    cout << dp[len_i][len_j] << endl;

    return 0;
}
