class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;

        int right =0, left = 0;

        int sum = 0;

        while (right < arr.size()) {
            sum = sum + arr[right];
            if (right - left + 1 == k) {
                int avg = sum/k;

                if (avg >= threshold) {
                    count++;
                }

                sum = sum - arr[left];
                left++;
            }
            right++;
        }

        return count;
    }
};