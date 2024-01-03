class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(bank.size() < 2)
            return 0;
            
        int res = 0 , laser = 0, prvLaser = 0 ;
        for(int i = 0 ; i < bank.size() ; i++){
            for(int j = 0 ; j < bank[i].size() ; j++){
                if(bank[i][j] == '1') laser++;
            }
            if(laser == 0) continue;
            res += (prvLaser * laser);
            prvLaser = laser;
            laser = 0;
        }
        return res;
    }
};