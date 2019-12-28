#include <stdio.h>
#include "parser.h"
#include "binarycoder.h"
#include "symboltable.h"

using namespace std;

binarycoder *binarycoder::instance = nullptr;
void scanfile(const char* filename);
void scanfileforsymbol(const char* filename,symboltable* symbolTable);

int main(int argc, char **argv){

    for (int i = 0; i < argc; ++i){
        printf("arg%d is %s\n",i,argv[i]);
    }
    //string fileName(argv[0]);
    symboltable *g_sysmboltable=new symboltable();
    binarycoder::getInstance()->setSymbolTable(g_sysmboltable);


    scanfile(argv[1]);
    if(g_sysmboltable !=nullptr){
        delete g_sysmboltable;
    }

    return 0;
}

void scanfileforsymbol(const char* filename,symboltable* symbolTable) {
	std::ifstream infile(filename);
	 //size_t found = filename.find(".asm");
	if (infile.is_open())
	{
		int lineno = 0;
		std::string line;
		while (std::getline(infile, line))
		{
			lineno++;
			if(has_only_spaces(line)==true) {
                continue; // skip if whole line is space
			}

			std::string instructionStr=removeCommentAndWhiteSpace(line);
			if(instructionStr.size()==0){
                continue;// skip if whole line is comment
			}
            //instruction Instr;
            //Instr.parse(instructionStr);
            //std::string binarycodestr=binarycoder::getInstance()->convert(Instr,lineno);
            //printf("%s\n",binarycodestr.c_str());


		}
		infile.close();
	}
}


void scanfile(const char* filename) {
	std::ifstream infile(filename);
	ofstream hackfile;
	std::string inputfilename(filename);
	size_t found=inputfilename.find(".asm");
	std::string outputfilename=inputfilename.substr(0,found)+".hack";

	 //size_t found = filename.find(".asm");
	if (infile.is_open())
	{
        hackfile.open(outputfilename.c_str());
		int lineno = 0;
		std::string line;
		while (std::getline(infile, line))
		{
			lineno++;
			if(has_only_spaces(line)==true) {
                continue; // skip if whole line is space
			}

			std::string instructionStr=removeCommentAndWhiteSpace(line);
			if(instructionStr.size()==0){
                continue;// skip if whole line is comment
			}
            instruction Instr;
            Instr.parse(instructionStr);
            std::string binarycodestr=binarycoder::getInstance()->convert(Instr,lineno);
            printf("%s\n",binarycodestr.c_str());
            hackfile<<binarycodestr.c_str()<<"\n";

		}
		hackfile.close();
		infile.close();
	}
}


