bool isAnagram(char* s, char* t) {
    int *num = (int *)calloc(sizeof(int), 128);
    for (int i = 0; s[i]; i++) {
        num[s[i]] += 1;
    }
    for (int i = 0; t[i]; i++) {
        num[t[i]] -= 1;
    }
    int flag = 1;
    for (int i = 0; i < 128; i++) {
        if (num[i] != 0) {
            flag = 0;
            break;
        }
    }
    free(num);
    if (flag) return true;
    return false;
}