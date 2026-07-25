#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 * Return: pointer to the new dog, or NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	unsigned int name_len = 0, owner_len = 0, i = 0;

	while (name[name_len] != '\0')
		name_len++;
	while (owner[owner_len] != '\0')
		owner_len++;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);
	dog->name = malloc(name_len + 1);
	if (dog->name == NULL)
		return (free(dog), NULL);
	dog->owner = malloc(owner_len + 1);
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	while (i <= name_len)
		dog->name[i] = name[i], i++;
	i = 0;
	while (i <= owner_len)
		dog->owner[i] = owner[i], i++;
	dog->age = age;
	return (dog);
}
