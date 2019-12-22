#include "instruction.h"


instruction::instruction(){

 this->Type=instruction::INVALID_COMMAND;
  symbol="";
  dest="";
  comp="";
  jump="";

}

 void instruction::parse(std::string line){

    if(line.at(0)=='@'){
        this->Type=instruction::A_COMMAND;
        symbol=line.substr(1,line.size()-1); //exclude @
    }else {
        if(line.at(0)=='('){
            this->Type=instruction::L_COMMAND;
            symbol=line.substr(1,line.size()-2);// exclude ()
        }else {
           this->Type=instruction::C_COMMAND;
           std::size_t comp_pos =  line.find("=");
           std::size_t jump_pos =  line.find(";");
           if(comp_pos !=std::string::npos){
                this->dest=line.substr(0,comp_pos-1);
                this->comp=line.substr(comp_pos+1,line.size()-(comp_pos+1));
           }
           if(jump_pos !=std::string::npos){
                this->dest=line.substr(0,jump_pos-1);
                this->jump=line.substr(jump_pos+1,line.size());
           }
        }
    }
 }
