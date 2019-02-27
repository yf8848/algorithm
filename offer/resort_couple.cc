
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    long InversePairs(vector<int>& data) {
        if(data.empty()) return 0;
        
        vector<int> copy;
        copy.reserve(data.size());
        vector<int>::iterator it = data.begin();
        for(; it!=data.end();++it)
        {
             copy.push_back(*it);
        }
        //copy.assign(data.begin(), data.end());
        //int* copy = new int[data.size()];
        
        long sum=reserveInversePairs(data, copy, 0, data.size()-1);
        //delete[] copy;
        return sum%1000000007;
    }
    
private:
    long reserveInversePairs(vector<int>& data, vector<int>& copy, int start, int end)
    {
        if(start==end){
            copy[start] = data[start];
            return 0;
        }
        
        int len = (end-start)>>2;
        long left = reserveInversePairs(copy,data,start,start+len);
        long right = reserveInversePairs(copy,data,start+len+1,end);
        
        int idx_d=start+len, idx_c=end;
        int idx_cp = end, count=0;
        while(idx_d>=start&&idx_c>=start+len+1)
        {
            if(data[idx_d]>data[idx_c]){
                copy[idx_cp--]=data[idx_d--];
                count+=idx_c-(start+len);
            }
            else
            {
                copy[idx_cp--]=data[idx_c--];
            }
        }
        
        while(idx_d>=start)
        {
            copy[idx_cp--]=data[idx_d--];
        }
        
        while(idx_c>=start+len+1)
        {
            copy[idx_cp--]=data[idx_c--];
        }
        
        return (left+count+right);
    }
};

void printV(const vector<int>& v )
{
    for(size_t i=0; i< v.size(); ++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a;
    vector<int> vec;
    while(cin>>a)
    {
        vec.push_back(a);
    }

    printV(vec);

    Solution s;
    cout<<s.InversePairs(vec)<<endl;

    return 0;;
}