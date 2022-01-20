#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int Pattern(vector<int>& nums, int start, int back) {
    int val = nums[start];
    while (start < back) {
        while (start < back && nums[back] >= val) back--;
        if (start < back) nums[start] = nums[back];
        while (start < back && nums[start] <= val) start++;
        if (start < back) nums[back] = nums[start];
    }
    nums[start] = val;
    return start;
}
// 递归版本
void QuickSort(vector<int>& nums, int start, int back) {
    if (nums.empty() || start > back || start < 0 || back >= nums.size()) {
        return;
    }
    int mid = Pattern(nums, start, back);
    if (mid > start) QuickSort(nums, start, mid-1);
    if (mid < back)  QuickSort(nums, mid+1, back);
}
// 非递归版本
void QuickSort(vector<int>& nums) {
    if (nums.size() <= 1) return;
    int left = 0;
    int right = nums.size() - 1;
    stack<pair<int, int>> stk;
    stk.push({left, right});
    while (stk.size()) {
        int start = stk.top().first;
        int back = stk.top().second;
        stk.pop();
        int mid = Pattern(nums, start, back);
        if (mid > start) stk.push({start, mid-1});
        if (mid < back) stk.push({mid+1, back});
    }
}

int main()
{
    vector<int> nums{ 8,4,3,2,7,5,0,3,4,3,2 };
    // QuickSort(nums, 0, nums.size()-1);
    QuickSort(nums);
    for (auto elem : nums) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
