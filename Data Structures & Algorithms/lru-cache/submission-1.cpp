class LRUCache {
public:
    unordered_map<int, int> items;
    unordered_map<int, int> count;
    queue<int> q;
    int capacity;
    int num;

    LRUCache(int capacity) {
        this->capacity = capacity;
        num = 0;
    }

    void delete_top(){
        
        while(true){
            int temp = q.front();
            q.pop();
            count[temp]--;

            if(count[temp] == 0){
                count.erase(temp);
                break;
            }
        }
        num--;
    }
    
    int get(int key) {
        if(count.find(key) == count.end())
            return -1;

        q.push(key);
        count[key]++;
        return items[key];
    }
    
    void put(int key, int value) {

        if(count.find(key) == count.end()){
            count[key] = 1;
            num++;
        }
        
        else
            count[key]++;

        items[key] = value;
        q.push(key);
        
        if(num > capacity)
            delete_top();
    }
};
