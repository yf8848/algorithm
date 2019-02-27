#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int>& strNum) {
        string min="";
        string cur="";

        list<int> lc;
        lc.assign(strNum.begin(), strNum.end());
        getMin(lc, cur, min);
        return min;
    }

private:
    void getMin(list<int>& lc, string cur, string& min)
    {
        if(lc.empty()){
            if(min==""||cur<min){
		cout<<"min:"<<min<<endl;
                min = cur;
            }
        }

        int i = lc.size();
        for(int j = 0; j<i; ++j)
        {
	    //printl(lc);
            int t = lc.front();
            lc.pop_front();
            cur+=to_string(i);
            getMin(lc, cur, min);
	    cout<<">"<<min<<" - "<<cur<<endl;
            lc.push_back(t);
	    cur.pop_back();
	    //printl(lc);
        }
    }

    void printl(list<int>& l)
    {
	    for(list<int>::iterator it=l.begin();it!=l.end();++it)
	    {
		    cout<<*it<<" ";
	    }
	    cout<<endl;
    }
};

int main()
{
	vector<int> vec = {3,5,1,4,2};
	Solution s;
	cout<<s.PrintMinNumber(vec)<<endl;

	return 0;
}

