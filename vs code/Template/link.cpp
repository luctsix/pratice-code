#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct linklist{
    Node* head;
    int size;
    //int capacity;
}LINKLIST;

template<class T1, class T2>
class Linklist{
    public:
        Linklist(){
            list = new T1;
            list->head->next = NULL;
            list->head->data = 0;
            list->size = 0;
        }
        void Insert_Tail(int data)
        {
            T2 *newnode = new T2;
            newnode->data = data;
            newnode->next = NULL;
            T2* tmp = list->head->next;
            while(tmp->next!=NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = newnode;
            list->size++;
        }
        void traverse(){
            T2* tmp = list->head->next;
            while(tmp != NULL)
            {
                cout<<tmp->data<<endl;
            }
        }
        int getSize(){return list->size;}
    private:
        T1 *list;
};

int main(){
    Linklist<LINKLIST, Node> *list = new Linklist<LINKLIST, Node>;
    list->Insert_Tail(1);
    list->traverse();
    cout<<list->getSize()<<endl;
    return 0;
}