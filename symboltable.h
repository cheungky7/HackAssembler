#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <map>
#include <string>
#include <stdexcept>


#define VAR_STAR_ADDR 0x16



class symboltable {

private:
     std::map<std::string,int>* m_table;
     int numOfVarAssigned;

public:
    symboltable();
    ~symboltable();
    int  get(std::string symbol);
    void addVar(std::string symbol);
    void addLabel(std::string symbol,int value);

};

#endif
