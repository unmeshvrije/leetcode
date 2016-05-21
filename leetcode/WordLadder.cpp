class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        
        queue<string> wordQueue;
        queue<int> depthQueue;
        
        wordQueue.push(beginWord);
        depthQueue.push(1);
        //wordList.erase()
        
        while (wordQueue.size() > 0) {
            string word = wordQueue.front();
            wordQueue.pop();
            
            int depth = depthQueue.front();
            depthQueue.pop();
            
            if (word == endWord) {
                return depth;
            }
            
            
            for (int i = 0; i < word.size(); ++i) {
                for (int j = 0; j < 26; ++j) {
                    string temp = word;
                    temp[i] = j+'a';
                    if(wordList.count(temp) > 0) {
                        wordQueue.push(temp);
                        depthQueue.push(depth+1);
                        wordList.erase(temp);
                    }
                }
            }
        }
        
        return 0;
    }
};