class TimeMap {
private:
  unordered_map<string,vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        const vector<pair<int,string>>& values = mp[key];
        /*
        This modification avoids unnecessary copying of the vector associated with 
        the key by using a reference, which can significantly improve the
        performance, especially when dealing with large datasets.
        */
        int l = 0, r = values.size()-1;
        while(l <= r){
            int mid = l  + (r-l)/2;
            if( values[mid].first <= timestamp){
               res  = values[mid].second;
               l = mid + 1;
            }else{
              r = mid - 1; 
            }

        }
        return res;
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */