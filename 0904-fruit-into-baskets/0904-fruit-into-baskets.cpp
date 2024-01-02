class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        
        // Edge case
        if (n == 1) {
            return 1;
        }
        
        int right = 0, left =0;

        int max_count = 0;

        unordered_map<int, int> fruitsMap;
        
        while (right < n) {
            int f = fruits[right];
            fruitsMap[f]++;
            
            if (fruitsMap.size() == 2) {
                max_count = max(max_count, right - left + 1);
            } else if (fruitsMap.size() > 2) {
                while(fruitsMap.size() > 2) {
                    fruitsMap[fruits[left]]--;
                    if (fruitsMap[fruits[left]] == 0) {
                        fruitsMap.erase(fruits[left]);
                    }
                    left++;
                }
            }
            
            right++;
        }
        
        if (fruitsMap.size() == 1) {
            auto fr = fruitsMap.begin();
            return fr->second;
        }

        return max_count;
    }
};