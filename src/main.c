#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "linkedlist.h"
#include "misc.h"
#include "ini.h"

void usage(char *name)
{
    fprintf(stderr, "USAGE: %s <file> <options>\n\n", name);
    fprintf(stderr, "Options:\n\t");
    fprintf(stderr, "-c, --comment\t\tShow all comments\n");
    exit(1);
}

/* get_optlong
 * return optlong code
 *
 * @argv argument string
 */
int get_optlong(char *argv)
{
	if(strlen(argv) > 2 && argv[0] == '-' && argv[1] == '-')
		return 1;
	else if((strlen(argv) == 2) && (argv[0] == '-'))
		return 0;
	else return -1;
}

ARGS *parseargs(int argc, char *argv[])
{
#define ARGUMENTS_N 2
#define add_args(s) AddNode(args, "args", s, strlen(s))
	int iargc, iopt;
	char *optstring = "ca";
	const struct option opt[ARGUMENTS_N] = {{"comment"}, {"printall"}};
	ARGS *args = xmalloc(sizeof(LINKEDLIST));

	if(argc < 3)
		return NULL;
	else {
		for(iargc = 2; iargc < argc; iargc++) {
			switch(get_optlong(argv[iargc])) {
				case 0:
					if(strchr(optstring, argv[iargc][1]))
						add_args(opt[strchr(optstring, argv[iargc][1]) - optstring].fulloptstring);
					else return (ARGS *)-1;
					break;
				case 1:
					for(iopt = 0; iopt < ARGUMENTS_N; iopt++) {
						if(!strcmp(&argv[iargc][2], opt[iopt].fulloptstring)) {
							add_args(&argv[iargc][2]);
							break;
						}
					}
					if(iopt == ARGUMENTS_N)
						return (ARGS *)-1;
					break;
				case -1:
					return (ARGS *)-1;
			}
		}
	}
	return args;
}

int main(int argc, char *argv[])
{
    INI *ini;
    ARGS *args;

    if (argc < 2)
        usage(argv[0]);

    args = parseargs(argc, argv);
    if(args == -1) {
	    fprintf(stderr, "Wrong Option\n");
	    usage(argv[0]);	    
    }
    ini = parse_ini(argv[1], args);
    if(!ini)
	    fprintf(stderr, "check the file\n");
    print_ini(ini);

    return 0;
}
