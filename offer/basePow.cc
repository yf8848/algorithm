#include <iostream>

using namespace std;

class Solution {
public:
    double Power(double b, int n) {
        if(n==0) return 1.0;
        if(n==1) return b;
        double res = Power(b, n>>1);
        res *= res;
        if(n&0x1)
        {
            res *= b;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for(int i =0; i<5; ++i)
    {
        cout<< i<<": "<<  s.Power(5.5, i)<<endl;
    }
    return 0;
}