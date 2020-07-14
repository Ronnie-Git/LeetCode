bool isIsomorphic(char* s, char* t) {
    char num[128] = {0}, n[128] = {0};
    for (int i = 0; s[i]; i++) {
        if (num[s[i]] == 0) num[s[i]] = t[i];
        if (n[t[i]] == 0) n[t[i]] = s[i];
        if (num[s[i]] != t[i] || (n[t[i]] && n[t[i]] != s[i])) return false;
    }
    return true;
}