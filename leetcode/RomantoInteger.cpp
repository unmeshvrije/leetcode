class Solution {
public:
    int romanToInt(string s) {
        // MCMX

        int n = 0;
          
          std::map<char,int> romap;
          
   romap.insert(pair<char,int>('I', 1));
   romap.insert(pair<char,int>('V', 5));
   romap.insert(pair<char,int>('X', 10));
   romap.insert(pair<char,int>('L', 50));
   romap.insert(pair<char,int>('C', 100));
   romap.insert(pair<char,int>('D', 500));
   romap.insert(pair<char,int>('M', 1000));

        
        for(int i = 0; i < s.size(); ++i) {
            if (i+1 < s.size() && romap[s[i]] < romap[s[i+1]]) n -= romap[s[i]];
            else n += romap[s[i]];
        }
        
        return n;
    }
};