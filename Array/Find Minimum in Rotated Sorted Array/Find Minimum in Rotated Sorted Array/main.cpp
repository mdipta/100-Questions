#include <iostream>
#include <vector>

using namespace std;

/* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
 */

/* Example 1:
 * Input: [3,4,5,1,2]
 * Output: 1
 
 * Example 2:
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 */

int findMin(vector<int>& nums) {
    // starting index
    int start = 0;
    
    // ending index
    int end = (int)nums.size() - 1;
    
    while (start < end) {
        
        // if the element at the start is less than the element at the end the array is sorted
        if (nums[start] < nums[end]) {
            return nums[start];
        }
        
        // calculating the mid index
        int mid = (start + end) / 2;
        
        // if the mid is greater than the start change mid to one more than mid else change end to mid
        if (nums[mid] > nums[start]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return nums[start];
}

int main(int argc, const char * argv[]) {
    vector<int> input1{3,4,5,1,2};
    cout << "Example 1:" << endl;
    cout << "Input: [3,4,5,1,2]" << endl;
    cout << "Output: " << findMin(input1) << endl << endl;
    
    vector<int> input2{4,5,6,7,0,1,2};
    cout << "Example 2:" << endl;
    cout << "Input: [4,5,6,7,0,1,2]" << endl;
    cout << "Output: " << findMin(input2) << endl << endl;
}
