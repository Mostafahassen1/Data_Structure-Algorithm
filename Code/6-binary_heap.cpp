
#include <iostream>

using namespace std;
class MinHeap{
  private :

  int *array{} ;
  int size{};
  int capacity {10} ;

  bool _isEmpty(){
     if(size == 0 )
      return true ;
     else
      return false ;
 }

 int parent( int pos_child ) {
     if(pos_child % 2 == 0)
       return (pos_child-2) /2 ;
      else
      return (pos_child-1) /2 ;
 }
 void heapify_up( int pos_child ){

     int pos_parent = parent(pos_child) ;

     if( pos_child ==0 || array[pos_parent] <= array[pos_child])
       return ;

       swap( array[pos_parent] , array[pos_child] ) ;

     heapify_up(pos_parent) ;


 }

 int Left( int root){
     int left =(root *2)+1 ;
     if(left > size)
     return -1 ;
     else
     return left ;
 }
 int Right( int root){
     int right =(root *2)+2 ;
     if(right > size)
     return -1 ;
     else
     return right ;
 }

  public :

   MinHeap(){
      array = new int[capacity] {} ;
      int size = 0 ;
  }
  ~MinHeap(){
      delete[] array ;
      array =nullptr ;
      size = 0 ;
  }

 void isEmpty(){
     bool result = _isEmpty() ;
     if(result == true )
      cout<<"The heap is empty now\n";
      else
      cout<<"The heap is not empty\n";
 }

 void push( int element ){
     if( size+1 >= capacity ){
         cout<<"The heap is full now , you can't add --> "<< element<<" .\n";
         return ;
     }
       array[size] = element ;
       heapify_up( size ) ;
       size++ ;
 }
 void pop(){
     if(_isEmpty() )
       return ;
     if(size == 1) // there only one node in the Heap ;
        size-- ;
    else{
        int val = array[--size] ;
        array[0] = val ;
        heapify_down(0) ;
    }
     return ;
 }

 void heapify_down(int cur_parent ){

     int child_pos = Left(cur_parent) ;
     int Rit = Right(cur_parent) ;

     if(child_pos == -1 || Rit== -1 )
        return ;

    if(array[child_pos] > array[Rit] )
    child_pos= Rit ;

    if( array[cur_parent] >  array[child_pos] ){
        swap(array[cur_parent] , array[child_pos] ) ;
         heapify_down(child_pos);
    }
    return ;

 }

};
int main()
{
    MinHeap heap ;
    heap.push(2) ;
     heap.push(4) ;
      heap.push(3) ;
       heap.push(2) ;
        heap.push(8) ;
         heap.push(9) ;
          heap.push(4) ;
           heap.push(0) ;
            heap.push(22) ;
             heap.push(44) ;

    return 0;
}
