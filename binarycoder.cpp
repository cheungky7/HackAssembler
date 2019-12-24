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
    char temp2[16]={0};
    char temp[16]={0};
    memset (temp2,'0',16);
    memset (temp,'0',16);
    int digit=0;
    int init=number;
    for(digit=0; number>0; digit++){
        temp[digit]=(char)number%2+'0';
        number= number/2;
    }
    if(init%2==0){
        digit=digit+1;
    }



    memcpy ( (char*)&temp2[16-digit],(char*) temp, digit );
    std::string str(temp2);// string constructor deep copy
    return str;

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

