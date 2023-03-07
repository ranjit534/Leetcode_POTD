class Solution // Question-Minimum Time to Complete Trips
{
public:
    long long countTrips(vector<int> &time, int total, long long int midTime)
    { // To count number of trips for given time
        long long count = 0;
        for (auto t : time)
        {
            count += (midTime / (long long int)t);
        }
        return count;
    }
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long int low = 1, high = 1e14; // Range of possible times
        while (low < high)
        {
            long long int mid = low + (high - low) / 2;
            if (countTrips(time, totalTrips, mid) >= totalTrips)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};