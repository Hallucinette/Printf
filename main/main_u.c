#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

// INT_MAX 2147483647
// UINT_MAX 4294967295

int main()
{
	int w = 19; // Change width here !
	int p = 14; // Change precision here !
	unsigned int nb = 42;
	int ret_1 = 0;
	int ret_2 = 0;

/* SIMPLE TESTS --------------------------------- */

	printf("\n\n* SIMPLE TESTS ------------------------------------------ *\n");

	printf("\n\n* TYPE U ------------------------- *\n");

	printf("\n* BLOC 0 - Just u & flags *\n\n");

	ret_1 = printf("{%u}\n", nb);
	ret_2 = ft_printf("{%u}\n", nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0u}\n", nb);
	ret_2 = ft_printf("{%0u}\n", nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-u}\n", nb);
	ret_2 = ft_printf("{%-u}\n", nb);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n* BLOC 1 - Just width *\n\n");

	ret_1 = printf("{%*u}\n", w, nb);
	ret_2 = ft_printf("{%*u}\n", w, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*u}\n", w, nb);
	ret_2 = ft_printf("{%-*u}\n", w, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*u}\n", w, nb);
	ret_2 = ft_printf("{%0*u}\n", w, nb);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 2 - Width & Precision = 0 *\n\n");

	ret_1 = printf("{%.u}\n", nb);
	ret_2 = ft_printf("{%.u}\n", nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%*.u}\n", w, nb);
	ret_2 = ft_printf("{%*.u}\n", w, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.u}\n", w, nb);
	ret_2 = ft_printf("{%0*.u}\n", w, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.u}\n", w, nb);
	ret_2 = ft_printf("{%-*.u}\n", w, nb);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 3 - Just precision *\n\n");

	ret_1 = printf("{%.*u}\n", p, nb);
	ret_2 = ft_printf("{%.*u}\n", p, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-.*u}\n", p, nb);
	ret_2 = ft_printf("{%-.*u}\n", p, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0.*u}\n", p, nb);
	ret_2 = ft_printf("{%0.*u}\n", p, nb);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 4 - Width & Precision *\n\n");
	
	ret_1 = printf("{%*.*u}\n", w, p, nb);
	ret_2 = ft_printf("{%*.*u}\n", w, p, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.*u}\n", w, p, nb);
	ret_2 = ft_printf("{%-*.*u}\n", w, p, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.*u}\n", w, p, nb);
	ret_2 = ft_printf("{%0*.*u}\n", w, p, nb);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n😎\n");

/* OTHER TESTS --------------------------------- */

	printf("\n\n* OTHER TESTS ------------------------------------------- *\n");

	nb = 0; w = 0; p = 0;
	printf("\n🔥  TEST nb = %d | width = %d | precision = %d 🔥\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 1; w = 0; p = 0;
	printf("\n😘  TEST nb = %d | width = %d | precision = %d 😘\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 4568; w = 20; p = 9;
	printf("\n🌸  TEST nb = %d | width = %d | precision = %d 🌸\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 4568; w = -12; p = -9;
	printf("\n👀  TEST nb = %d | width = %d | precision = %d 👀\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = UINT_MAX; w = -15; p = -10;
	printf("\n🐒  TEST nb = %u | width = %d | precision = %d 🐒\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 4568; w = 15; p = -7;
	printf("\n🦁  TEST nb = %d | width = %d | precision = %d 🦁\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 0; w = 20; p = 1;
	printf("\n😉  TEST nb = %d | width = %d | precision = %d 😉\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = UINT_MAX; w = 0; p = 0;
	printf("\n🏓  TEST nb = %d | width = %d | precision = %d 🏓\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 1; w = 16; p = 5;
	printf("\n🍣  TEST nb = %d | width = %d | precision = %d 🍣\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 3694189; w = 21; p = 12;
	printf("\n🍑  TEST nb = %d | width = %d | precision = %d 🍑\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 764; w = 0; p = 8;
	printf("\n🌵  TEST nb = %d | width = %d | precision = %d 🌵\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 22; w = 0; p = 8;
	printf("\n🍌  TEST nb = %d | width = %d | precision = %d 🍌\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);

	nb = 666; w = 6; p = 6;
	printf("\n☠️  TEST nb = %d | width = %d | precision = %d ☠️\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = UINT_MAX; w = 18; p = 15;
	printf("\n🌲  TEST nb = %d | width = %d | precision = %d 🌲\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = UINT_MAX; w = 12; p = 1;
	printf("\n🤡  TEST nb = %d | width = %d | precision = %d 🤡\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = INT_MAX; w = 22; p = -15;
	printf("\n🤙  TEST nb = %d | width = %d | precision = %d 🤙\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%u}  .2 {%-u}  .3 {%0u}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*u}  .5 {%-*u}  .6 {%0*u}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.u}  8. {%*.u}  9. {%0*.u}  .10 {%-*.u}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*u}  .12 {%-.*u}  .13 {%0.*u}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);

	return 0;
}