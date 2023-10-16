/*
34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity
*/
class Solution {
public:
int first_position( vector<int>nums , int target ){
      if( nums.size() == 0)
      return -1 ;

      int start = 0 ;
      int end= nums.size()-1 ;
      int index = -1 ;
      while( start <= end ){
              int mid = end + (start - end) / 2;
          if(target == nums[mid] )
             index = mid ;

       if(target <= nums[mid] )
           end = mid -1 ;
        else if(target > nums[mid] )
           start = mid+1 ;
      }
      return index ;
}

int last_position( vector<int>nums , int target ){
      if( nums.size() == 0)
      return -1 ;

      int start = 0 ;
      int end= nums.size()-1 ;
      int index = -1 ;
      while( start <= end ){
              int mid = end + (start - end) / 2;
          if(target == nums[mid] )
             index = mid ;

       if(target < nums[mid] )
           end = mid -1 ;
        else if(target >= nums[mid] )
           start = mid+1 ;
      }
      return index ;
}



    vector<int> searchRange(vector<int>& nums, int target) {
         int firstPos = first_position(nums, target );
        int lastPos = last_position(nums, target );

        vector<int> result;
        result.push_back(firstPos);
        result.push_back(lastPos);

        return result;

    }
};
/*
//__________________________________________________________________________________________


1482. Minimum Number of Days to Make m Bouquets
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

  Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
  Output: 3
*/

class Solution {
public:
bool possible ( vector<int> v , int m , int k , int days ){
    int bound = 0 ;
    int count_flower = 0 ;
    for( int i = 0 ; i < v.size() ; i++ ){

             if(v[i] <= days)
                   count_flower++ ;
             else
                  count_flower = 0 ;
         if( count_flower == k ){
                bound++ ;
                count_flower = 0 ;
         }
    }
    if( bound >= m )
    return true ;
    else
    return false ;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
             if( (long long) m *k > bloomDay.size() )
                return -1 ;

         int start = 1 ;
          int end = 1e9;
          int answer = 0 ;
          while( start <= end ) {
              int mid = end+(start - end)/ 2 ;


              if( possible(bloomDay , m , k , mid) ){
                  end = mid -1 ;
                  answer = mid ;
              }
            else
               start= mid +1 ;

          }
          return answer ;
    }
};
//_________________________________

/*
611. Valid Triangle Number
Given an integer array nums, return the number of triplets chosen from the array that can make
triangles if we take them as side lengths of a triangle.

Example 1:

Input: nums = [2,2,3,4]
Output: 3
*/


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort( nums.begin() , nums.end() ) ;
        if( nums < 3)
         return 0 ;

         int count = 0 ;
      for( int i = 2 ; i < nums.size() ; i++ ){

              int s =0 ;
              int e = i-1 ;
              while( s < e ){
                  if( nums[s] + nums[e] > nums[i] ){
                         count += e-s ;
                         e-- ;
                  }
                  else
                   s++ ;
              }
      }
      return count ;
    }
};
//----------------------------------------------------------

/*
475. Heaters
Winter is coming! During the contest, your first job is to design a standard heater with a
 fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range.

Given the positions of houses and heaters on a horizontal line,
return the minimum radius standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius will the same.

Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
*/

// ___>>> My_Code

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
          long long end = 1e10+5 ;
          int start = 0 ;
          int answer = 0 ;
          sort(heaters.begin(), heaters.end());
          sort(houses.begin() , houses.end() ) ;
          unordered_set<int> st_element ;
          for( int i = 0 ; i < houses.size() ; i++ ){
                 st_element.insert(houses[i]) ;
          }

          while( start <= end ){

              int mid = end + (start - end ) /2 ;
              unordered_set<int> st ;
               int  j =0 ;

              for( int i = 0 ; i < heaters.size()  ; i++  ){
                  for( j ; j < houses.size() ; j++ ){

                      long long  pos = abs( houses[j] -heaters[i] ) ;

                      if( pos <= mid )
                         st.insert( houses[j]) ;

                      else
                       break ;
                  }
              }
                if(st.size() == houses.size() || st_element.size() == st.size() ){
                     answer = mid ;
                     end = mid -1 ;
                     st.clear();
                }
                else
                start = mid +1 ;
          }
          return answer ;
    }
};
//--------------------------------------------------------------------
/*
69. Sqrt(x)
Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
 The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
Input: x = 4
Output: 2

*/


class Solution {
public:
    int mySqrt(int x) {
        if( x == 0 )
         return 0 ;
        long long st =1 ;
        long long end = x ;
        int answer = 0 ;

        while( st <= end) {
             long long mid = end +( st - end) / 2 ;
             if( mid * mid <= x ) {
               st= mid + 1 ;
               answer = mid ;
             }
             else
             end = mid - 1 ;
        }
        return answer ;
    }
};
//---------------------------------------------------------------------
