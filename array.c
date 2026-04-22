#include "array.h"

#include <stdlib.h>

struct box_array {
	int *elements;
	size_t count;
	size_t capacity;
};

BoxArray *
box_array_new(void)
{
	BoxArray *a;

	a = malloc((sizeof *a));
	a->elements = NULL;
	a->count = 0;
	a->capacity = 0;

	return a;
}

void
box_array_delete(BoxArray *a)
{
	free(a->elements);
	free(a);
}

void
box_array_push(BoxArray *a, int e)
{
	if (a->count == a->capacity) {
		a->capacity = (a->capacity == 0) ? 1 : a->capacity * 2;
		a->elements = realloc(a->elements, a->capacity * (sizeof *a->elements));
	}

	a->elements[a->count] = e;
	a->count++;
}

void
box_array_pop(BoxArray *a)
{
	a->count--;
}

int
box_array_at(BoxArray *a, size_t i)
{
	return a->elements[i];
}

void
box_array_set(BoxArray *a, size_t i, int e)
{
	a->elements[i] = e;
}

size_t
box_array_size(BoxArray *a)
{
	return a->count;
}
