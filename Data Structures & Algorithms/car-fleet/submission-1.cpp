class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for(int i=0; i<n; i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end() , [](auto &a, auto& b){
            return a.first > b.first;
        });

        // sort(cars.begin(), cars.end());


        vector<double> time;
        for(auto c: cars){
            int p = c.first;
            int s = c.second;

            time.push_back((double)(target-p)/s);
        }

        stack<double> st;
        for(auto t: time){
            //first element pushed
            if(st.empty()){
                st.push(t);
                continue;
            }

            //if time is greater it joins the fleet
            if(st.top() < t) st.push(t);


        }


    return st.size();

    }
};
