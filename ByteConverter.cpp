#include <iostream>  
#include <cmath>  
#include <string> 
#include <vector>
#include <iomanip>

using namespace std;





int getPrefixNum(string str){
    char prefix;
    if(str.length() == 1){
        return 1;
    } 
    prefix = tolower(str[0]);
    
    int exp;
    switch(prefix){
        case 'k':
            exp = 1;
            break;
        case 'm':
            exp = 2;
            break;
        case 'g':
            exp = 3;
            break;
    }
    int val;
    if(str.length() == 3){
        val = pow(1024,exp);
    } else {
        val = pow(1000,exp);
    }

    return val; 
}

char getType(string str){
    return str[str.length()-1];
}



int main(int numargs, char* args[]){
    if(numargs != 4){
        cout << "Provide exactly three arguments" << endl;
        return -1;
    }
    string num = args[1];
    string in = args[2];
    string out = args[3];


    int val = stoi(num);
    int inPrefix = getPrefixNum(in);
    char inType = getType(in);
    int outPrefix = getPrefixNum(out);
    char outType = getType(out);
    double bitbyte;
    if(inType == 'b'){
        bitbyte = (outType == 'b') ? 1.0 : 1.0/8.0;
    } else {
        bitbyte = (outType == 'B') ? 1.0 : 8.0;
    }
    double result = val * bitbyte * ((double) inPrefix) / outPrefix; //so 1000 if input is gb and output is mb, for instance; 
    cout << result << endl;
    return 0;
}