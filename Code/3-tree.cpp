
#include <iostream>
#include<algorithm>
#include<vector>
#include <cassert>
#include <cmath>
#include <queue>
#include <deque>
#include <string>
#include<deque>
using namespace std;
 struct TreeNode{
     int val {} ;
     TreeNode *left {} ;
     TreeNode *right {} ;
     TreeNode( int value) : val(value) {

     }
 };

class BinaryTree{

private:

public :
  TreeNode* root =NULL ;

     BinaryTree(int root_val ) :  root (new TreeNode(root_val) ) { }



int _max_Node(TreeNode * current  ){

   if( current == nullptr)
      return 0 ;

    int max_left = _max_Node( current->left );

    int max_right = _max_Node (current->right  ) ;


  return   max( max(max_left , max_right) , current->val ) ;
}
void Max_Node(){
    int res =  _max_Node(root) ;
    cout<<" the max node in the tree is : "<<res <<"\n";
    return ;
}


void _PrintInorder( TreeNode *current){
     if( current == NULL)
       return ;

_PrintInorder(current->left) ;
      cout<< current->val<<" " ;
      _PrintInorder(current->right) ;
 }
void printInorder(){
    _PrintInorder(root) ;
     cout<<"\n" ;
}

int get_tree_height(TreeNode * current){
    if(current == NULL)
     return 0 ;

     int left_height  =  get_tree_height(current->left)  ;
     int right_height = get_tree_height(current->right) ;

     return max( left_height , right_height ) + 1 ;
}
void print_max_height_path(){
    int tree_height = get_tree_height(root) ;
    cout<< "Height of binary tree: " << tree_height <<"\n" ;
    return ;
}



void add (vector<int> value, vector<char> direction ){
     assert(value.size() == direction.size());
        TreeNode* current = this->root;
        for (int i = 0; i < (int)value.size(); ++i)
        {
            if (direction[i] == 'L')
            {
                if (!current->left)
                    current->left = new TreeNode(value[i]);
                else
                    assert(value[i] == current->left->val);
                current = current->left;
            }
            else
            {
                if (!current->right)
                    current->right = new TreeNode(value[i]);
                else
                    assert(current->right->val == value[i]);
                current = current->right;
            }
        }
}


void _levelOrderTraversal( TreeNode * root) {
     while(root == NULL )
      return ;

     queue<TreeNode *> qu ;
      qu.push(root) ;
      while(!qu.empty() ){

          int sizeQueue = qu.size() ;

         while(sizeQueue-- ){
             TreeNode * cur = qu.front() ;
             qu.pop() ;
             cout<<cur->val<<" " ;

             if(cur->left)
              qu.push(cur->left) ;
              if(cur->right)
              qu.push(cur->right) ;
         }
         cout<<"\n" ;
     }

}
void PrintOrderTraversal(){
    cout<<"print order Traversal : \n" ;
    _levelOrderTraversal(root) ;

    cout<<"\n";
}

void _ZigzagOrderTraversal(TreeNode * root ){
    if(root == NULL)
      return ;

    deque<TreeNode*> deq ;
    deq.push_back(root) ;

    int count = 0 ;
    while( !deq.empty() ){


         int sz = deq.size() ;
         while(sz--){

             if(count % 2 == 1){
               TreeNode* cur =deq.front() ;
               deq.pop_front() ;
               cout<<cur->val<<" " ;

               if(cur->left )
                deq.push_back(cur->left) ;

               if(cur->right)
               deq.push_back(cur->right) ;
             }

             else{
                 TreeNode* cur = deq.back() ;
                 deq.pop_back() ;
                  cout<<cur->val<<" " ;

                  if(cur->right)
                  deq.push_front( cur->right ) ;

                  if(cur->left)
                  deq.push_front( cur->left ) ;

             }

         }
         cout<<"\n" ;
    }

}
void PrintZigzagOrderTraversal(){
    cout<<"Print zigzag order traversel : \n" ;
    _ZigzagOrderTraversal(root) ;
    cout<<"\n";

}


bool _Check_Complet(TreeNode * root ){
      if(root == NULL)
       return false ;

     queue<TreeNode *> qu ;
     qu.push(root);

     while( !qu.front()){
         TreeNode * cur = qu.front() ;

         qu.pop();
         qu.push( cur->left ) ;
         qu.push( cur->right ) ;
     }

     while( !qu.empty() && qu.front() == NULL )
           qu.pop();

     return qu.empty();
}
void Print_Check_Complet(){
        cout<<"The tree is completly (T / F ) : ";

        if(_Check_Complet(root ) == 0)
          cout<<"FALSE" ;

         else
         cout<<"TRUE" ;

        cout<<"\n" ;
}

int check_length_diameter(TreeNode * root ,int & diameter ){
    if(root == NULL )
      return 0 ;

int left  = check_length_diameter(root->left  ,  diameter )  ;
int right = check_length_diameter(root->right ,diameter  )  ;

diameter = max(left + right , diameter ) ;

return max(left , right ) + 1 ;

}

void print_length_of_the_diameter(){
    if(root == NULL)
      return ;
    int diameter = 1 ;

    check_length_diameter(root , diameter ) ;
    cout<<"The length of the longest path between any two nodes is : " <<diameter<<"\n" ;
    return ;
}

string _parenthesize(TreeNode * root ){
    if( root == NULL)
      return "()" ;

     string rept = "("+to_string(root->val ) ;

     if( root->left)
     rept += _parenthesize(root->left) ;
     else
     rept +="()" ;

    if( root->right)
    rept += _parenthesize(root->right) ;
    else
    rept +="()" ;

    rept +=")" ;

    return rept ;

}
void print_parenthesize(){
     cout<<"the string of tree : " << _parenthesize(root) <<"\n";
     return ;
}

// if you have several tree how check it has the same value
string _parenthesize_canonical(TreeNode * root) {
    if( ! root)
     return "()" ;
     string repr = "(" + to_string(root->val ) ;
     vector<string > v ;

     if(left )
     v.push_back( _parenthesize_canonical(root->left) ) ;
     else
      v.push_back("()") ;

      if(right)
     v.push_back( _parenthesize_canonical(root->right) ) ;
     else
      v.push_back("()") ;

      sort( v.begin() , v.end() ) ;

      for( int i = 0 ; i < (int) v.size() ; i++)
      repr += v[i] ;

      repr +=")" ;

      return repr ;

}
void  print_parenthesize_canonical(){

    cout<<" the parenthesize canonical of tree : "<<_parenthesize_canonical(root)<<"\n" ;
}

};


int main()
{
     BinaryTree tree(1);

    tree.add({2, 4, 7}, {'L', 'L', 'L'});
    tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 9}, {'L', 'R', 'R'});
    tree.add({3, 6, 22}, {'R', 'R', 'L'});
     tree.add({3, 6, 11}, {'R', 'R', 'R'});

    tree.print_max_height_path() ;
    tree.PrintOrderTraversal() ;
    tree.PrintZigzagOrderTraversal();
    tree.Print_Check_Complet();
    tree.print_length_of_the_diameter();
    tree.print_parenthesize();
    tree.print_parenthesize_canonical() ;


  return 0;
}
