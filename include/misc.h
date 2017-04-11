#if !defined(_MISC_H)
#define _MISC_H

typedef void ARGS;

struct option {
	char *fulloptstring;
};

void *xmalloc(size_t);
ssize_t readf(char *, size_t, FILE *);

#endif
