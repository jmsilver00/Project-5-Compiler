//functions for managing temporary files used in the implementation of while loops within the compiler

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//appends a given string representing a variable name to a text file 
void write_var_to_string(char var_array[50]){
    FILE * VarFile;
    VarFile = fopen("./WhileOps/static/vars.txt", "a");
    fprintf(VarFile,"%s", var_array);
    fclose(VarFile);
}   

//writes a given string representing a while loop condition to a text file named "cond.txt"
void write_cond_to_string(char cond_array[50]){
    FILE * CondFile;
    CondFile = fopen("./WhileOps/static/cond.txt", "w");
    fprintf(CondFile,"%s", cond_array);
    fclose(CondFile);
}

//appends a given string representing a while loop body to a text file named "block.txt"
void write_block_to_string(char while_array[50]){
    FILE * WhileFile;
    WhileFile = fopen("./WhileOps/static/block.txt", "a");
    fprintf(WhileFile,"%s", while_array);
    fclose(WhileFile);
}

//removes the content of the "block.txt" file
void clearBlockFile(){
    char clearCMD[50], clearCMD2[50];
    strcpy(clearCMD, "rm -f ./WhileOps/static/block.txt" );
	system(clearCMD);
}

//creates a new empty "block.txt" file if it does not exist
void create_block_file(){
    char clearCMD[50], clearCMD2[50];
    strcpy(clearCMD, "touch ./WhileOps/static/block.txt" );
	system(clearCMD);
}

//removes the content of the "vars.txt" file
void clearVarFile(){
    char clearCMD[50], clearCMD2[50];
    strcpy(clearCMD, "rm -f ./WhileOps/static/vars.txt" );
	system(clearCMD);
}

//creates a new empty "vars.txt" file if it does not exist
void create_Var_file(){
    char clearCMD[50], clearCMD2[50];
    strcpy(clearCMD, "touch ./WhileOps/static/vars.txt" );
	system(clearCMD);
}