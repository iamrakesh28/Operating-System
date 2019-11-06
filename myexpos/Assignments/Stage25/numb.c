#include <stdio.h>

int main() {
	FILE *fp = fopen("numbers.dat", "w");
	for (int i = 1; i < 2048; ++i)
		fprintf(fp, "%d\n", i);
	fclose(fp);
	return 0;
}
