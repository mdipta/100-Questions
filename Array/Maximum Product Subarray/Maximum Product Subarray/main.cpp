#include <iostream>
#include <vector>

using namespace std;

/* Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which
 * has the largest product.
 */

/* Example 1:
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 
 * Example 2:
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

int maxProduct(vector<int>& nums) {
    // stores the current max product
    int curMaxProd = nums[0];
    
    // stores the current min product
    int curMinProd = nums[0];
    
    // stores the previous max product
    int prevMaxProd = nums[0];
    
    // stores the previous min product
    int prevMinProd = nums[0];
    
    // stores the answer
    int ans = nums[0];
    
    for (int i = 1; i < nums.size(); ++i) {
        /* checks to see which is greater and stores it:
         * the previous max product times the current element,
         * the previous min product times the current element,
         * or the current element
         */
        curMaxProd = max(max(prevMaxProd * nums[i], prevMinProd * nums[i]), nums[i]);
        
        /* checks to see which is the smallest and stores it:
         * the previous max product times the current element,
         * the previous min product times the current element,
         * or the current element
         */
        curMinProd = min(min(prevMaxProd * nums[i], prevMinProd * nums[i]), nums[i]);
        
        // checks to see which is greater: the answer or the current max product and stores the greater
        ans = max(ans, curMaxProd);
        
        // updates the previous max product to the current max product
        prevMaxProd = curMaxProd;
        
        // updates the previous min product to the current min product
        prevMinProd = curMinProd;
        
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> input1{2,3,-2,4};
    cout << "Example 1:" << endl;
    cout << "Input: [2,3,-2,4]" << endl;
    cout << "Output: " << maxProduct(input1) << endl << endl;
    
    vector<int> input2{-4,-3,-2};
    cout << "Example 2:" << endl;
    cout << "Input: [-2,0,-1]" << endl;
    cout << "Output: " << maxProduct(input2) << endl << endl;
}
