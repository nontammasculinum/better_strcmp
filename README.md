# better_strcmp
A small c library so you can finally say goodby to having to think about strcmp.

This is likely a very specific problem to me, but basically strcmp is annoying and its return type doesn't make sense.

So instead I made a function that does the same thing but you get to choose whether or not its fucky.

So the function prototypes looks as so:
```
int b_strcmp(char *p, char *p2, enum b_strtype t, bool debug, char *file, int line);
int b_strcmp_safe(char *p, int psz, char *p2, int p2sz, enum b_strtype t, bool debug, char *file, int line);
```
There are a few things you probably dont want to touch so here is what the interfacing macros look like.
```
#define bstrcmp( p, p2, t ) b_strcmp(p, p2, t, false, __FILE__, __LINE__)
#define bstrcmp_d( p, p2, t ) b_strcmp(p, p2, t, true, __FILE__, __LINE__)
#define safe_bstrcmp( p, psz, p2, p2sz, t ) b_strcmp_safe(p, psz, p2, p2sz, t, false, __FILE__, __LINE__)
#define safe_bstrcmp_d( p, psz, p2, p2sz, t ) b_strcmp_safe(p, psz, p2sz, t, true, __FILE__, __LINE__)
```
You may have noted that there is an enum `b_strtype` which must be passed into the functions as `t`.

This enum looks like this:
```
enum b_strtype { s_none, s_equal, s_greater, s_lesser };
```
s_none just makes the function act like normal strcmp (except with some debugging/safety if you opt into that), s_equal just checks if the strings are equal, s_greater checks if the strings are greater, and s_lesser checks if they are lesser. An example of the usage of this library would be as so:
```
#include <stdio.h>
#include "betterstrcmp.h"
#include "betterstrcmp.c"

int main() {
  char *p = "hello";
  char *p2 = "hello";
  if(safe_bstrcmp(p, 6, p2, 6, s_equal)) {
    printf("working!!");
  }
}
```
Hope it works lol!
