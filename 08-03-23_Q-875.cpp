class Solution
{ // Question - Koko Eating Bananas
public:
    int check(vector<int> &p, int mid)
    { // To calculate time to finish eating all the bananas
        int ans = 0;
        for (int i = 0; i < p.size(); i++)
        {
            ans += ceil(((double)p[i] / (double)mid));
        }
        return ans;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = INT_MIN;
        for (auto t : piles)
        { // Maximum element of piles vector
            high = max(high, t);
        }
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (check(piles, mid) <= h)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};