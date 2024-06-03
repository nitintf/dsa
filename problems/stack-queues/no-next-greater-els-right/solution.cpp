#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/**
Notes
*/

class Solution{
public:

    // Brute Force approach - Time comp. O(n * queries), space comp. O(queries)
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int> result;
        for (int i = 0; i < queries; i ++) {
            int query = indices[i];
            int nges = 0;
            for (int j = 0; j < n; j++) {
                if (j > query) {
                    if (arr[j] > arr[query]) {
                        nges++;
                    }
                }
            }
            result.push_back(nges);
        }
        return result;
    }

    // WRONG SOLUTION
    // Optimized Solution using dicresaing monotonic stack - TC O(n) & SC O(n)
    vector<int> count_NGE_Optimized(int n, vector<int> &arr, int queries, vector<int> &indices) {
        vector<int> result;
        vector<int> nge(n, 0);
        stack<int> ms;

        // traverse the list from right to left
        for (int i = n - 1; i >= 0; i--) {
            while (!ms.empty() && arr[i] >= arr[ms.top()]) {
                ms.pop();
            }

            nge[i] = ms.size();

            ms.push(i);
        }

        for (int i = 0; i < queries; i++) {
            result.push_back(nge[indices[i]]);
        }

        return result;
    }

};

int main() {}
