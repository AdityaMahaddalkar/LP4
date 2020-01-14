#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"


typedef struct node{
	struct node *next;
	char *data_type, *variable_name;
	YYSTYPE data_value;
}node;

typedef struct symtab{
	node *root;
}symtab;


node* isPresent(symtab *stab, char *variable_name){
	if(stab->root == NULL){
		return NULL;
	}
	else{
		node *current = stab->root;
		while(current != NULL){
			if(strcmp(current->variable_name, variable_name) == 0){
				return current;
			}
			current = current->next;
		}
		if(current == NULL){
			return NULL;
		}
	}
	return NULL;
}

void addVariableWithoutValue(symtab *stab, char *var_name){
	//printf("DEBUG: Executing addVariableWithoutValue %s\n", datatype);
	node *current;

	if((current = isPresent(stab, var_name)) != NULL){
		fprintf(stderr, "ERROR: Variable %s redeclaration\n", var_name);
		return;
	}

	if(stab->root == NULL){

		stab->root = malloc(sizeof(node));
		stab->root->variable_name = strdup(var_name);
	}
	else{

		current = stab->root;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = malloc(sizeof(node));
		current = current->next;
		current->variable_name = strdup(var_name);

	}
}

void addString(symtab *stab, char *var_name, char *value){
	//printf("DEBUG: Executing Addchar()\n");
	node *current;
	if((current = isPresent(stab, var_name)) != NULL){

		fprintf(stderr, "ERROR:%s already present in SYMTAB\n", var_name);
		exit(-1);

	}

	if(stab->root == NULL){

		stab->root = malloc(sizeof(node));
		stab->root->data_type = "char";
		stab->root->variable_name = strdup(var_name);
		stab->root->data_value.sValue = strdup(value);
	}
	else{

		current = stab->root;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = malloc(sizeof(node));
		current = current->next;
		current->data_type = "char";
		current->variable_name = strdup(var_name);
		current->data_value.sValue = strdup(value);
	}

}

void addInt(symtab *stab, char *var_name, int value){
	//printf("DEBUG: Executing AddInt()\n");
	node *current;
	if((current = isPresent(stab, var_name)) != NULL){

		fprintf(stderr, "ERROR:%s already present in SYMTAB\n", var_name);
		exit(-1);

	}

	if(stab->root == NULL){

		stab->root = malloc(sizeof(node));
		stab->root->data_type = "int";
		stab->root->variable_name = strdup(var_name);
		stab->root->data_value.iValue = value;
	}
	else{

		current = stab->root;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = malloc(sizeof(node));
		current = current->next;
		current->data_type = "int";
		current->variable_name = strdup(var_name);
		current->data_value.iValue = value;
	}

}

void addFloat(symtab *stab, char *var_name, float value){
	//printf("DEBUG: Executing Addfloat()\n");
	node *current;
	if((current = isPresent(stab, var_name)) != NULL){

		fprintf(stderr, "ERROR:%s already present in SYMTAB\n", var_name);
		//current->data_value.fValue = value;
		exit(-1);

	}

	if(stab->root == NULL){

		stab->root = malloc(sizeof(node));
		stab->root->data_type = "float";
		stab->root->variable_name = strdup(var_name);
		stab->root->data_value.fValue = value;
	}
	else{

		current = stab->root;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = malloc(sizeof(node));
		current = current->next;
		current->data_type = "float";
		current->variable_name = strdup(var_name);
		current->data_value.fValue = value;
	}

}

void assignVariableToVariable(symtab *stab, char *assigner, char *assignee){
	//VAR = VAR;

	node *assigner_pointer, *assignee_pointer;
	if((assigner_pointer = isPresent(stab, assigner)) != NULL && (assignee_pointer = isPresent(stab, assignee)) != NULL){

		if(strcmp(assigner_pointer->data_type, "int") && strcmp(assignee_pointer->data_type, "int")){

			assigner_pointer->data_value.iValue = assignee_pointer->data_value.iValue;
		}

		else if(strcmp(assigner_pointer->data_type, "float") && strcmp(assignee_pointer->data_type, "float")){

			assigner_pointer->data_value.fValue = assignee_pointer->data_value.fValue;
		}

		else if(strcmp(assigner_pointer->data_type, "char") && strcmp(assignee_pointer->data_type, "char")){

			assigner_pointer->data_value.sValue = assignee_pointer->data_value.sValue;
		}

		else{
			fprintf(stderr, "%s and %s are incompatible in terms of data types\n", assigner, assignee);
		}

	}

	else if((assigner_pointer = isPresent(stab, assigner)) == NULL){
		fprintf(stderr, "%s doesnot exist in symbol table\n", assigner);
	}

	else if((assignee_pointer = isPresent(stab, assignee)) != NULL){
		fprintf(stderr, "%s doesnot exist in symbol table\n", assignee);
	}

	else{
		fprintf(stderr, "CRITICAL: While assigning %s = %s\n", assigner, assignee);
	}

}


