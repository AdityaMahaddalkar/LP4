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
}

void addVariableWithoutValue(symtab *stab, char *datatype, char *var_name){
	printf("DEBUG: Executing addVariableWithoutValue %s\n", datatype);
	node *current;
	
	//Change datatype string for our convenience
	
	if(strcmp(datatype, "int") == 0){
		datatype = "INTEGER";
	}
	else if(strcmp(datatype, "float") == 0){
		datatype = "FLOAT";
	}
	else if(strcmp(datatype, "char") == 0){
		datatype = "STRING";
	}
	
	if((current = isPresent(stab, var_name)) != NULL){
		fprintf(stderr, "ERROR: Variable %s redeclaration\n", var_name);
		return;
	}
	
	if(stab->root == NULL){
		
		stab->root = malloc(sizeof(node));
		stab->root->data_type = strdup(datatype);
		stab->root->variable_name = strdup(var_name);
	}
	else{
	
		current = stab->root;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = malloc(sizeof(node));
		current = current->next;
		current->data_type = strdup(datatype);
		current->variable_name = strdup(var_name);

	}
}

void addString(symtab *stab, char *var_name, char *value){
	//printf("DEBUG: Executing AddString()\n");
	node *current;
	if((current = isPresent(stab, var_name)) != NULL){
	
		//printf("INFO:%s already present in SYMTAB\n", var_name);
		current->data_value.sValue = strdup(value);
		return;

	}

	if(stab->root == NULL){
		
		stab->root = malloc(sizeof(node));
		stab->root->data_type = "STRING";
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
		current->data_type = "STRING";
		current->variable_name = strdup(var_name);
		current->data_value.sValue = strdup(value);
	}
	
}

void addInt(symtab *stab, char *var_name, int value){
	//printf("DEBUG: Executing AddInt()\n");
	node *current;
	if((current = isPresent(stab, var_name)) != NULL){
	
		//printf("INFO:%s already present in SYMTAB\n", var_name);
		current->data_value.iValue = value;
		return;

	}

	if(stab->root == NULL){
		
		stab->root = malloc(sizeof(node));
		stab->root->data_type = "INTEGER";
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
		current->data_type = "INTEGER";
		current->variable_name = strdup(var_name);
		current->data_value.iValue = value;
	}
	
}

void addFloat(symtab *stab, char *var_name, float value){
	//printf("DEBUG: Executing AddFloat()\n");
	node *current;
	if((current = isPresent(stab, var_name)) != NULL){
	
		//printf("INFO:%s already present in SYMTAB\n", var_name);
		current->data_value.fValue = value;
		return;

	}

	if(stab->root == NULL){
		
		stab->root = malloc(sizeof(node));
		stab->root->data_type = "FLOAT";
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
		current->data_type = "FLOAT";
		current->variable_name = strdup(var_name);
		current->data_value.fValue = value;
	}
	
}

void printSymtab(symtab *stab){
	printf("------------------------------\n");
	printf("Printing SYMTAB\n");
	printf("------------------------------\n");
	node *current = stab->root;
	while(current != NULL){
		
		if(strcmp(current->data_type, "STRING") == 0){
		
			printf("NODE:  [%s\t%s\t%s]\n", current->data_type, current->variable_name, current->data_value.sValue);
		}
		else if(strcmp(current->data_type, "INTEGER") == 0){

			printf("NODE:  [%s\t%s\t%d]\n", current->data_type, current->variable_name, current->data_value.iValue);
		}
		else if(strcmp(current->data_type, "FLOAT") == 0){
		
			printf("NODE:  [%s\t%s\t%f]\n", current->data_type, current->variable_name, current->data_value.fValue);
		}
		
		current = current->next;
		
	}
}

//😖️
