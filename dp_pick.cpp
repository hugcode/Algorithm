/* pick up some numbers, the numbers can't not be adjacent, find out the largest sum 
 * dp[i]: Maximum sum of a[0,i]
 * Init:  dp[0] = 0
 * Rec:   dp[i] = max(dp[i-2]+a[i], dp[i-1])
 * Ans:   dp[n-1]
 */

#include <iostream>
#include <algorithm>

using namespace std;

int a[] = {100,3,5,7,10,100};
int dp[100];

int main(void)
{
    int i, n;
    
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);

    n = sizeof(a)/sizeof(int);    
    for (i=2; i<n; i++) {
        dp[i] = max(dp[i-2]+a[i], dp[i-1]);
    }

    for (i=0; i<n; i++)
        printf("%3d ", a[i]);
    cout << endl;

    for (i=0; i<n; i++)
        printf("%3d ", dp[i]);      
    cout << endl;

    cout << dp[n-1] << endl;
    
    return 0;
}
