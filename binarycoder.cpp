#include "binarycoder.h"
#include <regex>


bool binarycoder::isNumeric(std::string token){

    return std::regex_match( token, std::regex( ( "((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?" ) ) );
};


binarycoder *binarycoder::getInstance(){
     if (instance ==nullptr) {
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

   std::string binarycode="0000000";

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
            binarycode="0010011";
        if(mnemonic.compare("D-M")==0)
            binarycode="1010011";
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

std::string binarycoder::destToBinary(std::string &mnemonic){

        std::string binarycode="000";
        if(mnemonic.compare("")==0)
            binarycode="000";
        if(mnemonic.compare("M")==0)
            binarycode="001";
        if(mnemonic.compare("D")==0)
            binarycode="010";
        if(mnemonic.compare("MD")==0)
            binarycode="011";
        if(mnemonic.compare("A")==0)
            binarycode="100";
        if(mnemonic.compare("AM")==0)
            binarycode="101";
        if(mnemonic.compare("AD")==0)
            binarycode="110";
        if(mnemonic.compare("AMD")==0)
            binarycode="111";
       return binarycode;
   }

   std::string binarycoder::jumpToBinary(std::string &mnemonic){

        std::string binarycode="000";
        if(mnemonic.compare("")==0)
            binarycode="000";
        if(mnemonic.compare("JGT")==0)
            binarycode="001";
        if(mnemonic.compare("JEQ")==0)
            binarycode="010";
        if(mnemonic.compare("JGE")==0)
            binarycode="011";
        if(mnemonic.compare("JLT")==0)
            binarycode="100";
        if(mnemonic.compare("JNE")==0)
            binarycode="101";
        if(mnemonic.compare("JLE")==0)
            binarycode="110";
        if(mnemonic.compare("JMP")==0)
            binarycode="111";
       return binarycode;
   }

void binarycoder::addLabelTosymbolTable(instruction &instrInput,int  &NextMEMAddr) {

     if(instrInput.Type==instruction::L_COMMAND){
       // int NextMEMAddr=currentMEMAddr+1;
        m_SymbolTable->addLabel(instrInput.symbol,NextMEMAddr);
    } else {
        NextMEMAddr++;
    }

}

void binarycoder::addVarTosymbolTable(instruction &instrInput) {
     std::string binarycodestr="";
      if(instrInput.Type==instruction::A_COMMAND){
        if(isNumeric(instrInput.symbol) != true){
            m_SymbolTable->addVar(instrInput.symbol);
        }
    }
}

std::string binarycoder::convert(instruction &instrInput,int  lineno){
    std::string binarycodestr="";
    if(instrInput.Type==instruction::A_COMMAND){
        if(isNumeric(instrInput.symbol) == true){
            return binarycoder::SymbolToAInstr(instrInput.symbol);
        }else{
            try{
                int symbolValue=m_SymbolTable->get(instrInput.symbol);
                return binarycoder::SymbolToAInstr(std::to_string(symbolValue));
            }catch(std::exception &e){
                printf("%s at line %d",e.what(),lineno);
            }
        }
    }

     if(instrInput.Type==instruction::C_COMMAND){
        std::string compInBinary=binarycoder::compToBinary(instrInput.comp);
        std::string destInBinary=binarycoder::destToBinary(instrInput.dest);
        std::string jumpInBinary=binarycoder::jumpToBinary(instrInput.jump);
       // std::string C_COMMANDInBinary=compToBinary+destInBinary+jumpInBinary;
       std::string C_COMMANDInBinary("111");
       C_COMMANDInBinary.append(compInBinary);
       C_COMMANDInBinary.append(destInBinary);
       C_COMMANDInBinary.append(jumpInBinary);

        return C_COMMANDInBinary;
     }
/*
      if(instrInput.Type==instruction::L_COMMAND){


      }
*/
    return binarycodestr;
}

void binarycoder::setSymbolTable(symboltable *SymbolTable){
    m_SymbolTable=SymbolTable;
}

binarycoder::binarycoder(){
    m_SymbolTable=nullptr;

}
