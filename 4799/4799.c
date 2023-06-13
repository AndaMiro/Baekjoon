#include <stdio.h>
#include <math.h>

void kantor(int start, int length) {
	if (length == 1) {
		fputc('-', stdout);
		return;
	}

	int part = length / 3;
	kantor(start, part);
	for (int i = 0; i < part; i++) putc(' ', stdout);
	kantor(start, part);
}

int main(void) {
	int N, length;
	while (scanf("%d", &N) != EOF) {
		length = pow(3, N);
		kantor(0, length);
		putc('\n', stdout);
	}
	return 0;
}
