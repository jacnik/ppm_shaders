#include <stdio.h>

int main()
{
	char name_buf[256];
	for (int i = 0; i < 60; ++i) {
		snprintf(name_buf, sizeof(name_buf), "output-%02d.ppm", i);
		const char *output_path = name_buf;
		FILE *f = fopen(output_path, "wb");
		int w = 16 * 60;
		int h = 9 * 60;
		
		fprintf(f, "P6\n");
		fprintf(f, "%d %d\n", w, h);
		fprintf(f, "255\n");

		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (((x + i)/60 + (y + i)/60)%2) {
					fputc(0xFF, f);
					fputc(0x00, f);
					fputc(0x00, f);
				} else {
					fputc(0x00, f);
					fputc(0x00, f);
					fputc(0x00, f);
				}
			}
		}
		fclose(f);
		printf("Generated %s\n", output_path);
	}

	return 0;
}
