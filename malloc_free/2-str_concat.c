#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the concatenated string, or NULL
 */

char *str_concat(char *s1, char *s2)
{
unsigned int len1;
unsigned int len2;
unsigned int sum_s;
unsigned int i;
unsigned int j;
char *str_cat;

i = 0;
j = 0;

if (s1 == NULL)
	s1 = "";

if (s2 == NULL)
	s2 = "";

len1 = 0;
while (s1[len1] != '\0')
{
    ++len1;
}

len2 = 0;
while (s2[len2] != '\0')
{
    ++len2;
}

sum_s = len1 + len2;

str_cat = malloc(sizeof(char) * (sum_s + 1));
if (str_cat == NULL)
	return (NULL);


while (s1[i] != '\0')
{
    str_cat[i] = s1[i];
    i++;
}


while (s2[j] != '\0')
{
    str_cat[i] = s2[j];
    i++;
    j++;
}

str_cat[i] = '\0';

return(str_cat);
}