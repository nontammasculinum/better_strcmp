#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define bstrcmp( p, p2, t ) b_strcmp(p, p2, t, false, __FILE__, __LINE__)
#define bstrcmp_d( p, p2, t ) b_strcmp(p, p2, t, true, __FILE__, __LINE__)
#define safe_bstrcmp( p, psz, p2, p2sz, t ) b_strcmp_safe(p, psz, p2, p2sz, t, false, __FILE__, __LINE__)
#define safe_bstrcmp_d( p, psz, p2, p2sz, t ) b_strcmp_safe(p, psz, p2, p2sz, t, true, __FILE__, __LINE__)

enum b_strtype { s_none, s_equal, s_greater, s_lesser };
int b_strcmp(char *p, char *p2, enum b_strtype t, bool debug, char *file, int line);
int b_strcmp_safe(char *p, int psz, char *p2, int p2sz, enum b_strtype t, bool debug, char *file, int line);


