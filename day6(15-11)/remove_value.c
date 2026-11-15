struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode* pre=NULL;
    struct ListNode* cur=head;
    while(cur!=NULL){
        if(cur->val==val){
            if(pre==NULL)
            head=cur->next;
            else
            pre->next=cur->next;
        }
        else
        pre=cur;
        cur=cur->next;
    }
    return head;
}
