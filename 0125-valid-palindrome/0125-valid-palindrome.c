bool isPalindrome(char* s) {
    int n = strlen(s);
    char fil[n+1];
    fil[0] = '\0'; 
    for (int i = 0; i < n; i++) {
        char c = tolower(s[i]);
        if (isalnum(c)) {
            strncat(fil, &c, 1);
        }
    }
    int l = 0, r = strlen(fil) - 1;
    while (l < r) {
        if (fil[l] != fil[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}