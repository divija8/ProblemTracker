class Solution
{
private:
    bool isOkay(int x, int m, vector<int> &arr)
    {
        int n = arr.size();
        int c = 1, p = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - p >= x)
            {
                p = arr[i];
                c++;
            }
        }
        return c >= m;
    }

public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int low = 0, high = position.back();
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isOkay(mid, m, position))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};