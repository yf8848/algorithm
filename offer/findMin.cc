#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> &rotateArray) {
        if(rotateArray.empty()) return 0;
        
        int min = rotateArray[0];
        int high = rotateArray.size()-1;
        int low = 0;
        while(low < high-1){
            int middle = low + (high-low)/2;
            cout<<rotateArray[low]<<", "<<rotateArray[middle]<<", "<<rotateArray[high]<<endl;

            if(min >= rotateArray[middle]) high = middle;
            else low = middle;
        }
        return rotateArray[low]<rotateArray[high]?rotateArray[low]:rotateArray[high];
    }
};

int main()
{
    vector<int> vc = {3,4,5,1,2};
    Solution s;
    cout<<s.minNumberInRotateArray(vc)<<endl;
}