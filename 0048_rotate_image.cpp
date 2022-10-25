class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        // UNUTMA! Eger sadece in-place degistirmeni istiyorlarsa yani SWAP 
        // yaparak o zaman yuksek ihtimalle simetrik olarak SWAP yapman gerekiyor
        // yoksa diger degerleri kaybedebilirsin bu yuzden simetrik olarak swap yontemlerini
        // aramaya calis hep
        
        
        
        // CLOCKWISE ROTATE
        // 1 2 3      7 8 9      7 4 1
        // 4 5 6  ==> 4 5 6  ==> 8 5 2
        // 7 8 9      1 2 3      9 6 3
        // eger verilen matrixi reverse edersek ve sonra da simetrik swap edersek sonuc cikar
        for ( int i = 0; i < n; i++){
            
            for ( int j = i+1; j < n; j++){
                swap( matrix[i][j], matrix[j][i]);
            }
            
        }
        
        // UNCLOCKWISE ROTATE
        // 1 2 3    3 6 9 
        // 4 5 6 => 2 5 8
        // 7 8 9    1 4 7
        // ne zaman simetrik swap yaptiktan sonra bu hale gelir diye dusun yani mesela
        // swap yapilmadan onceki halini bul son arrayden o da su olur
        // 3 2 1
        // 6 5 4
        // 9 8 7
        // demek ki bizim arrayi bu hale getirmemiz lazim once bu yuzden de her arrayi kendi
        // icinde reverse etmemiz gerekiyor demek
        for ( int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[j].end());
        }
        // now swap
        for ( int i =0; i < n; i++){
            for (int j = 0; j < n; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        
       
        
    
    }
};
