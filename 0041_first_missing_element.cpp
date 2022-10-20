class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // bir cok farkli cozumu var bu sorunun;
        // siralayip cozersek  time => O(nlogn) space => O(1)
        // map kullanip cozersek time => O(n) space => O(n)
        // swap yontemi ile ilersek time => O(n) space => (1)
        
        // swap yonteminde ise listeyi iterate ediyoruz, ve bakiyoruz eger i. eleman
        // olmasi gereken yerde mi diye degilse onu swap ediyoruz. artik o eleman olmasi
        // gereken yerde ancak ilerlemeden once swap ettigimiz diger eleman dogru yerde mi 
        // diye de sormamiz lazim yani bunu surekli sorgulamamiz gerekiyor bu yuzden de while
        // kullanarak yapabiliriz. sonra ise kontrol asamasi tabi ki. guzel bir yontem
        
        // -3 -1 5 5 6 0 2 3 4 1
        // -3 -1 6 5 5 0 2 3 4 1
        // -3 -1 0 5 5 6 2 3 4 1
        // -3 2 0 5 5 6 -1 3 4 1
        // -3 2 3 5 5 6 -1 0 4 1
        // -3 2 3 4 5 6 -1 0 5 1
        // 1 2 3 4 5 6 -1 0 5 -3
        for ( int i = 0; i < nums.size(); i++){
            // check the borders and the condition
            while ( nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) {
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        for ( int i = 0; i < nums.size(); i++){
            if ( nums[i] != i+1 )   return i+1;
        }
        return nums.size()+1;
    }
};