void assignNumberToVariable(symtab *stab, char *var_name, int value){
	//VAR = NUM;

	node *current;
	if((current = isPresent(stab, var_name)) != NULL){
		if(strcmp(current->data_type, "int")==0){
			current->data_value.iValue = value;
			return;
		}
		

	}
	else{

		fprintf(stderr, "%s doesnot exist in symbol table or invalid datatype\n", var_name);
		exit(-1);
	}

}

void assignFNumberToVariable(symtab *stab, char *var_name, float value){
	//VAR = NUM;

	node *current;
	if((current = isPresent(stab, var_name)) != NULL){
		if(strcmp(current->data_type, "float")==0){
			current->data_value.fValue = value;
			return;
		}
	}
	else{

		fprintf(stderr, "%s doesnot exist in symbol table of invalid datatype\n", var_name);
		exit(-1);
	}

}

void assignStringToVariable(symtab *stab, char *var_name, char *value){
	node *current;
	if((current = isPresent(stab, var_name)) != NULL){
		if(strcmp(current->data_type, "char")==0){
			current->data_value.sValue = strdup(value);
			return;
		}
	}
	else{

		fprintf(stderr, "%s doesnot exist in symbol table of invalid datatype\n", var_name);
		exit(-1);
	}
}


void printSymtab(symtab *stab){
	printf("------------------------------\n");
	printf("Printing SYMTAB\n");
	printf("------------------------------\n");
	node *current = stab->root;
	while(current != NULL){

		if(strcmp(current->data_type, "char") == 0){

			printf("NODE:  [%s\t%s\t%s]\n", current->data_type, current->variable_name, current->data_value.sValue);
		}
		else if(strcmp(current->data_type, "int") == 0){

			printf("NODE:  [%s\t%s\t%d]\n", current->data_type, current->variable_name, current->data_value.iValue);
		}
		else if(strcmp(current->data_type, "float") == 0){

			printf("NODE:  [%s\t%s\t%f]\n", current->data_type, current->variable_name, current->data_value.fValue);
		}

		current = current->next;

	}
}

void checkDatatype(symtab *stab, char *datatype, char var_name[256][128], int iterator){

	node *current;
	for(int i = 0;i < iterator;i ++){

		if((current = isPresent(stab, var_name[i])) != NULL){

			if(current->data_type == NULL){
				current->data_type = strdup(datatype);
			}
			else if(strcmp(current->data_type, datatype)!=0){
				fprintf(stderr, "ERROR: %s datatype %s is erroneous\n", current->variable_name, current->data_type);
				exit(-1);
			}
		}

		else{
			fprintf(stderr, "ERROR: %s doesnot exist in symbol_table\n", var_name[i]);
			exit(-1);
		}
	}

}

int returnIntegerValue(symtab *stab, char *var_name){
	node *current;

	if((current = isPresent(stab, var_name)) != NULL){
		if(strcmp(current->data_type, "int")!=0){
			fprintf(stderr, "ERROR: %s is not integer\n", var_name);
			return 0;
		}
		return current->data_value.iValue;
	}
	else{
		fprintf(stderr, "ERROR: %s variable doesnot exist\n", var_name);
		exit(-1);
	}
}

float returnFloatValue(symtab *stab, char *var_name){
	node *current;

	if((current = isPresent(stab, var_name)) != NULL){
		if(strcmp(current->data_type, "float")!=0){
			fprintf(stderr, "ERROR: %s is not float\n", var_name);
			return 0;
		}
		return current->data_value.fValue;
	}
	else{
		fprintf(stderr, "ERROR: %s variable doesnot exist\n", var_name);
		exit(-1);
	}
}

int returnArithmeticOperationInt(int a, char *op, int b){
	printf("a op b: %d %s %d", a, op, b);
	if(strcmp(op, "+") == 0)
		return a+b;
	else if(strcmp(op, "-") == 0)
		return a-b;
	else if(strcmp(op, "*") == 0)
		return a*b;
	else if(strcmp(op, "/") == 0)
		return a/b;
	else{
		fprintf(stderr, "ERROR: %s operation not defined\n", op);
		exit(-1);
	}
}

float returnArithmeticOperationFloat(float a, char *op, float b){
	if(strcmp(op, "+") == 0)
		return a+b;
	else if(strcmp(op, "-") == 0)
		return a-b;
	else if(strcmp(op, "*") == 0)
		return a*b;
	else if(strcmp(op, "/") == 0)
		return a/b;
	else{
		fprintf(stderr, "ERROR: %s operation not defined\n", op);
		exit(-1);
	}

}

char* returnDataType(symtab *stab, char *var_name){
	node *current;

	if((current = isPresent(stab, var_name)) != NULL){
		return current->data_type;
	}
	else{
		fprintf(stderr, "ERROR: %s variable doesnot exist\n", var_name);
		exit(-1);
	}
}

//😖️
