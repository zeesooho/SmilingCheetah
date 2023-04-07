#include "error.h"

void error(char *errorMessage){
    printf("%s\n", errorMessage);
    exit(1);
}