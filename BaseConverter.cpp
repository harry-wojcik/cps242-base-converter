#include <iostream> //for cout 
#include <cmath> //for pow 
#include <string> //guess.
#include <vector>


using namespace std;

const string HEX_CHARS = "0123456789ABCDEF";

string BinaryToDecimal(string b) {
    int d = 0;
    for(int i = 0; i < b.length(); i++){
        int bit = b.length() - 1 - i;
        if(b.at(i) == '1'){
            d += pow(2.0,bit);
        }
    }
    return to_string(d);
}

string BinaryToHex(string b) {
    string h = "0x";
    while(b.length() % 4 != 0){
        b = "0" + b; //horrifically inefficient but works
    }
    for(int i = 0; i < b.length(); i+=4){
        int val = stoi(BinaryToDecimal(b.substr(i,4)));
        h += HEX_CHARS.at(val);
    }
    return h;
}

string DecimalToBinary(string d) {
    int val = stoi(d);
    string b = "";
    while(val > 0){
        b = to_string(val % 2) + b;
        val /= 2;
    }
    return b;
}

string DecimalToHex(string d) {
    int val = stoi(d);
    string h = "";
    while(val > 0){
        h = HEX_CHARS.at(val % 16) + h;
        val /= 16;
    }
    return "0x" + h;
}


string HexToDecimal(string h) {
    int d = 0;
    for(int i = 0; i < h.length(); i++){
        int hexit = h.length() - 1 - i;
        d += HEX_CHARS.find(h.at(i)) * pow(16,hexit);
    }
    return to_string(d);
}

string HexToBinary(string h) {
    return DecimalToBinary(HexToDecimal(h)); //I am lazy.
}


int main(int blech, char *args[]) {
    string arg1 = args[1];
    char arg2 = args[2][0];
    char arg3 = args[3][0];
    string result;
    switch(arg2){
        case 'b':
            switch(arg3){
                case 'b':
                    result = arg1;
                    break;
                case 'd':
                    result = BinaryToDecimal(arg1);
                    break;
                case 'h':
                    result = BinaryToHex(arg1);
                    break;
            }
            break;
        case 'd':
            switch(arg3){
                case 'b':
                    result = DecimalToBinary(arg1);
                    break;
                case 'd':
                    result = arg1;
                    break;
                case 'h':
                    result = DecimalToHex(arg1);
                    break;
            }
            break;
        case 'h': 
            switch(arg3){
                case 'b':
                    result = HexToBinary(arg1);
                    break;
                case 'd':
                    result = HexToDecimal(arg1);
                    break;
                case 'h':
                    result = "0x" + arg1;
                    break;
            }
            break;
    }
    cout << result << endl;
    return 0;
}