#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/**
Notes
*/

class Solution {
private:
    bool canCollide(vector<int>& asteroids, int i, int j) {
        int first = asteroids[i];
        int second = asteroids[j];

        if ((first > 0 && second > 0) || (first < 0 && second < 0)) return true;

        return false;
    }

public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        int n = ast.size();

        for (int i = 0; i < n; i++) {
            if (ast[i] > 0 || st.empty()) {
                st.push(ast[i]);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(ast[i])) {
                    st.pop();
                }

                if (!st.empty() && st.top() == abs(ast[i])) {
                    st.pop();
                } else {
                    if (st.empty() || st.top() < 0) {
                        st.push(ast[i]);
                    }
                }
            }
        }

        vector<int> res(st.size());

        for (int i = (int)st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};

int main() {}
