class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // buradaki mantik aslinda sunu ogretiyor bize : sayilari siralamaya gerek kalmadan da 
        // yani O(nlogn)lik bi islem yapmadan da sorgulayabiliyoruz cunku bizden istenen ard arda olmasi
        // biz de sayinin 1 eksigini ve fazlasini bulup sette sorgulatabiliriz. boylece siralamaya gerek kalmaz

        // time complexity -> O(n), space complexity -> O(n) as well

        unordered_set<int> st;
        for(int x : nums) st.insert(x); // to query if we have a number in constant time 

        // amacimiz sayilari gezerken ne kadar sola ve saga acilaibliriz diye bakmak
        // ancak baktiktan sonra da o baktigimiz sayilarin hepsini silebiliriz cunku 
        // bunlar ardisik oldugundan, diger sayilardan birinden baslasaydik bile ayni sonucu alirdik
        int best = 0;
        for ( int x : nums ) {
            
            if ( st.find(x) == st.end() ) continue;

            int lo = x-1;
            int hi = x+1;
            while ( st.find(lo) != st.end() ) {
                st.erase(lo);
                lo--;
            }   
            while ( st.find(hi) != st.end() )  {
                st.erase(hi);
                hi++;
            }
            st.erase(x);

            best = max(best, hi-lo-1);

        }

        return best;

    }
};
