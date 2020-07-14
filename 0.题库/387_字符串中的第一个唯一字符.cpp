int firstUniqChar(char* s) {
    int *num_s = (int *)calloc(sizeof(int), 128);
    int *num_t = (int *)calloc(sizeof(int), 128);
    for (int i = 0; s[i]; i++) {
        num_s[s[i]] += 1;
        num_t[s[i]] = i;
    }
    int flag = -1;
    for (int i = 0; s[i]; i++) {
        if (num_s[s[i]] == 1) {
            flag = num_t[s[i]];
            break;
        }
    }
    free(num_s);
    free(num_t);
    return flag;
}