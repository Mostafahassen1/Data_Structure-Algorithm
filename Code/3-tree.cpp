
#include <vector>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <deque>
#include <string>

using namespace std;

class BinaryTree
{
private:
    int Data{};
    BinaryTree *left{};
    BinaryTree *right{};

public:
    BinaryTree(int Data) : Data(Data)
    {
    }

    void add(vector<int> value, vector<char> direction)
    {
        assert(value.size() == direction.size());
        BinaryTree *current = this;
        for (int i = 0; i < (int)value.size(); ++i)
        {
            if (direction[i] == 'L')
            {
                if (!current->left)
                    current->left = new BinaryTree(value[i]);
                else
                    assert(value[i] == current->left->Data);
                current = current->left;
            }
            else
            {
                if (!current->right)
                    current->right = new BinaryTree(value[i]);
                else
                    assert(current->right->Data == value[i]);
                current = current->right;
            }
        }
    }


int max_node(){
    int res = Data ;
    if(left)
     res = max( res , left->max_node() ) ;

    if(right)
    res = max(res , right->max_node() ) ;

    return res ;
}


int Height_tree(){
    int ll = 1 , r =1 ;
    if(left){
       ll= left->Height_tree()+1;

    }


    if(right){
       r = right->Height_tree()+1;

    }



    return max( ll , r ) ;
}

int count_node(){
    int coun= 1 ;

    if(left)
     coun+=left->count_node() ;

     if(right)
     coun+=right->count_node() ;

   return coun ;
}

bool search(int x){

    bool test = false ;

    if(test == false &&left){
        test = left->count_node() ;
    }

    if(test == false && right)
      test = right->count_node() ;

if(test == true)
return true ;

return false ;
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

   int z = 0 ;
    BinaryTree * root = &tree;


    cout<<"\n"<<tree.max_node() ;

    cout<<"\n"<<tree.Height_tree();

    cout<<"\n"<<tree.count_node();

    cout<<"\n"<<tree.search(6) ;




    return 0;
}

