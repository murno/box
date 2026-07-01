#pragma once

#include <stddef.h>

typedef struct box_array BoxArray;

BoxArray *box_array_new(void);

void box_array_delete(BoxArray *a);

void box_array_push(BoxArray *a, int e);

void box_array_pop(BoxArray *a);

int box_array_at(BoxArray *a, size_t i);

void box_array_set(BoxArray *a, size_t i, int e);

size_t box_array_size(BoxArray *a);
