/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // sondan n. elemani sil dedigi icin burada slow fast pointerlari kullanip araya n mesafe 
        // koyup daha sonra da fast null olana kadar ikisini ilerletebiliriz boylece slow tam olarak
        // n. nodea gelmis olacaktir. n.nodun bi oncesine gelmesini istiyorsak da fast->next null oluncaya kadar ilerletebiliriz
        while ( n-- && fast != nullptr ){
            fast = fast->next;
        }
        
        // burada headi silme durumunu incelememiz gerekiyor. eger fast null olmus ise n ilerletmeden sonra
      // bize aslinda headi sil demek istiyor 
        if ( fast == nullptr ) { // delete the head itself
            ListNode* temp = head->next;
            delete head; // memory leak olmasin diye siliyoruz burada
            return temp;
        }
        // 1 2 3 4 5
        //     s   f
        while ( fast->next != nullptr ) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
        
        
    }
};
