class Solution {
public:
    
    
    void helperMerge(ListNode* tail, vector<ListNode*>& lists){
      
      // mantik basit en kucuk nodeu bulmamiz gerekiyor once bu yuzden mn index degerini tutuyorum.
      // nullptr kontrollerini de yapmayi unutma tabi ki
        
        int mn = INT_MAX;
        int mn_index = -1;
        // [1,4,5] , [1,3,4], [2,6]

        bool still_have = false;
        for ( int i = 0; i < lists.size(); i++ ){
            
            if ( lists[i] == nullptr )  continue;
            
            still_have = true;
            if ( mn > lists[i]->val ) {
                mn = lists[i]->val;
                mn_index = i;
            }
        }
        if ( !still_have )  return;
        
        // bu ilk nodeunu ayarlamak icin
        if ( tail == nullptr ){
            tail = lists[mn_index];
        }else{
            tail->next = lists[mn_index];
            tail = tail->next;
        }
        
        // daha sonra kullandigimiz elemani cikariyoruz ve tekrar ayni fonksiyonu cagiriyoruz
        lists[mn_index] = lists[mn_index]->next;
        helperMerge(tail, lists);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

      
        // dummy node yöntemi çok güzel bir yöntem. Böylece tailı ilerletsem bile onun her zaman izini sürebiliyorum.
        // bu tarz sorularda direkt dummy node kullanabilirsin eğer headı return etmek istediğimizde de direkt dummy.next yapıyoruz.
        ListNode dummy(0);
        ListNode* tail = &dummy;
        helperMerge(tail, lists);
        
        return dummy.next;
    }
};
