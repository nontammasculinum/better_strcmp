#include "betterstrcmp.h"

#define bstrcmp( p, p2, t ) bstrcmp(p, p2, t, false, __FILE__, __LINE__)
#define bstrcmp_d(p, p2, t) bstrcmp(p, p2, t, true, __FILE__, __LINE__)

enum b_strtype { s_none, s_equal, s_greater, s_lesser };
int b_strcmp(char *p, char *p2, enum strtype t, bool debug, char *file, int line) {
	char *c, *c2;
	switch(t) {
		case none:
			for(c = p, c2 = p2; *c == *c2; c++, c2++)
				if(*c == '\0') return *c - *c2;
			return *c - *c2;
		case equal:
			c = p; c2 = p2;
			while(*c++ && *c2++)
				if(*c != *c2) return 0;
			return 1;
		case lesser:
			c = p; c2 = p2;
			while(*c++ && *c2++)
				if(*c > *c2) return 0;
			return 1;
		case greater:
			c = p; c2 = p2;
			while(*c++ && *c2++)
				if(*c < *c2) return 0;
			return 1;
		default:
			if(debug) printf("Invalid usage, add a type correlating to the strtype enum.\nerror at: (%s, %d)\n", file, line);
			return 0;
	}
}

