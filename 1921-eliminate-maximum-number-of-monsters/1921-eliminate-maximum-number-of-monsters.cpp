class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int>  v;
        for(int i = 0 ; i < dist.size() ;i++){
            v.push_back(ceil(static_cast<double>(dist[i]) / speed[i]));

        }
        sort(v.begin(), v.end());
        int res {0};

        for(int i = 0 ; i < v.size(); i++){
            if(i >= v[i]) {return res;}
            res++;
        }
        return res;

    }
};