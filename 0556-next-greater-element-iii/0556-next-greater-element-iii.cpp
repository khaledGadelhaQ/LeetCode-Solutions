class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);

        // Find the first decreasing digit from the right
        int i = s.size() - 1;
        while (i > 0 && s[i - 1] >= s[i]) {
            i--;
        }

        // If no such digit is found, the number is already the largest possible
        if (i == 0) {
            return -1;
        }

        // Find the smallest digit to the right of s[i-1] and greater than s[i-1]
        int j = s.size() - 1;
        while (s[j] <= s[i - 1]) {
            j--;
        }

        // Swap s[i-1] and s[j]
        swap(s[i - 1], s[j]);

        // Reverse the substring to the right of s[i-1]
        reverse(s.begin() + i, s.end());

        // Convert the modified string back to an integer
        long long result = stoll(s);
        
        // Check for overflow
        if (result > numeric_limits<int>::max()) {
            return -1;
        }

        return static_cast<int>(result);
    }
};
