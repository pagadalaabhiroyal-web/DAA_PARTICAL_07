#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChangeMin(vector<int>& coins, int amount) {
    
    vector<int> dp(amount + 1, amount + 1);
    
    
    dp[0] = 0;
    
    
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
   
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    
    int result = coinChangeMin(coins, amount);
    cout << "Minimum coins required: " << result << endl; // Output: 3 (5 + 5 + 1)
    
    return 0;
}
