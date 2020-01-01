#ifndef BINARYCODE_H
#define BINARYCODE_H
//#include <map>
//#include <string>
#include "instruction.h"
#include "symboltable.h"

//typedef  std::map<std::string,int> SymbolTable;
//typedef  std::pair<std::string,int> SymbolPair;

class binarycoder {

private:
    static binarycoder* instance;
    bool isNumeric(std::string value);
    symboltable *m_SymbolTable;

public:
    binarycoder();
    void setSymbolTable(symboltable *SymbolTable);
    static binarycoder *getInstance();
    std::string convert(instruction &instrInput,int  lineno);
    static std::string SymbolToAInstr(std::string symbol);
    static std::string compToBinary(std::string &mnemonic);
    static std::string destToBinary(std::string &mnemonic);
    static std::string jumpToBinary(std::string &mnemonic);
    //void addtTosymbolTable(instruction &instrInput,int  &currentMEMAddr);
    void addLabelTosymbolTable(instruction &instrInput,int  &NextMEMAddr);
    void addVarTosymbolTable(instruction &instrInput);



};


#endif
