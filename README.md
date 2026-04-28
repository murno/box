# Box

My take on basic C data structures. Nothing fancy, just works.

**Status:** Array ⏳ | List ❌ | Map ❌

## Usage

Clone into your project:

```Shell
$ git clone https://github.com/murno/box.git
```

Include and use:

```C
#include <stdlib.h>
#include <stdio.h>

#include "box/array.h"

int
main(void)
{
	BoxArray *a;
	size_t i;

	a = box_array_new();

	box_array_push(a, 2);
	box_array_push(a, 4);
	box_array_push(a, 8);

	for (i = 0; i < box_array_size(a); i++) {
		printf("%d ", box_array_at(a, i));
	}
	putchar('\n');

	box_array_delete(a);
	exit(EXIT_SUCCESS);
}
```

Compile:

```Shell
$ cc main.c box/array.c
```
