#include<iostream>

using namespace std;

class Solution {
public:
    long jumpFloorII(int n) {
        long res = 0;
        cout<<"Fib["<<n<<"]: ";
       for(int i =0; i<n;i++)
       {
           res += Fib(i);
       }
       cout<<endl;
        return n==0?res:res+1;
    }
    
    long Fib(int n)
    {
        long res = 0;
        long fib = 0;
        long one = 0;
        long two = 1;
        for(int i=1; i<=n;++i)
        {
            fib = one + two;
            one = two;
            two = fib;
            res += fib;
        }
        cout<<"("<<n<<")"<<(n>2?res-fib:res)<<" ";
        return n>2?res-fib:res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    
    for(int i=0; i<10; ++i)
    {
        //cout << s.Fib(i)<<endl;
        cout<< s.jumpFloorII(i) << endl;
    }
    return 0;
}
