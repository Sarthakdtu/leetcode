class LRUCache {
public:
    list<int> q;
    unordered_map<int, list<int>::iterator> m;
    unordered_map<int, int> cache;
    int size;
    int maxs;
    
    LRUCache(int capacity) {
        this->size = 0;
        this->maxs = capacity;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            int val = cache[key];
            use(key);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        use(key);
        cache[key] = value;
    }
    private:
    
    void use(int key){
        if(m.find(key) != m.end()){
            q.erase(m[key]);
            m.erase(key);
            // cache.erase(key);
            size--;
        }
        else{
            if(size==maxs){
                int old_key = q.back();
               m.erase(old_key);
               q.pop_back();
                cache.erase(old_key);
                size--;
            }
        }
        
        size++;
        q.push_front(key);
        m[key] = q.begin(); 
    }
};
​
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
