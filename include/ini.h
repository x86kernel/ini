#if !defined(_INI_H)
#define _INI_H

typedef struct _section {
    char *name;
    LINKEDLIST *settings;

	int settings_n;

    struct _section *next;
} SECTION;

typedef struct _ini {
    SECTION *sections;
} INI;

INI *parse_ini(char *, ARGS *);
SECTION *add_section(INI *, char *);
LISTNODE *parse_setting(SECTION *, char *, ARGS *);
LISTNODE *add_setting(SECTION *, char *, char *);
SECTION *get_section(INI *, char *);
char *get_section_var(SECTION *, char *);
void free_ini(INI *);
void print_ini(INI *);

#endif
