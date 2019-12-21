#include "parser.h"

void readfile(const char* filename) {
	std::ifstream infile(filename);
	if (infile.is_open())
	{
		int lineno = 0;
		std::string line;
		while (std::getline(infile, line))
		{
			printf("line:%d,%s\n", lineno, line.c_str());
			lineno++;
		}
		infile.close();
	}
}

bool has_only_spaces(const std::string& str) {
   return str.find_first_not_of (' ') == str.npos;
}


void removeFromString(std::string &str, std::string tofind)
{
        size_t position = 0;
        for ( position = str.find(tofind); position != std::string::npos; position = str.find(tofind,position) )
        {
                str.erase (position,1);
        }
        //return(str);
}

std::string removeCommentAndWhiteSpace(std::string& str){
   std::size_t found = str.find("//");
   std::string  str2=str.substr(0, found);
  // std::remove_if( str2.begin(), str2.end(), isspace );
    removeFromString(str2," ");
    return str2;
}



void scanfile(const char* filename) {
	std::ifstream infile(filename);
	if (infile.is_open())
	{
		int lineno = 0;
		std::string line;
		while (std::getline(infile, line))
		{
			lineno++;
			if(has_only_spaces(line)==true) {
                continue; // skip whole line is space
			}

			std::string instruction=removeCommentAndWhiteSpace(line);

            printf("%d,%s,length:%d\n", lineno, instruction.c_str(),instruction.size());
		}
		infile.close();
	}
}
