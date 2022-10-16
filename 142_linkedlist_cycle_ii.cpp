// LEETCODE 142 - Linked List Cycle II


#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;



struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x ) : val(x), next( nullptr ) {}
};

// solution with set which uses extra memory
ListNode* solution1(ListNode* head){
    unordered_set<ListNode*> my_set;
    ListNode* curr = head;
    while ( curr != nullptr ){
        if ( my_set.count(curr) )   return curr;
        my_set.insert(curr);
        curr = curr->next;
    }
    return nullptr;
}
// solution with fast and slow pointer which does not use extra memory

ListNode* solution2(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    
    // oncelikle ilk olarak karsilasacaklari yeri bulmam gerekiyor. Daha sonra ise headden
    // gelerek birer birer ilerleyecegim. sonraki karsilasacaklari node ise o cyclein
    // baslangic noktasi olacaktir.
    
    // slowu kontrol etmeme gerek yok zaten fast her zaman daha onde olacaktir
    while ( fast != nullptr && fast->next != nullptr ){
        slow = slow->next;
        fast = fast->next->next;
        
        // bulduk demektir
        if ( slow == fast ) break;
    }
    
    // while loopundan cikma nedenimiz neymis onu bulalim, koydugumuz break mi yoksa kosullar mi
    if ( fast == nullptr || fast->next == nullptr ){ // cycle yok demektir
        return nullptr; // no cycle
    }
    
    // eger cycle olduguna kesin emin isek
    ListNode* slow2 = head; // headden baslayacak olan pointer
    while ( true ){
        if ( slow2 == slow )    return slow;
        slow = slow->next;
        slow2 = slow2->next;
    }
    
    return nullptr;

}
int main(){
    
    
    return 0;
}
