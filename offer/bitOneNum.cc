#include <iostream>

using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         int num=0;
         int s=n;
         if(s==0)
         {
         }
         else if(s>0)
         {
             while(s&(s-1))
             {
                 cout<<s<<" ";
                 ++num;
                 s-=1;
             }
             ++num;
             cout<<s<<endl;
         }else{
             while(s&(s+1))
             {
                cout<<s<<" ";
                 num++;
                 s+=1;
             }
             //num++;
            
            cout<<s<<endl;
         }
         return num;
     }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for(int i =-5; i<5; ++i)
    {
        cout<< i<<": "<<  s.NumberOf1(i)<<endl;
    }
    return 0;
}
