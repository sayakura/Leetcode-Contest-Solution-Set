string mergeAlternately(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    string r;
    r.reserve(n + m);
    int i = 0, j = 0;
    while (i < n or j < m) {
        if (i < n) 
            r += word1[i++];
        if (j < m)
            r += word2[j++];
    }
    return r;
}