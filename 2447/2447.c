#include <stdio.h>
#include <malloc.h>
#include <string.h>

void draw_window(char**map, int window_size, int x, int y) {
	if (window_size == 1) {
		map[y][x] = '*';
		return;
	}

	int width = window_size / 3;
	draw_window(map, width, x, y);
	draw_window(map, width, x + width, y);
	draw_window(map, width, x + width * 2, y);

	draw_window(map, width, x, y + width);
	draw_window(map, width, x + width * 2, y + width);

	draw_window(map, width, x, y + width * 2);
	draw_window(map, width, x + width, y + width * 2);
	draw_window(map, width, x + width * 2, y + width * 2);
}

int main(void) {
	int N;
	char** map;

	scanf("%d", &N);
	map = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		map[i] = (char*)malloc(sizeof(char) * N);
		memset(map[i], 0, sizeof(char) * N);
	}
	
	draw_window(map, N, 0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) putc(' ', stdout);
			else printf("%c", map[i][j]);
		}
		free(map[i]);
		putc('\n', stdout);
	}
	free(map);
	return 0;
}
