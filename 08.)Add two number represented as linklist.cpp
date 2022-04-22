
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(Node* head)
    {
    if (head == NULL || head->next == NULL)
        return head;
 
    /* reverse the rest list and put
        the first element at the end */
    Node* rest = reverse(head->next);
    head->next->next = head;
 
    head->next = NULL;
 
    /* fix the head pointer */
    return rest;
    }   
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node *dummy=new Node(0);
        Node *temp=dummy;
        int carry=0;
        Node *rev=NULL;
      Node *fir= reverse(first);
      Node *sec=reverse(second);
        // while(fir!=NULL){
        // cout<<fir->data<<" ";
        // fir=fir->next;
        // }
        // cout<<endl;
        // while(sec!=NULL){
        // cout<<sec->data<<" ";
        // sec=sec->next;
        // }
        // cout<<endl;
       
        while(fir!=NULL||sec!=NULL||carry){
            int sum=0;
            if(fir!=NULL){
                sum=sum+fir->data;
                fir=fir->next;
            }
            if(sec!=NULL){
                sum=sum+sec->data;
                sec=sec->next;
            }
            sum=sum+carry;
            carry=sum/10;
            Node *node=new Node(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        if(dummy==NULL)
        return dummy;
        Node *t=dummy;
        dummy=dummy->next;
        delete t;
        Node *dum=reverse(dummy);
       
        return dum;
    }
};
