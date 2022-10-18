vector<vector<int>> threeSum(vector<int>& nums) {
    
    // sortlamamizin sebebi, zaten complexity yuksek olacagini bildigimiz icin bunu yaparak
    // aslinda teoride olmasa da pratikte daha hizli bir kod yazabilecegiz 2 pointer mantigiyla
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    
    // burada mape atmamiza gerek yok direkt olarak sayilar uzerinden ilerleyebiliriz
    
    int i = 0;
    while ( i < nums.size() ){
        
        // -4 -1 -1 0 1 2
        int target = -nums[i]; // toplamlari 0 olacagindan target - olarak aliyoruz
        int left = i+1;
        int right = (int)nums.size()-1;
        
        // 2 pointer mantigi ile gelen toplamin degerine gore sol veya sag pointeri degistiriyoruz
        while ( left < right ){
            int sum = nums[left] + nums[right];
        
            if ( sum < target ) {
                left++;
            }else if ( sum > target ){
                right--;
            }else{
                vector<int> triplet = {nums[i],nums[left],nums[right]};
                res.push_back(triplet);
                
                // burasi onemli. bizden distinct tripletler istedigi icin
                // eger daha once buldugumuz triplet ile ayni ise surekli artiriyoruz pointeri
                // eger burada bunu yapmasaydik left++ right-- yapmamiz gerekecekti her turlu sonucta farkli
                // 3luleri bulmamiz gerekiyor
                while ( left < right && nums[left] == triplet[1] )    left++;
                while ( left < right && nums[right] == triplet[2] ) right--;
            }
            
            
        }
        // farkli 3luleri istediginden eger i. elemanda ayni ise artiriyoruz. aslinda bu artirmalarla ugrasmamiza gerek
        // yoktu eger direkt olarak basta verilen arrayi unique elementlerden olusan bir arraye cevirseydik.
        // ancak boyle pratikte daha hizli islem yapmis oluyoruz.
        while ( i+1 < nums.size() && nums[i] == nums[i+1] ) i++;
        i++;
        
    }
    
    return res;
}
