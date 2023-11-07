#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Defines a structure named dog
 * @name: dog name denoted
 * @owner: person who owns dog
 * @age: dog's age
 *
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
typedef struct dog dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
