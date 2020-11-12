#include <iostream>
#define b 256
#define q 101

int pow(int num, int len)
{
    int base = 1;

    for (int i = 0; i < len; i++)
    {
        base *= num %q;
        //base %= q;
    }
   
    return base;
}

int main()
{
    std::string text = "abracadabra";
    std::string key = "bra";

    int hash = 0;

    for(int i = 0;i<text.length();i++)
    {
        std::string sub = text.substr(i,key.length());
        for(int j =0;j<key.length();j++)
        {
            hash += ((int)text[i] * pow(256,key.length()-i-1))%q;
            hash %=q;
        }
        
    }

}