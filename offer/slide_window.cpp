#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        int max = 0,last_max=0;
        if(num.empty()||num.size() <= size || size <1)
        {
            return res;
        }
        
        for(size_t i = size -1; i < num.size(); ++i)
        {
            res.push_back(max_value(num,i,size)); 
        }
        return res;
    }
    
    int max_value(const vector<int>& v, const int& idx, const int& n)
    {
        int max_v=v[idx];
        for(int i = idx-1; i> idx-n && i>=0;--i)
        {
            if(v[i]>max_v){
                max_v = v[i];
            }
        }
        return max_v;
    }
};

void print_vec(const vector<int>& v)
{
    for(int i = 0; i< v.size(); ++i)
    {
        cout<<v[i]<< " ";
    }
    cout<<endl;
}

int main()
{
    vector<int> v = {0,2,3,4,2,6,2,5,1,0,0,0};
    int n =3;

    Solution s;
    print_vec(s.maxInWindows(v, 5));

}