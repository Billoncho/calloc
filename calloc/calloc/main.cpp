/*
Author:    Billy Gene Ridgeway
Purpose:   Learn the difference between "calloc" and "malloc".
Date:      June 30th. 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Look at the command calloc and memory leaks.
int main() {
	char *s;    
	int i;
	int *p;
    
    printf("\n");
	// Use malloc first to allocate some memory and see what is in it (usually garbage).
	s = (char*)malloc(6);						// Malloc will return NULL (0) if it fails, so we should check here, but we won't for brevity.
	for (i = 0; i < 6; i++) printf("s[%d]=%d\n", i, s[i]);
	free(s);	                                // Use 'free' to return the memory so that we don't get a memory leak.
    
    printf("\n");
												// Now we'll use calloc to do the same - note that the memory is 'zeroed out'.
												// NOTE: the syntax of 'calloc' is different for 'malloc' - the second argument gives the size of the memory unit to allocate.
	s = (char*)calloc(6, sizeof(char));			// Calloc will return 0 if it fails, so we should check here, but we won't for brevity.
	for (i = 0; i < 6; i++) printf("s[%d]=%d\n", i, s[i]);
	free(s);
    
    printf("\n");

	// In this last example, 'calloc' allocates 6 integers, or 24 bytes, since an integer is 4 bytes long.
	p = (int*)calloc(6, sizeof(int));				// Calloc will return 0 if it fails, so we should check here, but we won't for brevity
	for (i = 0; i < 6; i++) printf("p[%d]=%d\n", i, p[i]);
	free(p);
    
    printf("\n");

	return 0;
}

