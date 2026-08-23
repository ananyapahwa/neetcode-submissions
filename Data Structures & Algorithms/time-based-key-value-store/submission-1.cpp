class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int start = 0;
        int end = mp[key].size()-1;
        int ans = -1; 
        while(start <= end){
            int mid = start + (end-start)/2;

            if(mp[key][mid].first <= timestamp){
                ans = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }

        }
        if (ans == -1)
            return "";
        return mp[key][ans].second;
    }
};
