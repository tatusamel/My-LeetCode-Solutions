// LEETCODE 3 - Longest Substring Without Repeating Characters


#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;



int def(string s){
    
    unordered_map<char,int> mp;
    int left = 0;
    int right = 0;
    int best = 0;
    
    
    // Mantık çok basit burada. Her yeni gelen karakter mapimizde var mı diye bakıyoruz. Eğer yoksa
    // karater ve pozisyonu şeklinde mape ekliyoruz eğer var ise best değerimizi hesaplayıp yolumuza devam ediyoruz.
    while ( right < s.size() ){
        char ch = s[right];
        // eger mapte yeni gelen karakter var ise
        if ( !mp.count(ch) ){
            mp[ch] = right;
        }else{
            best = max(best, right - left); // best hesaplarken +1 eklemeyiz çünkü yeni gelen karakteri dahil edemeyiz aslında
            left = max(left, mp[ch]+1 ); // lefti ise yeni gelen karekterin bir önceki yerinin bir fazlasına eşitliyoruz
                                        // ama asla geri gidemez left değeri bu yüzden max ile kontrol ediyoruz
            mp[ch] = right;
        }
        right++;
    }
    best = max(best, right-left); // hiç bir şekilde else durumuna girmezse diye
    return best;
    
}
int main(){
    string s;
    cin >> s;
    cout << def(s) << endl;
    
    return 0;
}
