class Solution {
public:
    
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res;
        
        // sola,saga   veya  yukari asagi kac adim gidecegimizi gosteriyor
        vector<int> numOfSteps{m,n-1};
        
        int x = 0, y = -1;// initial values;
        
        int indOfDir = 0;
        
        // hala gidecek yolum varsa
        while (numOfSteps[indOfDir%2]) {
            
            for ( int i = 0; i < numOfSteps[indOfDir%2]; i++){
                x += dirs[indOfDir].first; 
                y += dirs[indOfDir].second;
                
                res.push_back({matrix[x][y]});
            }
            numOfSteps[indOfDir%2]--;
            indOfDir = (indOfDir + 1) % 4;
        }
        
        return res;
        
    }
};
