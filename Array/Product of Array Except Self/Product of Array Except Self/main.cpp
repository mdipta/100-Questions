#include <iostream>
#include <vector>

using namespace std;

/* Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product
 * of all the elements of nums except nums[i].
 */

/* Example:
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 */

/* Note: Please solve it without division and in O(n).
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose
 * of space complexity analysis.)
 */

vector<int> productExceptSelf(vector<int>& nums) {
    // store the size of the vector
    int n = (int)nums.size();
    
    // creating a array that is resized to be same size as nums array and fill it with 1
    vector<int> res(n, 1);
    
    // initialize product to be 1
    int prod = 1;
    
    // multiplies all the numbers on the left side of the index
    for (int i = 0; i < nums.size(); ++i) {
        res[i] *= prod;
        prod *= nums[i];
    }
    
    // reassign product to be 1
    prod = 1;
    
    // multiplies all the numbers on the right side of the index
    for (int i = n - 1; i >= 0; --i) {
        res[i] *= prod;
        prod *= nums[i];
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> res{1,2,3,4};
    vector<int> ans = productExceptSelf(res);
    cout << "[";
    string seperator = "";
    for (auto num : ans) {
        cout << seperator << num;
        seperator = ", ";
    } cout << "]" << endl;
}
