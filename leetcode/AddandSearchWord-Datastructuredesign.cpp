struct TrieNode {
    char ch;
    bool marker;
    vector<TrieNode*> children;
    
    TrieNode(char c): ch(c){
        marker = false;
        children = vector<TrieNode*>();
    }
    
    TrieNode* findChild(char c) {
        for (int i = 0; i < children.size(); ++i) {
            if (children[i]->ch == c) {
                return children[i];
            }
        }
        return NULL;
    }
    
    bool hasChildWithMaker() {
        for (int i = 0; i < children.size(); ++i) {
            if (children[i]->marker) {
                return true;
            }
        }
        
        return false;
    }
};


class WordDictionary {
    private:
    char ch;
    TrieNode* root;
public:

    WordDictionary() {
        root = new TrieNode('#');
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        
        TrieNode* current = root;
        if (word.size() == 0) {
            root->marker = true;
            return;
        }
        
        for (int i = 0; i < word.size(); ++i) {
            TrieNode* newnode = current->findChild(word[i]);
            if (!newnode) {
                newnode = new TrieNode(word[i]);
                current->children.push_back(newnode);
            }
            
            current = newnode;
            if (i == word.size() - 1) {
                current->marker = true;
            }
        }
    }

   
   bool matchPattern(string& pattern, int index, TrieNode* node) {
       if (index == pattern.size()-1)  {
           if (pattern[index] == '.') {
               if (node->children.size() != 0 && node->hasChildWithMaker()) {
                   // There has to be at least one child with a maker
                   return true;
               }
           } else {
               TrieNode* child = node->findChild(pattern[index]);
               if (child != NULL && child->marker) {
                   return true;
               }
           }
           return false;
       }
       
       if (pattern[index] == '.') {
           bool result = false;
           for (int i = 0; i < node->children.size(); ++i) {
                result |= matchPattern(pattern, index+1, node->children[i]);
           }
           return result;
       } else {
            TrieNode* child = node->findChild(pattern[index]);
            if (!child) {
                return false;
            }
            
            return matchPattern(pattern, index+1, child);
       }
       
   }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        matchPattern(word, 0, root);
        /*
        TrieNode* current = root;
        TrieNode* next;
        for (int i = 0; i < word.size(); ++i) {
            next = current->findChild(word[i]);
            if (next) {
                current = next;
            } else {
                return false;
            }
        }
        
        if (next->marker == false) {
            return false;
        }
        
        return true;*/
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");