/*
FIRST CODE :

This C++ code defines a phone book data structure (PhoneHashTable)
using a hash table to store phone entries (PhoneEntry) and provides
functionalities to add, remove, and print entries.
It employs custom string hashing and dynamic resizing to maintain efficiency.
*/

/*
====>>> when add element, print the (load factor) the load factor in this code = 0.7
       //when the current load factor exceeds the specified limit of 0.7,
       //it creates a new table (new_table) with a size twice that of the current table
       //and copies the entries to the new table.
*/


#include<iostream>
#include<vector>
#include<cmath>
#include<cassert>
#include<sstream>
using namespace std;

int hash_string(string str, int n_ = 65407) {
	int base = 2 * 26 + 10;	// lower, upper and 10 digits
	long long n = n_;
	long long sum = 0;

	for (int i = 0; i < (int) str.size(); ++i) {
		// lowers from [0-25], upper [26-51] and digits [52-61]
		int value = 0;
		if (islower(str[i]))
			value = str[i] - 'a';
		else if (isupper(str[i]))
			value = 26 + str[i] - 'A';
		else if (isdigit(str[i]))
			value = 26 + 26 + str[i] - '0';
		else
			assert(false);
		sum = sum * base + value;	// base 26 number
		sum %= n;	// reduce to minimize overflows
	}
	return sum % n;
}

struct PhoneEntry {
	const static int INTERNAL_LIMIT = 2147483647;
	string name;			// key
	string phone_number;	// data

	int hash() {
		return hash_string(name, INTERNAL_LIMIT);
	}

	PhoneEntry(string name, string phone_number) :
			name(name), phone_number(phone_number) {
	}

	void print() {
		cout << "(" << name << ", " << phone_number << ")  ";
	}
};

class PhoneHashTable {
private:
	int table_size { };
	double limit_load_factor { };
	int total_elements { };
	vector<vector<PhoneEntry>> table;

public:
	PhoneHashTable(int table_size = 10, double limit_load_factor = 0.7 ) :
		table_size(table_size), limit_load_factor(limit_load_factor) {
		table.resize(table_size);
	}

	void put(PhoneEntry phone) {
		int idx = phone.hash() % table_size;

		for (int i = 0; i < (int) table[idx].size(); ++i) {
			if (table[idx][i].name == phone.name) {
				table[idx][i] = phone; // exist => update
				return;
			}
		}
		++total_elements;
		rehashing();
		table[idx].push_back(phone);
	}


	void rehashing() {
		double cur_load_factor = (double) total_elements / table_size;
		cout<<cur_load_factor<<"\n";
		if (cur_load_factor < limit_load_factor)
			return;

		PhoneHashTable new_table(2 * table_size, limit_load_factor);

		for (int hash = 0; hash < table_size; ++hash) {
			if (table[hash].size() == 0)
				continue;

			for (int i = 0; i < (int) table[hash].size(); ++i)
				new_table.put(table[hash][i]);
		}
		// copy
		table_size *= 2;
		table = new_table.table;


	}

	void print_all() {
		cout<<"_____________________________\n";
		for (int hash = 0; hash < table_size; ++hash) {
			if (table[hash].size() == 0)
				continue;

			cout << "Hash " << hash << ": ";
			for (int i = 0; i < table[hash].size(); ++i )
				table[hash][i].print();
			cout << "\n";
		}
	}

	void Remove(  PhoneEntry phone ){
	    int idx = phone.hash();

	    for( int i = 0 ; i< table[idx].size() ; i++ ){
	        if(table[idx][i].name == phone.name && table[idx][i].phone_number == phone.phone_number  ) {
	            swap(table[idx][i] , table[idx].back() ) ;
	            total_elements-- ;
	            table[idx].pop_back() ;
	            return ;
	        }
	    }
	    return ;
	}


};


int main() {
    PhoneHashTable table(11);
   // table.print_all() ;


    table.put(PhoneEntry("a", "07"));
    table.put(PhoneEntry("bbbbb", "6332994"));
    table.put(PhoneEntry("bbbb", "6332994"));
    table.put(PhoneEntry("bbbbbbbb", "6332994"));
    table.put(PhoneEntry("bbbbb", "6332994"));
    table.put(PhoneEntry("b", "6332994"));
    table.put(PhoneEntry("c", "0332994"));
    table.put(PhoneEntry("d", "016332994"));
    table.put(PhoneEntry("e", "010063324"));
    table.put(PhoneEntry("f", "010062994"));
    table.put(PhoneEntry("g", "010063994"));
    table.put(PhoneEntry("h", "010063394"));
    table.put(PhoneEntry("i", "006332994"));
    table.put(PhoneEntry("mm", "006332994"));
    table.put(PhoneEntry("nz", "006332994"));
     table.put(PhoneEntry("n", "006394"));
     table.put(PhoneEntry("most", "006394"));


     table.Remove(PhoneEntry("h", "010063394")) ;

     table.print_all();



    return 0;
};


