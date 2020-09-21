/* Longest palindromic subsequence
 * dp[i][j]: lps length within a[i,j], i is the left index, j is the right index 
 * Init:  dp[i][i] = 1 (0<=i<n)
 *        dp[i][j] = 0 (if j>i, all items in bottom left of matrix)
 * Rec:   dp[i][j] = max(dp[i+1][j], dp[i][j-1])  if a[i]!=a[j]
 *        dp[i][j] = dp[i+1][j-1]+2               if a[i]==a[j] && dp[i+1][j-1] == j-i-1
 *          (dp[i+1][j-1] == j-i-1) means that a[i+1,j-1] is palindrome 
 *        only need gothrouth the items in up right of matrix
 * Ans:   dp[0][n-1]
 */

#include <iostream>
#include <algorithm>

using namespace std;

string a = "cabcbbad";
int  dp[100][100];

int main(void)
{
    int i, j, n;
    int left = 0, right = 0;
    
    n = a.length();

    for (i=0; i<n; i++)
        dp[i][i] = 1;

    for (i=n-2; i>=0; i--) {
        for (j=i+1; j<n; j++) {
            if (a[i] == a[j] && dp[i+1][j-1] == j-i-1) {
                dp[i][j] = dp[i+1][j-1] + 2;
                if (right - left < j - i) {
                    left  = i;
                    right = j;
                }
            }
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);            
        }
    }

    cout << "   ";
    for (j=0; j<n; j++)
        printf(" %c ", a[j]);
    cout << endl;
    for (i=0; i<n; i++) {
        printf(" %c ", a[i]);

        for (j=0; j<n; j++)
            printf("%2d ", dp[i][j]);
        cout << endl;
    }

    cout << dp[0][n-1] << endl;
    printf("left %d right %d string ", left, right);
    cout << a.substr(left, right-left+1) << endl;

    return 0;
}
