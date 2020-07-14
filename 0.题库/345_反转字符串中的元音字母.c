char* reverseVowels(char* s) {
    int num[1000] = {0};
    num['a'] = 1, num['e'] = 1, num['i'] = 1, num['o'] = 1, num['u'] = 1;
    num['A'] = 1, num['E'] = 1, num['I'] = 1, num['O'] = 1, num['U'] = 1;
    int *k = (int *)calloc(sizeof(int), strlen(s));
    int j = 0;
    for (int i = 0; s[i]; i++) {
        if (num[s[i]]) k[j++] = i;
    }
    int l = 0, r = j - 1;
    while (l <= r) {
        char temp = s[k[r]];
        s[k[r]] = s[k[l]];
        s[k[l]] = temp;
        l++, r--;
    } 
    free(k);
    return s;
}