//-----------------------------------------------------------------------------------------
// Second CODE :

// this struct return hash from ( two string and number )

#include <iostream>
#include <string>
using namespace std;
struct HashOpject {
    const static int  INTEGER_LIMIT = 2147483647 ;

    string str1 ;
    string str2 ;
    int num ;

    int hash(){
        int value = 0 ;
        value = hash_string_upper_and_lower( str1+str2 , INTEGER_LIMIT ) ;
        value += hash_digit(num , INTEGER_LIMIT ) ;

         return value % INTEGER_LIMIT ;
    }

 int hash_string_upper_and_lower( string  str , int INTEGER_LIMIT ){
       int sum = 0 ;
       for( int i = 0 ; i < (int)str.size() ; i++ ) {
           char ch = str[i] ;
            if(isupper(ch) )
            sum = sum * i + ch - 'A'  % INTEGER_LIMIT ;
            else
            sum = sum *i + ch  % INTEGER_LIMIT ;
       }
       return sum % INTEGER_LIMIT ;
 }

 int hash_digit( int num , int INTEGER_LIMIT  ){

        return num % INTEGER_LIMIT ;
 }

} ;

int main()
{
    HashOpject obj ;
    obj.str1 = " mostafa" ;
    obj.str2 = "Hessen" ;
    obj.num = 123456 ;
   cout<< obj.hash();

    return 0;
}



//-----------------------------------------------------------------------------------
// Third CODE
// return Hash from string( upper ,lowwer ) letter and number from(0 --> 9 )

#include <iostream>
#include <string>
using namespace std;
int hash_string( string str ,  int n ) {

     long long sum = 0 ;
      int base = 2 *26 + 9 ;

     for( int i = 0 ; i< str.size() ; i++ ){
          char ch = str[i] ;

          if( isupper(ch) )
           sum = sum * 26 + ch -'A' % n ;

          else if( islower(ch) )
          sum = sum + ch-'a' % n  ;
          else if( isdigit(ch) )
          sum = sum * 9 + ch -'0' % n ;
          else {
              cout<<"There are char out the scode --> "<< ch <<" Hash =  " ;
              return -1 ;
          }

     }
     cout<<" Hash = ";
     return sum % base ;
 }

int main()
{
     cout<< hash_string( "Mostafa" , 232323434) <<"\n";
     cout<< hash_string( "Mostafa&" , 232323434) ;

    return 0;
}

//--------------------------------------------------------------------------------------
// fourth CODE
// ---> count the common substrings between two input strings.

#include <iostream>
#include<unordered_set>

using namespace std;

int Common_sub_String( string  str1 , string str2 ){
    unordered_set<string> st1 ;
    unordered_set<string> st2 ;

    for( int i = 0 ; i < (int)str1.size() ; i++ ){
           string substr="" ;

        for( int j = i ; j < (int)str1.size() ; j++ ){
              substr += str1[j] ;
              st1.insert(substr) ;
        }
    }

    for( int i = 0 ; i < (int)str2.size() ; i++ ){
           string substr="" ;

        for( int j = i ; j < (int)str2.size() ; j++ ){
              substr += str2[j] ;
              st2.insert(substr) ;
        }
    }


         int count = 0 ;

    for( auto it = st1.begin() ; it != st1.end() ; it++ ){
           string s = *it ;
           if( st2.find(s) != st2.end() )
           count++ ;
    }


    return count ;
}
int main()
{
       string str1 = "aaab" ;
       string str2 = "ab";
       // the comman between str1 & str2 ( a , b , ab )  The answer --> 3

       cout<< Common_sub_String( str1 , str2 ) ;

    return 0;
}

//-------------------------------------------------------------------------------------
// fiveth CODE
//----> How many unique substring in the main string

#include <iostream>
#include <string>
#include<unordered_set>
using namespace std;

int Number_of_distinct_of_subString( string st ){
    unordered_set<string> unset ;

for( int i = 0 ; i < st.size() ; i++ ){
        string str = "" ;

    for( int j = i ; j < st.size() ; j++ ){
         str +=st[j] ;
         unset.insert(str) ;
    }

}

  return unset.size() ;
}

int main()
{

  cout<< Number_of_distinct_of_subString( "aaaba") ;
    return 0;
}


