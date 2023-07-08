#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;
struct Node{
    int Data ;
    Node *next ;
    Node(int Data) : Data(Data) {}
};

class Linked_List{

private:
    Node *head ;
    Node *tail  ;
    int length  ;
// Move the value to the front of the linked list in order to make it easier to find
// in the future quickly
void improve_search( int value ){

for( Node *cur= head , *prv =nullptr ; cur != nullptr ; prv= cur , cur = cur->next ){
   if(cur->Data == value )
      swap(cur->Data , prv->Data);
}
}

public:

Linked_List(){
        cout<<"Start work \n ";
        head = nullptr ;
        tail = nullptr ;
        length = 0 ;
    }

~Linked_List() {
    cout<<"\n End work \n";
    Node *item = head;

    while (item != nullptr) {
        Node *next_item = item->next;
        delete item;
        item = next_item;
    }
    head = tail = nullptr;
    length = 0 ;
}

void insert_front( int value){

    Node *item = new Node(value) ;
    length++ ;

    if( length == 1 )
      head = tail = item ;
     else{
         item->next= head ;
         head = item ;
     }
}

void print(){

  for( Node * cur = head ; cur ; cur= cur->next)
    cout<<cur->Data<<" " ;
   }

void insert_end( int value ){

    Node * item = new Node(value) ;

     length++ ;

  if( head == nullptr){
     head=tail= item ;
  }

  else{
      tail->next = item ;
      tail = item ;
  }

}

// This function retrieves the nth node
void  get_nth( int n ){

    if( length < n)
      cout<<"This value is False \n" ;

     Node *cur = head ;

     for( int i = 1; i < n ; i++)
        cur = cur->next ;

    cout<<"\n"<<cur->Data;
}

// take value of node and return the index of this node
int search( int value ){

    int index = 1 ;
    for( Node *cur = head ; cur ; cur = cur->next  , index++){
         if( cur->Data == value ){
           improve_search(value) ;         // hift left of this node
           return index ;
         }
    }
    return -1 ;
}

void delete_front(){

if( head == nullptr)
      return ;

    Node *item = head ;
    head = head->next ;
    delete item ;
     length-- ;

    if(length == 0 ){
        head= tail = nullptr ;
    }
}

void  delete_last(){

       length-- ;

   if(  length == 0){
        delete tail ;
        head = tail = nullptr ;
    }

  else {

        Node* rev = nullptr;
        Node* last = head;
        while (last->next != nullptr) {
            rev = last;
            last = last->next;
        }
        delete last;
        rev->next = nullptr;
        tail = rev;
    }

}

void delete_nth_node( int value){
    length-- ;

  Node *prv = nullptr ;
  Node *curr = head ;

  while(curr->Data != value ){
      prv = curr ;
      curr = curr->next ;
  }
   prv->next = prv->next->next ;
   // or
   // prv->next = curr->next ;
   delete curr ;
}

void Delete_Node( int value ){

    if( head == nullptr)
    return ;

    else if( head->Data == value )
      delete_front();

    else if( tail->Data == value )
      delete_last();
     else
        delete_nth_node(value) ;

}

// Returns the value of the nth node from the end of the list
// Returns -1 if n is out of range or the list is empty
int Get_nth_back( int n ){

    if( n > length || 0 >= n)
        return -1 ;

       Node *temp =head ;
       int index = 1 ;

       while( index !=  (length -n +1 ) ){
            temp = temp->next ;
            index++ ;
       }
      return temp->Data ;

}
//  compares the data values of each node in the current list with the
//corresponding nodes in another linked list others
bool is_same( const Linked_List & others ){

    if( length != others.length )
      return false ;

     Node* others_h = others.head ;

  for( Node* cur = head ; cur ; cur =cur->next ){
       if( cur->Data != others_h->Data ){
          return false ;
       }
         others_h =others_h->next ;
  }
  return true;
}


void Delete_With_Key( int value){
   Delete_Node(value) ;

}

void swap_each_pair(){
    Node *cur = head ;
    while( cur!=nullptr && cur->next != nullptr ){
    swap( cur->Data , cur->next->Data ) ;
     cur = cur->next->next ;
    }
}

void Reverse_list_node(){
    vector<int> v ;
    Node * cur =head ;

    while( cur != nullptr){
        v.push_back(cur->Data) ;
         cur = cur->next ;
    }
      int index = v.size()-1 ;
      cur = head ;

      while( cur != nullptr){
        cur->Data = v[index] ;
         cur = cur->next ;
         index-- ;
      }
}

void insert_to_the_sorted( int value ){

     if(head->Data >= value || head == nullptr )
     insert_front(value) ;

    else if( tail->Data <= value)
    insert_end( value) ;

    else{

        Node *prv = head ;
        Node *item = head->next ;

         Node * cur = new Node(value) ;
        while( item->Data < cur->Data ){
            prv = item ;
            item = item->next ;
        }

        cur->next = item ;
        prv->next = cur ;

        length++ ;
    }
}

Node * reverse(){
      if(head == nullptr) return nullptr ;

      else if( head->next == nullptr) return nullptr ;

      Node*rev = head ;
      Node *cur = head->next ;
      while( cur->next != nullptr ){
            rev = cur ;
            cur = cur->next ;
      }
   return rev ;
}

void Left_Rotate(){
      if( length <= 1)
        return ;
      else if( length == 2 ){
       swap_head_and_tail() ;
       return ;
      }
else{
      Node *second_last =reverse() ;
      tail->next = head ;
      second_last->next = nullptr ;
      head = tail ;
      tail = second_last ;
}

}
void swap_head_and_tail(){
if( length <= 1 )
    return ;

   if( length == 2 ){
         swap(head , tail ) ;
         tail->next= nullptr ;
         head->next= tail ;
         return ;
   }

 else{
       Node* prv = reverse();

       tail->next = head->next ;
       prv->next = head ;
       head->next= nullptr ;
       Node * swa = head ;
       head =tail ;
       tail = swa ;
 }

}

void delete_next_node(Node * prv){

      if( prv->next == nullptr){
        delete_last();
        return ;
      }
   else{
         Node *del_nod  ;
         del_nod = prv->next ;
         prv->next= del_nod->next ;
         delete del_nod ;
         length-- ;
   }
}
// delete all Repeating the number EX 1 2 1 1 3  --> print 1 2 3
void delete_duplicates(){

   if( length <= 1)
      return ;
for( Node * cur1 = head ; cur1 != nullptr ; cur1= cur1->next ){

   for(Node * cur2 = cur1->next , *prv = cur1 ; cur2 ; ){

         if( cur2->Data == cur1->Data ){
               delete_next_node(prv) ;
               cur2= prv->next ;
         }
         else {
               prv = cur2 ;
               cur2 = cur2->next ;
         }
   }
}
}
// give list of numbers (not sorted) and key : delete the last node for this key
void delete_last_occurance( int key ){
      bool is_found = false ;
      Node  *delete_last_node = nullptr ;

   for(Node * cur = head , *prv = nullptr ; cur ; prv = cur , cur =cur->next ){

       if(cur->Data == key){
          is_found = true ;
          delete_last_node = prv ;
         }
     }
   if( is_found == true  ){

         if( delete_last_node == nullptr)
            delete_front();
         else
          delete_next_node(delete_last_node) ;

   }
}

// give list of numbers (not sorted) and key : move all node for this key to the end
void Move_to_back( int key){
      if(length <= 1)
      return ;

      int x= length ;
 for( Node * cur = head , *prv =nullptr ; x !=0 ;  x--){
       if( cur->Data == key){

         if(prv == nullptr){
             delete_front();
             insert_end(key);
             cur =head ;
             }
            else{
             delete_next_node(prv) ;
                  insert_end(key) ;
                  cur =prv ;
            }

       }
       else{
            prv = cur , cur =cur->next ;
       }
 }
}
} ;

int main()
{
    Linked_List list ;


    list.insert_end(1);
    list.insert_end(4);
    list.insert_end(4);
    list.insert_end(4);
    list.insert_end(9);
    list.insert_end(21);
    list.insert_end(11);
    list.insert_end(33);
    list.print();
    cout<<"\n";
    list. Move_to_back(4);
    cout<<"\n";
    list.delete_last_occurance(21) ;

   list.delete_duplicates();
   list.insert_to_the_sorted(3) ;


    return 0;
}
