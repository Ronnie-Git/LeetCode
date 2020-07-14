char* reverseString(char* s) {
    int l = 0, r = strlen(s) - 1;
    while (l <= r) {
        char temp = s[r];
        s[r] = s[l];
        s[l] = temp;
        l++, r--;
    }
    return s;
}