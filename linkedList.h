template <class T>
class LinkedList
{
    struct node
    {
        T item;
        node* next;
    };
    int size;
    node* head;
    node* tail;
    public:
    LinkedList()
    {
        head=tail=NULL;
        size=0;
    }
    // insert the item in the end
    void insert(T x)
    {
        node* p=new node;
        p->item=x;
        p->next=NULL;
        if(!head)
        {
            head=p;
            tail=p;
        }else
        {
            tail->next=p;
            tail=p;
        }
        size++;
    }
    void remove(int index)
    {
        node*temp=head;
        // spacial case when there is only one item or the item on the beginning of the list
        if(!index)
        {
            head=temp->next;
            delete temp;
        }else
        {
           //iterate until you reche the index of the item
           for(int i=0; i<index-1; i++)
           {
                temp=temp->next;
           }
           node*temp2=temp->next;
           temp->next=temp->next->next;
           delete temp2;
        }
        size--;
    }
    bool empty()
    {
        return size==0;
    }
    bool full()
    {
        try
        {
           node*temp=new node;
           delete temp;
           return 0;
        }
        catch(bad_alloc exception)
        {
            return 1;
        }   
    }
    int getSize()
    {
        return size;
    }
    void clear()
    {
        node*temp=head;
        while(head)
        {
            temp=head;
            head=head->next;
            delete temp;
        }
        size=0;
    }
    // return the item at this position
    T retrive(int index)
    {
        node*temp=head;
        for(int i=0; i<index; i++)
            temp=temp->next;
        return temp->item;
    }
    // take index,new value 
    // update the item
    void update(int index,T x)
    {
        node*temp=head;
        for(int i=0; i<index; i++)
            temp=temp->next;
        temp->item=x;
    }
};