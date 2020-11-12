#include <iostream>
#include <string>
#include <cmath>
#include <time.h>

#define b 256
#define q 101

//do we need to erase symbols and does case matter, do spaces

int power(int base, int exponent){
	int poww = 1;

	if (exponent == 0){
		return 1;
	}
	else{
		for(int i = 0; i < exponent; i++){
			poww *= base;
		}
	}

	return poww % 101;
}

int hash(const std::string& text, int len)
{
    int h = 0;
    for (int i = 0; i < len; i++)
    {
        h += (int)text[i] * (power(256, len - 1 - i));

    }
    return h;
}

void rk(const std::string& text, const std::string& key)
{
    int len = key.length();
    // calculate hash value of key
    int keyHash = hash(key, len);
    // calculate hash value of first substring to search
    int strHash = hash(text.substr(0, len),len);

    for (int i = 0; i <= text.length()-len; i++)
    {
        std::string sub = text.substr(i, len);
        strHash = hash(sub, len);
        //std::cout<<"subStr "<<sub<<std::endl;
        if (keyHash == strHash)
        {
            std::cout << "Pattern found at index " << i << std::endl;
        }

        strHash -= int(sub[0]) * power(256, len - 2);
        strHash *= 256;
    }

}

int main()
{
    //define a clock
    clock_t t;

    // std::string text = "abradaacadabrada";
    // std::string pattern = "ada";
    // std::string text = "aababacdabays isaliujhsdf;jnasajnfdsa jibababa;ajkshdasababa;osuidhf sdfababa;asdffdhfaaaaabb bbbbaaaa";
    // std::string pattern = "babab";

    std::string text = "Loremipsumdolorsitametconsecteturadipiscingelitsit";
    std::string pattern = "sit";
    //std::cout<<"length"<<text.length()<<std::endl;

    t = clock();
    rk(text,pattern);

    t = clock() - t;

    std::cout<<"The program ran in" << " "<< ((float)t)/CLOCKS_PER_SEC<< " seconds"<< std::endl;
}