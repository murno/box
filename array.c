#include "array.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

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
	if (a == NULL) {
		perror("box_array_new: malloc failed");
		abort();
	}

	a->elements = NULL;
	a->count = 0;
	a->capacity = 0;

	return a;
}

void
box_array_delete(BoxArray *a)
{
	if (a != NULL) {
		free(a->elements);
		free(a);
	}
}

void
box_array_push(BoxArray *a, int e)
{
	assert(a != NULL);

	if (a->count == a->capacity) {
		a->capacity = (a->capacity == 0) ? 1 : a->capacity * 2;
		a->elements = realloc(a->elements, a->capacity * (sizeof *a->elements));
		if (a->elements == NULL) {
			perror("box_array_push: realloc failed");
			abort();
		}
	}

	a->elements[a->count] = e;
	a->count++;
}

void
box_array_pop(BoxArray *a)
{
	assert(a != NULL);
	assert(a->count > 0);

	a->count--;
}

int
box_array_at(BoxArray *a, size_t i)
{
	assert(a != NULL);
	assert(i < a->count);

	return a->elements[i];
}

void
box_array_set(BoxArray *a, size_t i, int e)
{
	assert(a != NULL);
	assert(i < a->count);

	a->elements[i] = e;
}

size_t
box_array_size(BoxArray *a)
{
	assert(a != NULL);

	return a->count;
}
