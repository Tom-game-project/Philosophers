#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct s_data t_data;

struct s_data
{	
	int x;
	int y;
};

t_data *init(int length)
{
	int i;
	t_data *a;

	a = malloc(sizeof(t_data) * length);

	i = 0;
	while (i < LENGTH)
	{
		a[i].x = 1 * i;
		a[i].y = 2 * i;
		i += 1;
	}
	return (a);
}

void show_data(t_data *a, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		printf(
			"x: %d"
			" y: %d\n", 
			a[i].x,
			a[i].y
		);
		i += 1;
	}
}

/// ```bash
/// make example EXAMPLE_FILE=examples/example_adr.c
/// ```
int main()
{
	t_data *a;

	a = init(LENGTH);

	show_data(a, LENGTH);

	free(a);

	return (0);
}
