/****************************************************************
Implimentation of my file read and write library. 

@author Christina Kidwell
@version Fall 2018
****************************************************************/
#include "file_utils.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

/****************************************************************
Allocate memory and read file into a buffer.
@param *filename is the name of file to read
@param **buffer is the pointer to the buffer to store the file in 
@return size of file read
****************************************************************/
int read_file( char* filename, char **buffer ) {
    FILE *fp1;			//pointer to file
	struct stat st;		//structure to get file size

	// determine the size of the input file
	stat(filename, &st);
	int size = st.st_size;
	
	// if the file is empty then display error and exit
	if(size==0){
		fprintf(stderr, "Input file is empty");
		return 0;
	}
	
	// allocate memory to store file
	*buffer = malloc(size * sizeof(char));

	if(buffer == NULL){
		fprintf(stderr, "Memory could not be allocated");
		return 0;
	}
	// open the file as read only
    fp1= fopen(filename, "rb");
	
	// if file fails to open then display error and exit
	if(fp1 == NULL){
		fprintf(stderr, "File failed to open");
		return 0;
	}

	// Read file into buffer
	fread(*buffer, sizeof(char), size, fp1);
	
	// close file
    fclose(fp1);
    return size;
}
/****************************************************************
Write buffer to file.
@param *filename is the name of file to write
@param *buffer is a pointer to the buffer that outputs to a file
@param size is the number of bytes to output
@return 0 on completion 
****************************************************************/
int write_file( char* filename, char *buffer, int size){
	FILE *fp1;						//pointer to file
	fp1= fopen(filename, "wb");
	
	// if file fails to open then display error and exit
	if(fp1 == NULL){
		fprintf(stderr, "File failed to open");
		return 0;
	}
	int wrote = fwrite(buffer, sizeof(char), size, fp1);
	if(wrote!= size){
		fprintf(stderr, "File failed to write.");
	}
	fclose(fp1);
	return 0;
}
