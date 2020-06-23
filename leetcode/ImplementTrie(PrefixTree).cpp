class TrieNode {
    char ch;
    bool marker;
    vector<TrieNode*> children;
public:
    // Initialize your data structure here.
    TrieNode() {
        marker = false;
        children = vector<TrieNode*>();
    }
    
    void setChar(char ch) {
        this->ch = ch;
    }
    
    void setMarker(bool m) {
        this->marker = m;
    }
    
    char getChar()const {
        return ch;
    }
    
    bool getMarker() const {
        return marker;
    }
    
    TrieNode* findChild(char ch) {
        for (int i = 0; i < children.size(); ++i) {
            if (children[i]->ch == ch) {
                return children[i];
            }
        }
        return NULL;
    }
    
    void appendChild(TrieNode* child) {
        children.push_back(child);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* current = root;
        if (word.size() == 0) {
            current->setMarker(true);
            return;
        }
        
        for (int i = 0; i < word.size(); ++i) {
            TrieNode* child = current->findChild(word[i]);
            if (!child) {
                child = new TrieNode();
                child->setChar(word[i]);
                current->appendChild(child);
            }
            current = child;
            if (i == word.size()-1) {
                current->setMarker(true);
            }
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* current = root;
        TrieNode* next;
        for (int i = 0; i < word.size(); ++i) {
            next = current->findChild(word[i]);
            if (!next) {
                return false;
            } else {
                current = next;
            }
        }
        
        return next->getMarker();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* current = root;
        TrieNode* next;
        for (int i = 0; i < prefix.size(); ++i) {
            next = current->findChild(prefix[i]);
            if (!next) {
                return false;
            } else {
                current = next;
            }
        }
        
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
