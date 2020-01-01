#include "symboltable.h"


symboltable::symboltable(){
    m_table=new std::map<std::string,int>();
    m_table->insert( std::pair<std::string,int>("SP",0x00));
    m_table->insert( std::pair<std::string,int>("LCL",0x01));
    m_table->insert( std::pair<std::string,int>("ARG",0x02));
    m_table->insert( std::pair<std::string,int>("THIS",0x03));
    m_table->insert( std::pair<std::string,int>("THAT",0x04));
    m_table->insert( std::pair<std::string,int>("SCREEN",0x4000));
    m_table->insert( std::pair<std::string,int>("KBD",0x6000));


    for(int i=0;i<16;i++){
        char temp[8];
        sprintf(temp,"R%d",i);
        std::string strTemp(temp);
        m_table->insert( std::pair<std::string,int>(strTemp,i));
    }

    this->numOfVarAssigned=0;
}

symboltable::~symboltable(){
    /*
    std::map<string, int>::iterator it;
    for ( it = m_table.begin(); it != m_table.end(); it++ ){

    } */
    this->m_table->clear();
    delete this->m_table;

}


void symboltable::addVar(std::string symbol){
    if(m_table->find(symbol) ==m_table->end()){
        int varAddr=this->numOfVarAssigned+VAR_STAR_ADDR;
        m_table->insert( std::pair<std::string,int>(symbol,varAddr));
        this->numOfVarAssigned++;
        printf("add %s value%d\n",symbol.c_str(),varAddr);
    }
}

void symboltable::addLabel(std::string symbol,int value){
  //  if(m_table->find(symbol) ==m_table->end()){
        //int varAddr=this->numOfVarAssigned+VAR_STAR_ADDR;
        m_table->insert( std::pair<std::string,int>(symbol,value));
        //this->numOfVarAssigned++;
        printf("Insert %s value %d\n",symbol.c_str(),value);
   // }
}

int symboltable::get(std::string symbol){
    if(m_table->find(symbol) !=m_table->end()){
        return m_table->at(symbol);
    } else {
        std::string errorMsg="Symbol not define:"+symbol;
        throw std::invalid_argument(errorMsg);
    }
}

