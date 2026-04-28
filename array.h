#pragma once

#include <stddef.h>

/**
 * @brief Dynamic array type for storing integers that automatically grows when needed.
 *
 * The internal implementation is hidden from the user.
 */
typedef struct box_array BoxArray;

/**
 * @brief Creates a new empty array.
 *
 * @return Pointer to a new allocated array. Abort on allocation failure.
 * @note Must be freed with `box_array_delete()`.
 */
BoxArray *box_array_new(void);

/**
 * @brief Destroys the box array and frees all associated memory.
 *
 * @param a Pointer to the array to delete. Safe to pass `NULL`.
 */
void box_array_delete(BoxArray *a);

/**
 * @brief Appends an element to the end of the array.
 *
 * Automatically reallocates and doubles capacity if needed.
 * First element causes capacity to grow from 0 to 1.
 *
 * @param a Pointer to the array (must not be `NULL`).
 * @param e Element to add.
 * @warning Assertion fails if `a` is `NULL`.
 * @warning Aborts if reallocation fails.
 */
void box_array_push(BoxArray *a, int e);

/**
 * @brief Removes the last element from the array.
 *
 * @param a Pointer to the array (must not be `NULL`).
 * @warning Assertion fails if `a` is `NULL` or array is empty.
 */
void box_array_pop(BoxArray *a);

/**
 * @brief Access element at given index.
 *
 * @param a Pointer to the array (must not be `NULL`).
 * @param i Index. Must be less than current size.
 * @return Value at index `i`.
 * @warning Assertion fails if `a` is `NULL` or `i >= box_array_size(a)`.
 */
int box_array_at(BoxArray *a, size_t i);

/**
 * @brief Overwrite element at given index with a new value.
 *
 * @param a Pointer to the array (must not be `NULL`).
 * @param i Index. Must be less than current size.
 * @param e New value to assign.
 * @warning Assertion fails if index is out of bounds.
 */
void box_array_set(BoxArray *a, size_t i, int e);

/**
 * @brief Return the number of elements currently in the array.
 *
 * @param a Pointer to the array (must not be NULL).
 * @return Current element count.
 */
size_t box_array_size(BoxArray *a);
