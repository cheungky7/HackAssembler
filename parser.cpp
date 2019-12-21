#include "parser.h"

void readfile(const char* filename) {


	ifstream infile(filename);
	if (infile.is_open())
	{
		int lineno = 0;
		string line;
		while (getline(infile, line))
		{
			printf("line:%d,%s\n", lineno, line.c_str());
			lineno++;
		}
		infile.close();
	}

}
