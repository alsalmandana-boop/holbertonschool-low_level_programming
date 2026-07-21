 #include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space
 * containing a copy of the string
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string, or NULL
 */

char *_strdup(char *str)
{
    unsigned int length;
    unsigned int i;
    char *copy_str;

    if (str == NULL)
    {
    return (NULL);
    }

    length = 0; 
    while (str[length] != '\0')
    {
    length++;
    }

   copy_str = malloc (sizeof(char) * (length + 1));

   if (copy_str == NULL)
   {
    return(NULL);
   }
    i = 0;
    while (i < length)
    {
    copy_str[i] = str[i];
    i++;
    }
    
   
   return(copy_str);
}