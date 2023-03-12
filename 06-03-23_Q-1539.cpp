class Solution // Qusetion number - 1539 Leetcode
{
public:
    int findKthPositive(vector<int> &arr, int k) // To find Kth missing positive integer.
    {
        int low = 0, high = arr.size();
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if ((arr[mid] - mid - 1) >= k) //(arr[i] - i - 1) gives the number of missing positive numbers till ith index.
                high = mid;
            else
                low = mid + 1;
        }
        return low + k; // Returns the required missing number
    }
};