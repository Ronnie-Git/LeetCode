int lengthOfLastWord(char* s) {
    int ans = 0, flag = 1;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == ' ' && ans) return ans;
        if (s[i] != ' ') ans++;
    }
    return ans;
}