#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

/*
** Flag ZERO and precision -> Undifined behaviour
*/

int main()
{
	int w = 12; // Change width here !
	int p = 10; // Change precision here !
	int c = 0;

	int ret_1 = 0;
	int ret_2 = 0;

/* SIMPLE TESTS --------------------------------- */

	printf("\n\n* TYPE C ------------------------- *\n");

	printf("\n* BLOC 1 - Just width *\n\n");

	ret_1 = printf("{%c}\n", c);
	ret_2 = ft_printf("{%c}\n", c);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%*c}\n", w, c);
	ret_2 = ft_printf("{%*c}\n", w, c);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*c}\n", w, c);
	ret_2 = ft_printf("{%-*c}\n", w, c);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*c}\n", w, c);
	ret_2 = ft_printf("{%0*c}\n", w, c);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n* BLOC 2 - Width & Precision = 0 *\n\n");

	ret_1 = printf("{%.c}\n", c);
	ret_2 = ft_printf("{%.c}\n", c);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%*.c}\n", w, c);
	ret_2 = ft_printf("{%*.c}\n", w, c);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.c}\n", w, c);			//probleme  %012.c
	ret_2 = ft_printf("{%0*.c}\n", w, c);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.c}\n", w, c);
	ret_2 = ft_printf("{%-*.c}\n", w, c);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n* BLOC 3 - Just precision *\n\n");

	ret_1 = printf("{%.*c}\n", p, c);
	ret_2 = ft_printf("{%.*c}\n", p, c);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-.*c}\n", p, c);
	ret_2 = ft_printf("{%-.*c}\n", p, c);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0.*c}\n", p, c);
	ret_2 = ft_printf("{%0.*c}\n", p, c);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n* BLOC 4 - Width & Precision *\n\n");

	ret_1 = printf("{%*.*c}\n", w, p, c);
	ret_2 = ft_printf("{%*.*c}\n", w, p, c);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.*c}\n", w, p, c);
	ret_2 = ft_printf("{%-*.*c}\n", w, p, c);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.*c}\n", w, p, c);   //probleme  %012.10c
	ret_2 = ft_printf("{%0*.*c}\n", w, p, c);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n* BLOC 5 - Zero only and minus only *\n\n");

	ret_1 = printf("{%0c}\n", c);
	ret_2 = ft_printf("{%0c}\n", c);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-c}\n", c);
	ret_2 = ft_printf("{%-c}\n", c);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-0c}\n", c);
	ret_2 = ft_printf("{%-0c}\n", c);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n😎\n");

// INT_MAX = 2147483647;
// UINT_MAX = 4294967295;

/* OTHER TESTS --------------------------------- */

	ret_1 = printf("|hello ca%----4c %1c%10c%-c ??|\n", '\0', '\n', (char)56, 0);
	ret_2 = ft_printf("|hello ca%----4c %1c%10c%-c ??|\n", '\0', '\n', (char)56, 0);
	printf("%d | %d\n\n", ret_1, ret_2);

	ret_1 = printf("|%----4c|\n", '\0');
	ret_2 = ft_printf("|%----4c|\n", '\0');
	printf("%d | %d\n\n", ret_1, ret_2);

	ret_1 = printf("|%1c|\n", '\n');
	ret_2 = ft_printf("|%1c|\n", '\n');
	printf("%d | %d\n\n", ret_1, ret_2);

	ret_1 = printf("|%10c|\n", (char)56);
	ret_2 = ft_printf("|%10c|\n", (char)56);
	printf("%d | %d\n\n", ret_1, ret_2);

	ret_1 = printf("|%-c|\n", 0);
	ret_2 = ft_printf("|%-c|\n", 0);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n🐒\n");
	return 0;
}
