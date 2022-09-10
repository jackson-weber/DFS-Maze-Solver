#include <stdio.h>
#include <stdlib.h>
#include "path.h"
#include "mazehelper.h"

char * read_path(char * pathFileName)
{
	FILE * inputPath = fopen(pathFileName, 'r');
	
	if (inputPath == NULL)
	{
		fprintf(stderr, "Error opening input path file\n");
	}
	
	int len = 0;
	while (!feof(inputPath))
	{
		fgetc(inputPath);
		len++;
	}

	if (fseek(inputPath, 0L, SEEK_SET) == -1)
	{
		fprintf(stderr, "Problem seeking to beginning of file\n");
		return NULL;
	}

	char * path = malloc(len * sizeof(char));
	
	fscanf(inputPath, "%s\n", path);

	if (fclose(inputPath))
	{
		fprintf(stderr, "Problem closing input file\n");
		return NULL;
	}
	
	return path;
}

int write_path(char * pathFileName, char * path)
{
	FILE * f = fopen(pathFileName, 'w');

	if (f == NULL)
	{
		fprintf(stderr, "Error opening output file");
		return EXIT_FAILURE;
	}
	
	fprintf(f, "%s", path);
	
	fclose(f);
	
	return EXIT_SUCCESS;
	
}

