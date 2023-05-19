#include <iostream>
#include <cassert>

using namespace std;
 class Vector{

 private :
     int *arr = nullptr ;
     int Size {0} ;
     int capacity {} ;

void extra_capacity(){
         capacity = capacity*2 ;
    cout<<"We make extra positions in the array \n" ;
    int *arr2 = new int[capacity]{} ;
    for( int i = 0 ; i < Size ; i++ ){
        arr2[i]= arr[i] ;
    }
        swap(arr2 , arr) ;
        delete[] arr2 ;

}

 public :
Vector(int Size) : Size(Size) {
        if( Size < 0)
            Size = 1 ;
            capacity = Size ;
       arr = new int[capacity]{} ;
}

~Vector(){
         delete[] arr ;
         arr = nullptr ;
}
void insert( int index , int value ){
    assert(index <Size && index >= 0) ;

    if( Size == capacity )
        extra_capacity() ;
  for( int i = Size-1 ; i >= index ; i--)
      arr[i+1] = arr[i] ;

      arr[index] = value ;
      ++Size ;

}
int push_back(int value){
       if( capacity == Size)
      extra_capacity();

      arr[Size++] = value ;

}
 void Print(){
  for( int i = 0  ; i < Size ; i++ )
       cout<<arr[i]<<" " ;
  cout<<"\n";
 }

int Find(int value){
       for(int index = 0 ; index < Size ; index++)
       if( arr[index] == value )
        return index;

      return -1 ;
}
int get(int index){
      assert( 0 <= index && Size > index) ;
      return arr[index] ;
}

int get_front(){
      return arr[0];
}
int get_back(){
    return arr[Size-1] ;
}

void Set(int index , int value) {
    assert( 0 <= index && Size > index) ;
    arr[index] =value ;
}

void Right_Rotation(){
  int end = arr[Size-1] ;
  for( int i = Size-1 ; i >0  ; i-- ){
      arr[i] = arr[i-1] ;
  }
  arr[0] =end ;
}

void Right_Rotation_WithSteps(int steps ){
 steps = steps %  Size;

   while(steps--){
   Right_Rotation();

   }
}

void Left_Rotation(){
 int start = arr[0] ;
 for( int i =0 ; i < Size-1 ; i++ )
    arr[i] = arr[i+1] ;

 arr[Size-1] = start ;
}

void Delete_position( int index ){
    assert( index >= 0 && index < Size );
for( int i = index ; i < Size-1 ; i++ )
    arr[i] = arr[i+1] ;

 Size-- ;

}


 };

int main()
{
    Vector v(10) ;

   cout<< v.get(8)<<"\n";

    v.Set(0, 40);

    for(int i = 0 ;i < 10 ; i++)
        v.Set(i , i);

    cout<<v.get_back()<<"\n";
    cout<<v.get_front()<<"\n";

     v.push_back(100) ;
     v.push_back(10) ;
     v.push_back(567) ;
     v.push_back(428) ;

     cout<<v.Find(7)<<"\n" ;
     v.insert(5 , 1000) ;
     cout<< v.get(5)<<"\n";
     v.Print();

     v.insert(10 , 11111 ) ;
      v.Print();
      v.Right_Rotation_WithSteps(2);
      v.Print();
      v.Delete_position(14);
       v.Print();

      v.Right_Rotation();
      v.Print();

      v.Left_Rotation() ;
       v.Print();

    return 0;
}
