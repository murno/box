# Box

## Usage

```Shell
$ git clone https://github.com/murno/box.git
```

### Example
```C
#include <stdlib.h>
#include <stdio.h>

#include "array.h"

void
print_box_array(BoxArray *a)
{
	size_t i;

	for (i = 0; i < box_array_size(a); i++) {
		printf("%d ", box_array_at(a, i));
	}
	putchar('\n');
}

int
main(void)
{
	BoxArray *a;

	a = box_array_new();

	box_array_push(a, 2);
	box_array_push(a, 4);
	box_array_push(a, 8);

	print_box_array(a);

	box_array_pop(a);
	box_array_set(a, box_array_size(a) - 1, 16);

	print_box_array(a);

	box_array_delete(a);
	exit(EXIT_SUCCESS);
}
```

### Build
```Shell
$ cc main.c box/array.c
$ ./a.out
```
