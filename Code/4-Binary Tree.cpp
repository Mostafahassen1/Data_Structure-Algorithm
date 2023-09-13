#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
    private:
     TreeNode* root;

    void _print_InOrder(TreeNode* node) {
        if (node == nullptr)
            return;

        _print_InOrder(node->left);
        cout << node->val << " ";
        _print_InOrder(node->right);
    }

    void _add_element(vector<int> v) {
        for (int i = 0; i < static_cast<int>(v.size()); i++) {
            TreeNode* cur = root;
            TreeNode* newNode = new TreeNode(v[i]);

            while (true) {
                if (cur->val > newNode->val && cur->left != nullptr)
                    cur = cur->left;
                else if (cur->val > newNode->val && cur->left == nullptr) {
                    cur->left = newNode;
                    break;
                }
                else if (cur->val < newNode->val && cur->right != nullptr)
                    cur = cur->right;
                else {
                    cur->right = newNode;
                    break;
                }
            }
        }
    }

    int _min_node( TreeNode * root){
        TreeNode * node = root  ;
         int min_val = root->val ;

         while( root->left != NULL ) {
              root = root->left ;
              min_val = root->val ;
         }
          return min_val ;
    }

public:
    BinaryTree(int val) {

        root = new TreeNode(val);
    }

    void print_inOrder() {
        cout << "The elements in the tree using in-order traversal: ";
        _print_InOrder(root);
        cout << endl;
    }


    void add(vector<int> v) {
        _add_element(v);
        cout << "Elements added successfully." << endl;
        return;
    }

    void  delete_Node( int target ){
        _delete_Node( root , target) ;
    }

 TreeNode * _delete_Node( TreeNode * root , int target){

     if( root == NULL) return NULL ;

     if( root->val < target)
     root->right = _delete_Node( root->right , target ) ;

     else if( root->val > target)
     root->left = _delete_Node( root->left , target ) ;

     else{

         TreeNode * temp = root ;

         if(root->left == NULL && root->right == NULL )
           root = NULL ;

         else if(root->left == NULL )
           root = root->right ;

         else if( root->right == NULL)
          root = root->left ;

         else{
            root->val =_min_node(root->right ) ;
            root->right =  _delete_Node(root->right , root->val ) ;
            temp = NULL ;
         }
         delete temp ;
     }
     return root ;

}

};

int main() {
    BinaryTree tree(20);
    tree.add({ 11, 3, 12 ,25 , 30 , 26});
    tree.print_inOrder();
    cout<<"\n" ;
    tree.delete_Node(25) ;
     tree.print_inOrder();
    cout<<"\n" ;


    return 0;
}
