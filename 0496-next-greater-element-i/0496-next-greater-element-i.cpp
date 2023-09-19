class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector<int> ans(nums1.size(),-1 );
       unordered_map<int,int> umap;
       stack<int> st;
       for(int i =0 ; i < nums2.size() ;i++){
            int ele = nums2[i];
           while(!st.empty() && ele > st.top()){
               umap[st.top()] = ele;
               st.pop();
           }
           st.push(ele);
        }

        for(int i = 0 ; i<nums1.size() ; i++){

            if(umap.count(nums1[i]))
              ans[i] = umap[nums1[i]];
        }
        return ans;
    }
};