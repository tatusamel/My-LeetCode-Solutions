class Solution {
public:
    
    // we need to do backtracking so we will not return at the end
    // we'll just modify the result array
    void helper(int open, int closed, int n, const string& str, vector<string>& res){
        
        // base case
        if ( str.size() == 2 * n ){
            res.push_back(str);
            return;
        }
        // if number of open bracket is less than n, we can add more open
        if ( open < n ) helper(open+1, closed, n, str+'(' , res);
        
        // if number of closed bracket is less than open bracket, we can add more closed
        if ( closed < open ) helper(open, closed+1, n, str+')', res);
        
        // make sure to not return inside those if statements because we need to do backtracking
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        helper(0,0,n,"",res);
        return res;
    }
    
};
