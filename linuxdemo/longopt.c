
#include <stdlib.h>
#include <stdio.h>		
#include <errno.h>		
#include <fcntl.h>		
#include <string.h>		
#include <unistd.h>		
#include <sys/types.h>
#include <sys/stat.h>		

// ./longopt --init -l --file=fred.c 'hi there'

#define _GNU_SOURCE
#include <getopt.h>

int main(int argc, char *argv[])
{
	int opt;
	/*
	struct option{
		const char *name;
		int has_arg;
		int *flag;
		int val;
	}
	*/
	struct option longopts[] = {
		{"initialize", 0, NULL, 'i'},
		{"file", 1, NULL, 'f'},
		{"list", 0, NULL, 'l'},
		{"restart", 0, NULL, 'r'},
		{0, 0, 0, 0},
	};

	while((opt = getopt_long(argc, argv, ":if:lr", longopts, NULL)) != -1)
	{
		switch(opt)
		{
			case 'i':
			case 'l':
			case 'r':
				printf("option:%c\n", opt);
				break;
			case 'f':
				printf("filename:%s\n", optarg);
				break;
			case ':':
				printf("option needs a value\n");
				break;
			case '?':
				printf("unknown option:%c\n", opt);
				break;
		}

	}
	for ( ; optind < argc; optind++)
	{
		printf("argument: %s\n", argv[optind]);
	}
		
	return 0;
}

