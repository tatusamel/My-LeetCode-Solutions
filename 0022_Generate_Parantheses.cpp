class Solution {
public:
    
    void helper(int open, int closed, int n, const string& str, vector<string>& res) {
        
        if ( str.size() == 2*n ) {
            res.push_back(str);
            return;
        }
        if ( open < n ) helper(open+1, closed, n, str+"(", res);
        if ( closed < open )    helper(open, closed+1, n , str+')', res);
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        helper(0,0,n,"",res);
        return res;
    }
    
};
