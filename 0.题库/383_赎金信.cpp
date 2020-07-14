bool canConstruct(char* ransomNote, char* magazine) {
    int len_s = strlen(ransomNote), len_t = strlen(magazine);
    int *num_s = (int *)calloc(sizeof(int), 128);
    int *num_t = (int *)calloc(sizeof(int), 128);
    for (int i = 0; ransomNote[i]; i++) {
        num_s[ransomNote[i]] += 1;
    }
    for (int i = 0; magazine[i]; i++) {
        num_t[magazine[i]] += 1;
    }
    int flag = 1;
    for (int i = 0; i < 128; i++) {
        if (num_s[i] > num_t[i]) {
            flag = 0;
            break;
        }
    }
    free(num_s);
    free(num_t);
    if (flag) return true;
    return false;   
}