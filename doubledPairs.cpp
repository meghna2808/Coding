class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> nums;
        sort(arr.begin(), arr.end(), [](int &a, int &b)
             { return abs(a) < abs(b); });
        for (int i : arr)
            nums[i]++;
        for (int i = 0; i < n; i++)
        {
            if (nums[arr[i]] == 0)
                continue;
            if (nums[arr[i] * 2] < 1)
                return false;
            nums[arr[i]]--;
            nums[arr[i] * 2]--;
        }
        return true;
    }
};