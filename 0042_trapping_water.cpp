class Solution {
public:
    int trap(vector<int>& height) {
        
        if (height.size() < 3) return 0;
        
        int max_left = 0, max_right = 0;
        
        // buradaki amac en buyuk olani bulmak oncelikle, bunu listeyi bir kez
        // gezerek de yapabiliriz ya da sol ve sag diye iki pointer kullanip 
        // hangisi daha kucuk ise onu artiririz
        
        // max_left ve max_right degerlerimiz ise bize soldan ve sagdan geldigimizdeki 
        // en buyuk degerleri verecektir. bu sayede mesela ondan kucuk bir deger gorursek ona 
        // direkt olarak su koyabiliriz
        
        // 0 1 0 2 1 0 1 3 2 1 2 1
        
        int left = 0, right = height.size()-1;
        int res = 0;
        while ( left <= right ) {
            
            // hangisi kucuk ise onu bir ilerletiyoruz en buyuge ulasmak icin
            if ( height[left] <= height[right] ){ //left++
                
                if ( height[left] > max_left ) max_left = height[left];
                else res += max_left - height[left];
                left++;
            }else{
                if ( height[right] > max_right ) max_right = height[right];
                else res += max_right - height[right];
                right--;
            }
        }
        return res;
    }
};
