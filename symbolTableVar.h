//variable symbol table implementation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct linked_list_of_function {
    char name[50];
    struct linked_list_of_function *next;
    struct linked_list_of_function *prev;
};

//init_function_list initializes an empty function list and returns a pointer to it
struct linked_list_of_function *init_function_list() {
    struct linked_list_of_function *head = NULL;
    return head;
};

//add_to_function_list adds a new function to the list by creating a new node and assigning the function name to it
void add_to_function_list(char *name[50], struct linked_list_of_function **function_list) {
    struct linked_list_of_function *temp = (struct linked_list_of_function *)malloc(sizeof(struct linked_list_of_function));
    strcpy(temp->name,*name);
    temp->next = NULL;


    if ((*function_list) == NULL) {
        *function_list = temp;
        temp->prev = NULL;
        return;
    }
    else {
        struct linked_list_of_function *temp2;
        temp2 = (*function_list);
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->prev = temp2;
        return;
    }
}


//struct contatining fields to store information about the variable like its name, type, kind, and value
struct VarSymTableEntry
{
	int itemID;
	char itemName[50];
	char itemKind[8];
	char itemType[8];
	int arrayLength;
	int intVal;
	double floatVal;
	char charVal[50];
	char functionName[50];
	char scope[50];
};


struct VarSymTableEntry symTabItems[100]; //symTabItems array contains all the entries in the symbol table
int symTabIndex = 0;					  //symTabIndex keeps track of the number of entries
int SYMTAB_SIZE = 30;                     //specifies the maximum number of entries that can be stored in the symbol table

void symTabAccess(void){
	printf("ACCESSED SYMBOLTABLE\n\n");
}

//creates a new entry in the symTabItems array and populates it with the given information
void add_Item_to_var_sym_table(char itemName[50], char itemKind[8], char itemType[8], int arrayLength, char *scope[50]){
	
	symTabItems[symTabIndex].itemID = symTabIndex;
	strcpy(symTabItems[symTabIndex].itemName, itemName);
	strcpy(symTabItems[symTabIndex].itemKind, itemKind);
	strcpy(symTabItems[symTabIndex].itemType, itemType);
	symTabItems[symTabIndex].intVal = 0;
	symTabItems[symTabIndex].floatVal = 0;
	strcpy(symTabItems[symTabIndex].charVal, "NULL");
	strcpy(symTabItems[symTabIndex].functionName, "NULL");
	symTabItems[symTabIndex].arrayLength = arrayLength;
	strcpy(symTabItems[symTabIndex].scope, scope);
	symTabIndex++;
	
}


//setVal, setfloatVal, and setcharVal functions are used to set the value of a variable in the symbol table
int setVal(char itemName[50], char intVal[50], char scope[50]){
	int intValint = atoi(intVal);
	printf("itemName: %s\n", itemName);
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope);	
		if( str1 == 0){
			symTabItems[i].intVal = intValint;
			printf("finished\n");
			return 1;
		}
	}
	return 0;
}

//function that sets the float value of variable with the given name and scope
double setfloatVal(char itemName[50], char intVal[50], char scope[50]){
	double intValint = atof(intVal);
	printf("float val: %f\n", intValint);
	printf("itemName: %s\n", itemName);
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope);	
		if( str1 == 0){
			symTabItems[i].floatVal = intValint;
			printf("finished\n");
			return 1;
		}
	}
	return 0;
}

//function sets the char value of an item in symbol table identified by name and scope 
int setcharVal(char itemName[50], char CharVal[50], char scope[50]){
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope);	
		if( str1 == 0){
			strcpy(symTabItems[i].charVal, CharVal);
			printf("finished\n");
			return 1;
		}
	}
	return 0;
}


//prints the contents of the variable symbol table
void showVarSymTable(){
	printf("----------------------------------------Globel Variable Symbol Table------------------------------------------\n");
	printf("itemID    itemName  intVal   floatVal    CharVal   itemKind    itemType   ArrayLength     FunName    itemScope\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	for (int i=0; i<symTabIndex; i++){
		printf("%5d %8s %9d \t%0.2f %9s %9s %11s %10d %14s %14s \n",symTabItems[i].itemID, symTabItems[i].itemName, symTabItems[i].intVal, symTabItems[i].floatVal, symTabItems[i].charVal, symTabItems[i].itemKind, symTabItems[i].itemType, symTabItems[i].arrayLength, symTabItems[i].functionName, symTabItems[i].scope);
	}
	printf("--------------------------------------------------------------------------------------------------------------\n");
}

//checks if a variable with the given name and scope exists in the symbol table 
//if it does the function returns 1 otherwise it returns 0
int found(char itemName[50], char scope[50]){
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		int str2 = strcmp(symTabItems[i].scope,scope); 
		if( str1 == 0 && str2 == 0){
			return 1;
		} 
	}
	return 0;
}

//function searches the sym table for specified item name and scope
int getVal(char itemName[50],char scope[50]){
	int returnNum;
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		int str2 = strcmp(symTabItems[i].scope,scope); 
			if( str1 == 0 && str2 == 0){
				returnNum = symTabItems[i].intVal;
				return symTabItems[i].intVal;
		
			}
	}

	return 0;
}

char *getCharVal(char itemName[50],char scope[50]){
	char returnNum;
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		int str2 = strcmp(symTabItems[i].scope,scope); 
			if( str1 == 0 && str2 == 0){
				returnNum = symTabItems[i].charVal;
				return symTabItems[i].charVal;
		
			}
	}

	return 0;
}

double getFloatVal(char itemName[50],char scope[50]){
	int returnNum;
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		int str2 = strcmp(symTabItems[i].scope,scope); 
			if( str1 == 0 && str2 == 0){
				returnNum = symTabItems[i].floatVal;
				return symTabItems[i].floatVal;
		
			}
	}

	return 0;
}

void printVal(){
	for(int i = 0; i < 4; i++) {
		printf("%7d\n", symTabItems[i].intVal);
	}
}


//searches the sym table for given itemName and scope then returns itemID associated with it if found
int getItemID(char itemName[50],char scope[50]){
	int returnID;
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		int str2 = strcmp(symTabItems[i].scope,scope); 
		if( str1 == 0 && str2 == 0){
			returnID = (int)(symTabItems[i].itemID)+0;
			return returnID; 
	
		}
	}
	return 0;
}

//searches the sym table for given itemName and scope then returns itemType associated with it if found
const char* getVariableType(char itemName[50], char scope[50]){

	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		int str2 = strcmp(symTabItems[i].scope,scope); 
		if( str1 == 0 && str2 == 0){
			return symTabItems[i].itemType;
		}
	}
	return NULL;
}

//compares the types of two variables identified by itemName and scope
//returns 1 if types match otherwise returns 0
int compareTypes(char itemName1[50], char itemName2[50],char scope){
	const char* idType1 = getVariableType(itemName1, scope);
	const char* idType2 = getVariableType(itemName2, scope);
	
	printf("%s = %s\n", idType1, idType2);
	
	int typeMatch = strcmp(idType1, idType2);
	if(typeMatch == 0){
		return 1; 
	}
	else return 0;
}


    