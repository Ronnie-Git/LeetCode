int myAtoi(char* str) {
    int i = 0, ret = 0, flag = 1;
    while (str[i] == ' ') ++i;
    if (str[i] == '-') flag = -1, ++i;
    else if (str[i] == '+') flag = 1, ++i;
    while (str[i] && str[i] <= '9' && str[i] >= '0') {
        int pre_ret = ret;
        ret = ret * 10 + (str[i] - '0');
        if (ret / 10 != pre_ret) {
            return flag == -1 ? INT_MIN : INT_MAX;
        }
        ++i;
    }
    return ret * flag;  
}