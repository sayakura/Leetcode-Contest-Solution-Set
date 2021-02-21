vector<int> minOperations(string boxes) {
    const int n = boxes.size();
    vector<int> ret(n, 0);
    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (boxes[j] == '1')
                total += i - j;
        }
        for (int j = i + 1; j < n; j++) {
            if (boxes[j] == '1')
                total += j - i;
        }
        ret[i] = total;
    }
    return ret;
}

vector<int> minOperations(string boxes) {
    vector<int> res(boxes.length()); 
    for (int i = 0, total = 0, cnt = 0; i < boxes.length(); ++i) {
       res[i] += total;
       cnt += boxes[i] == '1' ? 1 : 0;
       total += cnt;
    }
    for (int i = boxes.length() - 1, total = 0, cnt = 0; i >= 0; --i) {
        res[i] += total;
        cnt += boxes[i] == '1' ? 1 : 0;
        total += cnt;
    }
    return res;
}