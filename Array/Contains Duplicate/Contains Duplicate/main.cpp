#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/* Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array, and it should return false
 * if every element is distinct.
 */

/* Example 1:
 * Input: [1,2,3,1]
 * Output: true
 
 * Example 2:
 * Input: [1,2,3,4]
 * Output: false
 
 * Example 3:
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 */

bool containsDuplicate(vector<int>& nums) {
    // create a hash set to find unique numbers
    unordered_set<int> mySet;
    
    for (int &num : nums) {
        
        // if the number already exists in the set, return true
        if (mySet.find(num) != mySet.end()) {
            return true;
        }
        
        // insert into the set
        mySet.insert(num);
    }
    
    // return false if all other condition fails
    return false;
}

int main(int argc, const char * argv[]) {
    vector<int> input1{1,2,3,1};
    cout << "Example 1:" << endl;
    cout << "Input: [1,2,3,1]" << endl;
    cout << "Output: " << containsDuplicate(input1) << endl << endl;
    
    vector<int> input2{1,2,3,4};
    cout << "Example 2:" << endl;
    cout << "Input: [1,2,3,4]" << endl;
    cout << "Output: " << containsDuplicate(input2) << endl << endl;
    
    vector<int> input3{1,1,1,3,3,4,3,2,4,2};
    cout << "Example 3:" << endl;
    cout << "Input: [1,1,1,3,3,4,3,2,4,2]" << endl;
    cout << "Output: " << containsDuplicate(input3) << endl << endl;
    
}
