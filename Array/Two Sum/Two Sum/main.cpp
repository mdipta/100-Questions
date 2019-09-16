#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

/*
 Example:
    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
*/

vector<int> twoSum(vector<int>& nums, int target) {
    // creating a hash map to store the complement and index
    unordered_map<int, int> myMap;
    
    for (int i=0; i<nums.size(); i++) {
        // finding the complement
        int complement = target - nums[i];
        
        // checking to see if the complement is in the map
        if (myMap.find(complement) != myMap.end()) {
            
            // returning the index of the complement and current index
            return {myMap[complement], i};
        }
        // storing the current number  as key and index as the value
        myMap[nums[i]] = i;
    }
    // returning an empty vector
    return {};
}

int main(int argc, const char * argv[]) {
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    
    vector<int> ans = twoSum(nums, target);
    cout << "[";
    string separator = "";
    for (auto x : ans) {
        cout << separator << x;
        separator = ", ";
    } cout << "]" << endl;
}
