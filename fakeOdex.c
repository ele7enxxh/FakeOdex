#include <stdio.h>

unsigned int read4LE(FILE *fp)
{
    unsigned int val;

    val = getc(fp);
    val |= getc(fp) << 8;
    val |= getc(fp) << 16;
    val |= getc(fp) << 24;
    return val;
}

void write4LE(unsigned int val, FILE *fp)
{
	putc(val, fp);
	putc(val >> 8, fp);
	putc(val >> 16, fp);
	putc(val >> 24, fp);
}

unsigned int readInt(FILE *fp)
{
	unsigned int val;

	val = getw(fp);
	return val;
}

int main (int argc, char *argv[])
{
	char *sourceOdexPath;
	char *destODexPath;
	FILE *fp;
	unsigned int depsOffset;
	unsigned int modWhen;
	unsigned int crc;

	if (argc < 3) {
		return -1;
	}

	sourceOdexPath = argv[1];
	destODexPath = argv[2];

	fp = fopen(sourceOdexPath, "rb");
	if (fp == NULL) {
		fprintf(stderr, "fopen %s\n failed", sourceOdexPath);
		return -1;
	}
	fseek(fp, 16, SEEK_SET);
	depsOffset = readInt(fp);
	fseek(fp, depsOffset, SEEK_SET);
	modWhen = read4LE(fp);
	crc = read4LE(fp);
	printf("%s: modWheng=%08x, crc=%08x\n", sourceOdexPath, modWhen, crc);
	fclose(fp);

	fp = fopen(destODexPath, "rb+");
	if (fp == NULL) {
		fprintf(stderr, "fopen %s\n failed", destODexPath);
		return -1;
	}
	fseek(fp, 16, SEEK_SET);
	depsOffset = readInt(fp);
	fseek(fp, depsOffset, SEEK_SET);
	write4LE(modWhen, fp);
	write4LE(crc, fp);
	fseek(fp, depsOffset, SEEK_SET);
	modWhen = read4LE(fp);
	crc = read4LE(fp);
	printf("%s: modWheng=%08x, crc=%08x\n", destODexPath, modWhen, crc);
	fclose(fp);
}