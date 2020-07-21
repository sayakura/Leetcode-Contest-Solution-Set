// https://leetcode.com/problems/longest-absolute-file-path/

class Solution {
public:
    int countLevel(string token) {
        int cnt = 0;
        for (int i = 0; i < token.size(); i++){
            if (token[i] != '\t') return cnt;
            else cnt++;
        }
        return cnt;
    }
    int lengthLongestPath(string input) {
        stack<pair<int,int>> st;
        istringstream ss(input);
        int longest = 0;
        string token;

        st.push({ -1, -1 });
        while (getline(ss, token)) {
            int level = countLevel(token);
            while (!st.empty() && st.top().first >= level)
                st.pop();
            int curLength = st.top().second + 1 + token.size() - level;
            if (token.find(".") != string::npos)
                longest = max(longest, curLength); 
            st.push({ level, curLength });
        }
        return longest;
    }
};

/*
class Solution {
public:
    int countLevel(string token) {
        int cnt = 0;
        for (int i = 0; i < token.size(); i++){
            if (token[i] != '\t') return cnt;
            else cnt++;
        }
        return cnt;
    }
    int lengthLongestPath(string input) {
        stack<pair<int,int>> st;
        istringstream ss(input);
        int longest = 0;
        string token;

        st.push({ -1, -1 }); // a/b/c  a doesnt have '/', we need to minus 1 when we add '/a'
        while (getline(ss, token)) {
            int level = countLevel(token);
            while (!st.empty() && st.top().first >= level)  // find prefix, prefix's level should be less than current level
                st.pop();
            int curLength = st.top().second + 1 + token.size() - level; // length of:  prefix + '/' + "\t\t\t\tcurrentname.txt" - "\t\t\t"
            if (token.find(".") != string::npos) // only count filename
                longest = max(longest, curLength); 
            st.push({ level, curLength });
        }
        return longest;
    }
};
*/