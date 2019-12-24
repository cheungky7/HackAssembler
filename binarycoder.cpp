#include "binarycoder.h"
#include <regex>


bool binarycoder::isNumeric(std::string token){

    return std::regex_match( token, std::regex( ( "((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?" ) ) );
};


binarycoder *binarycoder::getInstance(){
     if (instance !=nullptr) {
       instance = new binarycoder();
     }
      return instance;
}


std::string binarycoder::SymbolToAInstr(std::string symbol){
    size_t sz;
    int number= std::stoi(symbol,&sz,10);
    std::bitset<16> symbolbits(number);
    return symbolbits.to_string();

}


std::string binarycoder::convert(instruction &instrInput,int  lineno){
    std::string binarycodestr="";
    if(instrInput.Type==instruction::A_COMMAND){
        if(isNumeric(instrInput.symbol) == true){
            return binarycoder::SymbolToAInstr(instrInput.symbol);
        }
    }

    return binarycodestr;
}

