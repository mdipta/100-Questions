#include <iostream>
#include <vector>

using namespace std;

/* Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest
 * sum and return its sum.
 */

/* Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 */

/* Follow up:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach,
 * which is more subtle.
 */

int maxSubArray(vector<int>& nums) {
    // the max so far starts at the first index
    int maxSoFar = nums[0];
    
    // the max ending also starts at the first index
    int maxEndingHere = nums[0];
    
    for (int i = 1; i < nums.size(); ++i) {
        // the max ending takes whatever is greater (current index or the max ending plus the current index)
        maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
        
        // the max so far takes whatever is greater (max so far or the max ending)
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int main(int argc, const char * argv[]) {
    vector<int> res{-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(res) << endl;
}
