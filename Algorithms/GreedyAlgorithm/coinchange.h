class CoinChange
{
private:
    void displayCombination(int amount, const vector<float>& coins, int i, vector<vector<int>>& dp, vector<float>& currentCombination, int& count, int& maxCoins, int& minCoins) {
      
        if (amount == 0) 
        {
            cout << "Combination " << ++count << ": ";
            for (float coin : currentCombination) {
                cout << coin << " ";
            }
            cout << endl;

            if (currentCombination.size() > maxCoins) {
                maxCoins = currentCombination.size();
            }

            if (currentCombination.size() < minCoins) {
                minCoins = currentCombination.size();
            }
            return;
        }
        if (i < 0 || amount < 0) return;

        currentCombination.push_back(coins[i]);
        displayCombination(amount - coins[i], coins, i, dp, currentCombination, count, maxCoins, minCoins);
        currentCombination.pop_back();
        displayCombination(amount, coins, i - 1, dp, currentCombination, count, maxCoins, minCoins);
    }

    int calc(int amount, const vector<float>& coins, int i, vector<vector<int>>& dp)
    {
        if (i < 0 || amount < 0)
            return 0;
        if (amount == 0)
            return 1;
        if (dp[i][amount] != -1)
            return dp[i][amount];
        return dp[i][amount] = calc(amount - coins[i], coins, i, dp) + calc(amount, coins, i - 1, dp);
    }

    int change(int amount, const vector<float>& coins)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return calc(amount, coins, coins.size() - 1, dp);
    }

public:
    int run()
    {
    	system("cls");
    	cout << "\n| ----- COIN CHANGE ----- |\n";
        int amount;
        cout << "Enter the amount for which you want to make change: ";
        cin >> amount;

        vector<float> coins = { 1000, 500, 200, 100, 50, 20, 10, 5, 1};
        system("cls");
        cout << "Available coins to use [";
        for (size_t i = 0; i < coins.size(); ++i) {
            cout << coins[i];
            if (i < coins.size() - 1) 
            {
                cout << ", ";
            }
        }
        cout << "] to change for "  <<amount << "\n";

        cout << "Step-by-step combinations:\n";
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        vector<float> currentCombination;
        int count = 0;
        int maxCoins = 0;
        int minCoins = INT_MAX;
        displayCombination(amount, coins, coins.size() - 1, dp, currentCombination, count, maxCoins, minCoins);

        cout << "Total possible combinations of change for amount " << amount << ": " << change(amount, coins) << endl;
        cout << "Maximum amount of coins in combination for " << amount << ": " << maxCoins <<endl;
        cout << "Minimum amount of coins in combination for " << amount << ": " << (minCoins == INT_MAX ? 0 : minCoins);
    	
    	return again();
    }
};