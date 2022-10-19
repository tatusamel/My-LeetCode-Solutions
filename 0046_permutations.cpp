class Solution {
public:
    
    void helper( int n, vector<int> vt, vector<int>& nums, vector<vector<int>>& res){
        
        //base case
        if ( n == vt.size() ){
            res.push_back(vt);
            return;
        }
        for ( int i = 0 ; i < nums.size(); i++){

            // if this specific element does already exist we can skip it, or it will be infinite loop
            if ( std::count(vt.begin(), vt.end(), nums[i])) continue;

            // to do backtracking we first add it and after we're done we delete it.
            // eger vt + nums[i] olarak direkt parametre olarak gecebilseydik daha iyi olurdu ama boyle yapiyoruz
            vt.push_back(nums[i]);
            helper(n, vt, nums, res);
            vt.pop_back();
        }
    }
        
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums.size(), vector<int>(), nums, res);
        
        return res;
    }
};
