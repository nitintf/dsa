class Solution {
public:
  string minWindow(string str, string t) {
    int len1 = str.length();
    int len2 = t.length();

    // Hash array to count occurrences of each character
    int hash_pat[256] = { 0 };
    int hash_str[256] = { 0 };

    // Store the occurrences of t
    for (int i = 0; i < len2; i++) {
      hash_pat[t[i]]++;
    }

    // Initialize 3 things
    int start = 0;
    int start_index = -1;
    int min_len = INT_MAX;  // Include <climits> for INT_MAX
    int count = 0;

    // Start traversing the string
    for (int j = 0; j < len1; j++) {
      hash_str[str[j]]++;

      // String char matches with pattern char then increment count
      if (hash_str[str[j]] <= hash_pat[str[j]]) {
        count++;
      }

      if (count == len2) {
        // Try to minimize the window
        while (hash_str[str[start]] > hash_pat[str[start]] || hash_str[str[start]] == 0) {
          if (hash_str[str[start]] > hash_pat[str[start]]) {
            hash_str[str[start]]--;
          }
          start++;
        }

        // Update the window size also
        int len_window = j - start + 1;
        if (min_len > len_window) {
          min_len = len_window;
          start_index = start;
        }
      }
    }

    // If no valid window found
    if (start_index == -1) {
      return "";
    }

    return str.substr(start_index, min_len);
  }
};
