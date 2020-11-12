#include <iostream>
#include <string>
#include <cmath>

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
			poww = poww%101;
		}
	}

	//return poww % 101;
	return poww;
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

void stringFind(const std::string& text, const std::string& key){
    //find first occurence
    std::size_t found = text.find(key);
     while(found != std::string::npos){
        // print out tthat the pattern occurs
        std::cout << "Pattern found at index " << found << std::endl;
        // Get the next occurrence from the current position
        found =text.find(key, found + key.size());
    }
}

int main()
{
    // std::string text = "abradaacadabrada";
    // std::string pattern = "ada";
    std::string text = "aababacdabays isaliujhsdf;jnasajnfdsa jibababa;ajkshdasababa;osuidhf sdfababa;asdffdhfaaaaabb bbbbaaaa";
    std::string pattern = "babab";

    // std::string text = "Loremipsumdolorsitametconsecteturadipiscingelitsit";
    // std::string pattern = "sit";
    //std::cout<<"length"<<text.length()<<std::endl;

    std::cout<<"Our Rabin Karp Algorithm Results"<<std::endl;

    rk(text,pattern);
    std::cout<<"///////////////"<<std::endl;
    std::cout<<"String Class Find Function results"<<std::endl;
    stringFind(text, pattern);

}