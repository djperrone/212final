#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

void WriteFile(){
}

int main(int argc, char** argv){


    std::string CHARACTERS;


    if(argv[1]=="genes"){
        CHARACTERS =     "A,C,G,T";
    }
    else{
        CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    }

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);



    std::ofstream oStream;   
    int patlen = std::stoi(argv[2]);
    //std::cin>>patlen;
    oStream.open("../assets/pattern.txt");

    for(int j = 0;j<patlen;j++){
        
        oStream << CHARACTERS[distribution(generator)];
    }
    oStream.close();


    oStream.open("../assets/names.txt");
    
    for(int i =6;i<10;i++){
        oStream<<"rand"+std::to_string(i)+".txt"<<std::endl;      
    }
    oStream.close();

    for(int i = 5; i < 10; i++){

        int len = std::pow(10,i);    

    //     std::string rand_str;
    //     rand_str.reserve(len);
    //     for(int j = 0;j<len;j++){
    //         rand_str += (CHARACTERS[distribution(generator)]);
    //     }
    //     std::cout<<rand_str.size()<<std::endl;
    //     std::cout<<rand_str.max_size()<<std::endl;
    //    rand_str.clear();        
        
        std::cout<<i<<std::endl;
        oStream.open("../assets/rand"+ std::to_string(i)+".txt");

        for(int j = 0;j<len;j++){
            
            oStream << CHARACTERS[distribution(generator)];
        }
        oStream.close();
    }
}