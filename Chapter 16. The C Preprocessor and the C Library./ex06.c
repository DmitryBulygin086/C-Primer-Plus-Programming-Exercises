// Modify Listing 16.17 so that it uses an array of struct names elements (as defined after
// the listing) instead of an array of double. Use fewer elements, and initialize the array
// explicitly to a suitable selection of names.

#include "ex01.h"
#include <stdlib.h>
#include <string.h>

#define ARRLEN 15
#define NAMELEN 20

typedef struct names {
    char first[NAMELEN];
    char last[NAMELEN];
} Names;

int compare(const void *p1, const void *p2);
int main(void)
{
    Names someNames[ARRLEN] = {
		{"Amy", "Poehler"},
		{"Phyllis", "Smith"},
		{"Richard", "Kind"},
		{"Bill", "Hader"},
		{"Lewis", "Black"},
		{"Mindy", "Dias"},
		{"Kaitlyn", "Dias"},
		{"Diane", "Lane"},
		{"Kyle", "MacLachlan"},
		{"Paula", "Poundstone"},
		{"Bobby", "Moynihan"},
		{"Paula", "Pell"},
		{"Dave", "Goelz"},
		{"Frank", "Oz"},
		{"Josh", "Cooley"},
	};

    qsort(someNames, ARRLEN, sizeof(Names), compare);

    for (int i = 0; i < ARRLEN; i++)
    {
        printf("%s, %s\n", someNames[i].first, someNames[i].last);
    }

    return 0;
}

int compare(const void *p1, const void *p2)
{
    const Names *n1 = p1;
    const Names *n2 = p2;

    if (strcmp(n1->last, n2->last) == 0)
        return strcmp(n1->first, n2->first);
    else
        return strcmp(n1->last, n2->last);
}

