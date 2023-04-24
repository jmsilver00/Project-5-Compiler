//Functions for handeling intermediate representation (IR) code emissions 

FILE * IRcode;
int x = 20;
//initilizes file and writes the header for the start if the IR code section 
void  initIRcodeFile(){
    IRcode = fopen("IRcode.ir", "w");
    fprintf(IRcode, "\n\n#### IR Code ####\n\n");
    fclose(IRcode);
}
//IR code for a binary operation with the given operator op and operands id1 and id2
void emitBinaryOperation(char op[1], const char* id1, const char* id2){
    fprintf(IRcode, "T1 = %s %s %s", id1, op, id2);
    fclose(IRcode);
}

//IR code for an assignment operation, where the value of id2 is assigned to id1
void emitAssignment(char * id1, char * id2){

  fprintf(IRcode, "T0 = %s\n", id1);
  fprintf(IRcode, "T1 = %s\n", id2);
  fprintf(IRcode, "T1 = T0\n");
  fclose(IRcode);
}

//creates IR code for an assignment of a constant integer value id1 to a temporary variable with index id2
void emitConstantIntAssignment (char id1[50], int id2[50]){
    IRcode = fopen("IRcode.ir", "a");
    fprintf(IRcode, "T%d = %s\n",id2, id1);
    fclose(IRcode);
}

//creates IR code for an assignment of the value of id2 to a temporary variable with index curScope
void emitIRAssignment(char id1[50], char id2[50],int curScope[50]){
    IRcode = fopen("IRcode.ir", "a");
    fprintf(IRcode, "T%d = %s\n",curScope, id2);
    fclose(IRcode);
}

//this function is for writing the value of a temporary variable with a given ID
void emitWriteId(char * id){

    fprintf (IRcode, "output T%s\n", id);
    fclose(IRcode);
}

//assigns a constant integer value to a temporary variable with a unique index 
//the unique index is incremented each time this function is called
void emitConstantWhileAssignment (char id1[50]){
    IRcode = fopen("IRcode.ir", "a");
    fprintf(IRcode, "T%d = %s",x, id1);
    fclose(IRcode);
    x = x + 1;
}    