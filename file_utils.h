/****************************************************************
Header file for my file read and write library. 

@author Christina Kidwell
@version Fall 2018
****************************************************************/
#ifndef _H_MY_LIBRARY_ 
#define _H_MY_LIBRARY_

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);

#endif
