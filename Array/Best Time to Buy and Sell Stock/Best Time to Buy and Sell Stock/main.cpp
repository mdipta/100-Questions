#include <iostream>
#include <vector>

using namespace std;

/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock),
 design an algorithm to find the maximum profit.
 Note: that you cannot sell a stock before you buy one.
*/

/*
 Example 1:
 Input: [7,1,5,3,6,4]
 Output: 5
 Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 Not 7-1 = 6, as selling price needs to be larger than buying price.
 
 Example 2:
 Input: [7,6,4,3,1]
 Output: 0
 Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

int maxProfit(vector<int>& prices) {
    // if the prices vector has less than 2 elements return 0
    if (prices.size() < 2) return 0;
    
    // variable to keep track of the max profit
    int maxProfit = 0;
    
    // variable to keep track of the min price
    int minPrice = INT_MAX;
    
    for (int i=0; i<prices.size(); i++) {
        // using the min function to track the min price
        minPrice = min(minPrice, prices[i]);
        
        // using the max function to track the max profit
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;
}

int main(int argc, const char * argv[]) {
    vector<int> prices{7,6,4,3,1};
    cout << maxProfit(prices) << endl;
}
