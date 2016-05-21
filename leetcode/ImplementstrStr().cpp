class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        
        if (n > h) {
            return -1;
        }
        
        if (n == 0) {
            return 0;
        }
        
        int i,j,k;
        for (i = 0; i < h; ++i) {
            if (haystack[i] == needle[0]) {
                if (haystack[i+n-1] == needle[n-1]) {
                    k = 1;
                    for (j = i+1; j < i+n-1; ++j) {
                        if (haystack[j] != needle[k++]) {
                            break;
                        }
                    }
                    if (j >= i+n-1) {
                        return i;
                    }
                }
            }
        }
        
        return -1;
    }
};