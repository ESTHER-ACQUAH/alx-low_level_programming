#include "dog.h"

/**
 * init_dog -  initializes a variable
 * @d: struct dog.
 * @name: firt name
 * @age: initialize age
 * @owner: initialize owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
d->name = name;
d->age = age;
d->owner = owner;
}
