#include <stdlib.h>

int **alloc_grid(int width, int height) {
if (width <= 0 || height <= 0) return NULL;
int **grid = malloc(sizeof(int *) * height);
    if (!grid) return NULL;
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(sizeof(int) * width);
if (!grid[i]) 
{
for (int j = 0; j < i; j++) 
{
free(grid[j]);
}
free(grid);
return (NULL);
}
for (int j = 0; j < width; j++) 
{
grid[i][j] = 0;
}
}
return (grid);
}

