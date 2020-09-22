/* 
 * dp[i]: Minimum number of coins of value i
          dp[i] = 0 means no coins can make up value i 
 * Init:  dp[0] = 0
 * Rec:   dp[i] = min(dp[i-coins[j]]) + 1 if i>coins[j] && dp[i-coins[j]]!=0
          dp[i] = 1 if i == coins[j]
          dp[i] = 0 if i<coins[j]
 * Ans:   dp[sum]
 */

#include <iostream>
#include <algorithm>

using namespace std;

int coins[] = {3,5,7};
int dp[100];

int main(void)
{
    int i, j, kinds, v;
    int sum = 30;
    
    kinds = sizeof(coins)/sizeof(int);

    cout << "sum " << sum;
    cout << " coins: ";
    for (i=0; i<kinds; i++)
        printf("%2d ", coins[i]);
    cout << endl;

    dp[0] = 0;
    for (i=1; i<=sum; i++) {
        v = INT_MAX;
        for (j=0; j<kinds; j++) {
            if (i == coins[j]) {
                v = 1;
                break;
            } else if (i > coins[j] && dp[i-coins[j]]) {
                v = min(v, dp[i-coins[j]]+1);
            }
        }
        if (v != INT_MAX)
            dp[i] = v;
        else
            dp[i] = 0;
    }

    for (i=0; i<=sum; i++)
        printf("%2d ", i);
    cout << endl;

    for (i=0; i<=sum; i++)
        printf("%2d ", dp[i]);      
    cout << endl;

    return 0;
}
