class LRUCache{
    private:
    
    int capacity;
    unordered_map<int, list<pair<int,int>>::iterator> keymap;
    list<pair<int,int>> cache;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = keymap.find(key);
        if (it == keymap.end()) {
            return -1;
        }
        
        // Push the pair the beginning of the list
        cache.push_front(*(it->second));
        
        // Remove by iterator (remove from original position)
        cache.erase(it->second);
        
        it->second = cache.begin();
        
        return it->second->second;
    }
    
    void set(int key, int value) {
        auto it = keymap.find(key);
        if (it == keymap.end()) { // insert new
            while (keymap.size() >= capacity) {
                keymap.erase(cache.crbegin()->first);
                cache.pop_back();
            }
        } else {
            // Remove by iterator
            cache.erase(it->second);
        }
        
        cache.push_front(make_pair(key,value));
        keymap[key] = cache.begin();
    }
};