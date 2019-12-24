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

std::string binarycoder::compToBinary(std::string &mnemonic){

   std::string binarycode="";

        if(mnemonic.compare("0")==0)
            binarycode="0101010";
        if(mnemonic.compare("1")==0)
            binarycode="0111111";
        if(mnemonic.compare("-1")==0)
            binarycode="0111010";
        if(mnemonic.compare("D")==0)
            binarycode="0001100";
        if(mnemonic.compare("A")==0)
            binarycode="0110000";
        if(mnemonic.compare("M")==0)
            binarycode="1110000";
        if(mnemonic.compare("!D")==0)
            binarycode="0001101";
        if(mnemonic.compare("!A")==0)
            binarycode="0110001";
        if(mnemonic.compare("!M")==0)
            binarycode="0110001";
        if(mnemonic.compare("-D")==0)
            binarycode="0001111";
        if(mnemonic.compare("-A")==0)
            binarycode="0110011";
        if(mnemonic.compare("-M")==0)
            binarycode="1110011";
        if(mnemonic.compare("D+1")==0)
            binarycode="0011111";
        if(mnemonic.compare("A+1")==0)
            binarycode="0110111";
        if(mnemonic.compare("M+1")==0)
            binarycode="1110111";
        if(mnemonic.compare("D-1")==0)
            binarycode="0001110";
        if(mnemonic.compare("A-1")==0)
            binarycode="0110010";
        if(mnemonic.compare("M-1")==0)
            binarycode="1110010";
        if(mnemonic.compare("D+A")==0)
            binarycode="0000010";
        if(mnemonic.compare("D+M")==0)
            binarycode="1000010";
        if(mnemonic.compare("D-A")==0)
            binarycode="0100011";
        if(mnemonic.compare("D-M")==0)
            binarycode="1100011";
        if(mnemonic.compare("A-D")==0)
            binarycode="0000111";
        if(mnemonic.compare("M-D")==0)
            binarycode="1000111";
        if(mnemonic.compare("D&A")==0)
            binarycode="0000000";
        if(mnemonic.compare("D&M")==0)
            binarycode="1000000";
        if(mnemonic.compare("D|A")==0)
            binarycode="0010101";
        if(mnemonic.compare("D|M")==0)
            binarycode="1010101";

       return binarycode;
   }




std::string binarycoder::convert(instruction &instrInput,int  lineno){
    std::string binarycodestr="";
    if(instrInput.Type==instruction::A_COMMAND){
        if(isNumeric(instrInput.symbol) == true){
            return binarycoder::SymbolToAInstr(instrInput.symbol);
        }
    }

     if(instrInput.Type==instruction::L_COMMAND){

     }

    return binarycodestr;
}

