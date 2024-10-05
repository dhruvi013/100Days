class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        std::vector<int> s1Freq(26, 0), windowFreq(26, 0);

        // Populate frequency for s1
        for (char c : s1) {
            s1Freq[c - 'a']++;
        }

        // Initialize the first window in s2
        for (int i = 0; i < s1.size(); i++) {
            windowFreq[s2[i] - 'a']++;
        }

        // Check if the first window is a permutation of s1
        if (s1Freq == windowFreq) return true;

        // Slide the window over s2
        for (int i = s1.size(); i < s2.size(); i++) {
            windowFreq[s2[i] - 'a']++; // Add new char to the window
            windowFreq[s2[i - s1.size()] - 'a']--; // Remove the char out of the window

            // Check if current window matches the frequency of s1
            if (s1Freq == windowFreq) return true;
        }

        return false;
    }
};
