#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

class Solution {
    private:
        int right(int idx, int n, vector<int> &height) {
            int maxx = height[idx];

            for (int i = idx; i < n; i++) {
                maxx = max(maxx, height[i]);
            }

            return maxx;
        }

        int left(int idx, vector<int> &height) {
            int maxx = height[idx];

            for (int i = idx; i >= 0; i--) {
                maxx = max(maxx, height[i]);
            }

            return maxx;
        }

    public:

        // brute force approach, we find the max height on left and right find the min of that and subtract the current height thats the unit of water we can store at that index,
        // TC: O(n*n), SC: O(1)
        int trap(vector<int> &height) {
            int totalWater= 0;
            int n = height.size();

            for (int i = 0; i < n; i++) {
                totalWater += min(left(i, height), right(i, n, height)) - height[i];
            }

            return totalWater;
        }


        int trapOpt(vector<int> &height) {

        }
};

int main() {}
