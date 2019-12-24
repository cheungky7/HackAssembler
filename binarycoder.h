#ifndef BINARYCODE_H
#define BINARYCODE_H
#include <string>
#include "instruction.h"

class binarycoder {

private:
    static binarycoder* instance;
    bool isNumeric(std::string value);

public:
    static binarycoder *getInstance();
    std::string convert(instruction &instrInput,int  lineno);
    static std::string SymbolToAInstr(std::string symbol);
    static std::string compToBinary(std::string &mnemonic);



};


#endif
