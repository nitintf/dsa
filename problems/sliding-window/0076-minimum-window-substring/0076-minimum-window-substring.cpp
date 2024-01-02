class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        
        for (auto& ch: t) {
            map[ch]++;
        }
        
        int count = map.size();
        
        int right = 0, left = 0;
        int min_len = INT_MAX;
        int start = 0;
        
        while (right < s.size()) {
            if (map.find(s[right]) != map.end()) {
                map[s[right]]--;
                if (map[s[right]] == 0) {
                    count--;
                }
            }
            
            if (count == 0) {
                while (count == 0) {
                    if (map.find(s[left]) != map.end()) {
                        map[s[left]]++;
                        if (map[s[left]] == 1){
                            count++;
                            if (right - left + 1 < min_len) {
                                min_len = right - left + 1;
                                start = left;
                            }
                        }
                    }
                    left++;
                }
            }
            right++;
        }
        
        if (min_len == INT_MAX) return "";
        
        return s.substr(start, min_len);
    }
};