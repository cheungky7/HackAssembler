
#include <stdio.h>
#include "parser.h"

using namespace std;

int main(int argc, char **argv){

    for (int i = 0; i < argc; ++i){
        printf("arg%d is %s\n",i,argv[i]);
    }
    //string fileName(argv[0]);

    scanfile(argv[1]);
    return 0;
}
