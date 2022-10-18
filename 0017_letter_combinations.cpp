class Solution {
public:
    
    // buradaki asil mantik bize verilen string ( 234 ) ü tek tek gezerken önce 2nin olanlarını 
    // bir arraye atmak ( ya da arraye önce boş bir string koyup onunla birleştirmek çünkü ileride)
    // hepsini birleştirmemiz gerekecek zaten. 
    // Daha sonra ise 3ün harflerini daha önce arrayde bulunan tüm itemlerle birleştirmek...
    // temp arrayi mantığını da kullanıyoruz burada. Çok güzel bir çözüm
    
    // 2 3 4
    vector<string> letterCombinations(string digits) {
        
        vector<string> letters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        vector<string> result = {""};
        
        // "234"
        for ( char ch : digits ){
            // ch = '2'
            
            // we should create a temporary array to store the new created items.
            vector<string> temp = {};
            // now let's find what 2 represents from the letters array and traverse thru it
            for ( char letter : letters[ch-'0'] ){
                // and we should combine every letter with the items in which the result array
                
                for ( string r : result ){
                    temp.push_back( r + letter );
                }
            }
            // now swap those two arrays.
            result.swap(temp);
        }
        return result;
        
    }
        
};
