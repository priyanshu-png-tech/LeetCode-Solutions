class LRUCache {
public:
    list<int>dll;
    unordered_map<int ,pair<list<int>::iterator , int>>mp;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    void markRecentlyUsed(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
        return;
    }

    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }

        markRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second = value;
            markRecentlyUsed(key);
            return;
        }
        else{
            dll.push_front(key);
            mp[key].first = dll.begin();
            mp[key].second = value;
            n--;
        }
        if(n<0){
            int key_to_be_del = dll.back();
            dll.pop_back();
            mp.erase(key_to_be_del);
            n++;
            return;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */