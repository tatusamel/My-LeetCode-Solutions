class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // 4 5 6 7 0 1 2
        
        int l = 0; int r = nums.size()-1;
        int first = nums[0];
        
        while ( l <= r ){
            int mid = l + (r-l)/2;
            
            if ( nums[mid] == target ) return mid;
            
            bool am_big = nums[mid] >= first;
            bool target_big = target >= first;
            
            // if I am (middle element) and target are both bigger or smaller than
            // the first element 
            if ( am_big == target_big ) {
                // bu if iki durumu da dogru sagliyor o yuzden 0 0 ve 1 1 icin kullanabildik
                // eger aklina gelmez ise bir ornek yap ve kendine sorular sor eger target kucuk ise
                // ve mid degerim buyuk ise nereye giderim gibi 
                if ( target < nums[mid] ) {
                    r = mid-1;
                }else{
                    l = mid+1;
                }
             }
            else if ( am_big ) {
                // ben buyuksem ve target kucuk ise sag tarafa gidecektir
                l = mid + 1;
            }
            else if ( target_big ){
                // ben kucuksem ve target buyuk ise sol tarafa gidecektir
                r = mid - 1;
                
            }
        }
        return -1;
    }
};
