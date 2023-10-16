

#include <iostream>
using namespace std;

class NodeTrie {
private:
    static const int MAX_CHAR = 26;


public:

    NodeTrie* children[MAX_CHAR];
    bool isLeaf;

 NodeTrie() {
     isLeaf = false;
      for (int i = 0; i < MAX_CHAR; i++) {
            children[i] = nullptr;
     }
    }

};

class Trie {
private:
    NodeTrie* root;

public:
    Trie() {
        root = new NodeTrie();
    }

    void insert(string str) {
        NodeTrie* current = root;

        for (int i = 0; i < str.size(); i++) {
            int index = str[i] - 'a';

            if (!current->children[index])
                current->children[index] = new NodeTrie();

            current = current->children[index];
        }
        current->isLeaf = true;
    }

 bool prefix_exist(string str) {
    NodeTrie* current = root;
    for (int i = 0; i < str.size(); i++) {
        int cur = str[i] - 'a';
        if (current->children[cur] == nullptr)
            return false;
        else
            current = current->children[cur];
    }
    return true ;
}

bool world_exist( string str , int idx = 0 , NodeTrie * current = nullptr ){

     if( current  == nullptr )
      current = root ;


     int pos = str[idx] - 'a' ;

    if( idx == str.size() ){
       return current->isLeaf ;

    }


    if( current->children[pos] == 0 )
    return false ;

   return  world_exist(str , idx+1 , current->children[pos] ) ;

}

bool world_exist_with_1_change( string str ) {

    for( int i = 0 ;  i< str.size() ; i++ ){
        char cpy = str[i] ;
      for( char c = 'a' ;  c <='z' ; c++ ){
         str[i] = c ;
         if(cpy == str[i] )
           continue ;
          else
          if(world_exist(str) )
           return true ;
      }
      str[i] = cpy ;
  }
   return false ;
}



};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");

    cout<<trie.prefix_exist("app");

    cout<<"\n"<<trie.world_exist("app");
    cout<<"\n"<<trie.world_exist_with_1_change("app");

    return 0;
}
