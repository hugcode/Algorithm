/* 0-1 knapsack problem
 * Given weights and values of n items, put these items in a knapsack of capacity c
 * to get the maximum total value in the knapsack, each item can be used 0 or 1 time
 * dp[i][j] 0<=i<=n, 0<=j<=c 
 * Init: dp[i][j] = 0                                        if i == 0  (n is zero)
 *                = 0                                        if j == 0  (c is zero)
 * Rec:  dp[i][j] = dp[i-1][j]                               if w[i] >  j (can't put item i in a knapsack)
 *                = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i])  if w[i] <= j (can put item i in a knapsack)
 * Ans:  dp[n][c]
 *
 * f[j]  f[j] is the last row of dp (dp[n][j]) 0<=j<=c
 * Rec:  f[j] = max(f[j], f[j-w[i]]+v[i])
 * Ans:  f[c]
 */

#include <iostream>
#include <algorithm>

using namespace std;

int w[] = {6,3, 4, 9, 8, 10};
int v[] = {2, 4, 3,10, 8, 5};
int c = 25;
int dp[100][100];
int f[100];

int main(void)
{
    int i, j, n;
    
    n = sizeof(w)/sizeof(int);


    /* Two-dimensional array */
    for (i=0; i<=n; i++)
        dp[i][0] = 0;
    for (j=0; j<=c; j++)
        dp[0][j] = 0;

    for (i=1; i<=n; i++) {
        for (j=1; j<=c; j++) {
            if (w[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }    
    }

    /* One-dimensional array */
    for(i=0; i<n; i++)
        for(j=c; j>= w[i]; j--)
            f[j] = max(f[j], f[j-w[i]]+v[i]);

    printf("     w  v  c %2d\n", c);
    for(i=0; i<n; i++)
        printf(" %2d %2d %2d\n", i+1, w[i], v[i]);
    cout << endl;

    cout << "   ";
    for (j=0; j<=c; j++)
        printf(" %2d", j);
    cout << endl;
    for (i=0; i<=n; i++) {
        printf(" %2d ", i);

        for (j=0; j<=c; j++)
            printf("%2d ", dp[i][j]);
        cout << endl;
    }

    cout << endl << "   ";
    for (j=0; j<=c; j++)
        printf(" %2d", f[j]);
    cout << endl;

    cout << dp[n][c] << " " << f[c] << endl;

    return 0;
}
