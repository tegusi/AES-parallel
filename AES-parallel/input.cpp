//
//  input.cpp
//  AES-parallel
//
//  Created by tegusi on 2017/6/24.
//  Copyright © 2017年 tegusi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int read_sequence (
                  char    *s,          /* File name */
                unsigned char  *a, /* Array name */
                  int     *n)          /* Length of plain text */
{
    FILE    *fptr;          /* Input file pointer */
    
    fptr = fopen (s, "r");
    if (fptr == NULL) {
        printf("Error in reading text.");
        return 1;
    }
    fread (n, sizeof(int), 1, fptr);
    a = (unsigned char*)malloc((sizeof(unsigned char)) * (*n));
    fread (a, sizeof(unsigned char), *n, fptr);
    fclose (fptr);
    return 0;
}
