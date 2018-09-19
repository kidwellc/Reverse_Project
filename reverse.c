/****************************************************************
Program that reads in a file and outputs it in reverse order to 
another file. 

@author Christina Kidwell
@version Fall 2018
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

/****************************************************************
Main that reads in a file and outputs it in reverse order to 
another file. 
@param input file name
@param output file name
@return 0 on completion 
****************************************************************/
int main(int argc, char** argv){
	char* buffer; 		//buffer to store file in
	int size=0;			//number of bytes in file
	
	// verify that we only have 2 parameters
	if(argc != 3){
		fprintf(stderr, "Incorrect number of parameters");
		return 0;
	}

	// read the file into buffer
	size=read_file( argv[1], &buffer );

	// if we failed to read the file then exit
	if(size<1){
		return 0;
	}
// Used for testing fread.
//	for(int i=0; i<size; i++)
//		printf("%c", buffer[i]);
//	printf("\n");
	
	//reverse the file
	for(int i=0; i<size-1-i; i++){
		char temp = buffer[i];
		buffer[i] = buffer[size-1-i];
		buffer[size-1-i] = temp;
	}
	
//	test for reverse
//	for(int i=0; i<size; i++)
//		printf("%c", buffer[i]);
//	printf("\n");
	
	
	// write out the file 
	write_file( argv[2], buffer, size);
	free(buffer);
	return 0;
}