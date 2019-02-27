#include <iostream>
#include <string>

using namespace std;

void getNext(const string& str, int next[])
{
    size_t  len = str.size()-1;
    int k=-1;
    int j =0;
    next[0] =  -1;

    while(j<=len)
    {
        if(k==-1 || str[k]==str[j])
        {
            k++;
            j++;
            next[j] = k;
        }
        
        else
        {
            k = next[k];
        }
    }

    for(int i=0; i<=len;++i)
    {
        cout<<next[i]<<" ";
    }
    cout << endl;
}

int KMPSearch(const string& src, const string& des, int next[])
{
    int i=0, j=0;
    int sLen=src.length(), dLen = des.length();

    while(i<sLen && j< dLen)
    {
        if(j==-1 || src[i] == des[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }

    if(j == dLen) return i-j;
    else return -1;
}


int main(int argc, char const *argv[])
{
    string src="substring searching algorithm";
    string des="search";

    int next[des.size()];


    getNext(des, next);
    for(int i=0; i<des.size();++i)
    {
        cout<<next[i]<<" ";
    }
    cout << endl;
    
    cout << "res: "<< KMPSearch(src, des, next)<<endl;
    return 0;
}
