class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
         
        vector<pair<int,int>> diffProfit ; 
        for( int i  = 0  ; i< diff.size() ;i++){
            diffProfit.push_back({diff[i],profit[i]});
        }
        sort(diffProfit.begin(), diffProfit.end());
        sort(worker.begin(), worker.end());

        int sum {0}, subSum {0} , j {0};

        for( int i = 0 ; i < worker.size() ; i++){
           
            
            for( ; j < diffProfit.size() && worker[i] >= diffProfit[j].first ; j++)
              subSum = max(subSum, diffProfit[j].second);
            sum += subSum;
        }
        return sum; 
    }
};