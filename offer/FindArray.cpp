#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> >& array) {
        for(size_t i =0; i < array.size(); ++i){
            if(0==binarySearch(target, array[i])){
                return true;
            }
        }
        return false;
    }
    
    int binarySearch(int target, vector<int>& vec)
    {
        size_t high = vec.size()-1;
        size_t low = 0,middle=0;
        
        while(low<=high)
        {   
            middle = low + (high-low)/2;
            int& v = vec[middle]; 
            if(v == target) return 0;
            else if(v > target){high = middle-1;}
            else{low = middle+1;}
        }
        return -1;
    }
};

int main()
{
    vector<vector<int> > array ={{1,2,4,6},{3,4,5,7},{4,7,9,78}};
    Solution s ;
    cout << s.Find(7, array)<<endl;

    return 0;
}