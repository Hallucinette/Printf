#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int ret_1 = 0;
	int ret_2 = 0;

	int w = 18; // Change width here !
	int p = 12; // Change precision here !
	char *str = "bonjour yohann";

	// str = NULL;

/* SIMPLE TESTS --------------------------------- */

	printf("\n\n* TYPE S ------------------------- *\n");


	printf("\n* BLOC 0 - Just s & flags *\n\n");

	ret_1 = printf("{%s}\n", str);
	ret_2 = ft_printf("{%s}\n", str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0s}\n", str);
	ret_2 = ft_printf("{%0s}\n", str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-s}\n", str);
	ret_2 = ft_printf("{%-s}\n", str);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n* BLOC 1 - Just width *\n");

	ret_1 = printf("{%*s}\n", w, str);
	ret_2 = ft_printf("{%*s}\n", w, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*s}\n", w, str);
	ret_2 = ft_printf("{%-*s}\n", w, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*s}\n", w, str);
	ret_2 = ft_printf("{%0*s}\n", w, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 2 - Width & Precision = 0 *\n");

	ret_1 = printf("{%.s}\n", str);
	ret_2 = ft_printf("{%.s}\n", str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%*.s}\n", w, str);
	ret_2 = ft_printf("{%*.s}\n", w, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.s}\n", w, str);
	ret_2 = ft_printf("{%0*.s}\n", w, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.s}\n", w, str);
	ret_2 = ft_printf("{%-*.s}\n", w, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 3 - Just precision *\n");

	ret_1 = printf("{%.*s}\n", p, str);
	ret_2 = ft_printf("{%.*s}\n", p, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-.*s}\n", p, str);
	ret_2 = ft_printf("{%-.*s}\n", p, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0.*s}\n", p, str);
	ret_2 = ft_printf("{%0.*s}\n", p, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 4 - Width & Precision *\n");

	ret_1 = printf("{%*.*s}\n", w, p, str);
	ret_2 = ft_printf("{%*.*s}\n", w, p, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.*s}\n", w, p, str);
	ret_2 = ft_printf("{%-*.*s}\n", w, p, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.*s}\n", w, p, str);			// error  %018.12s
	ret_2 = ft_printf("{%0*.*s}\n", w, p, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);

	printf("\n😎\n");

/* OTHER TESTS --------------------------------- */

	printf("\n\n* OTHER TESTS ------------------------------------------- *\n");

	str = NULL; w = 0; p = 0;
	printf("\n🔥  TEST str = %s | width = %d | precision = %d 🔥\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	str = ""; w = 0; p = 0;
	printf("\n😘  TEST str = %s | width = %d | precision = %d 😘\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)			// error n'15 == %018.12s
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	str = "4568"; w = 20; p = 9;
	printf("\n🌸  TEST str = %s | width = %d | precision = %d 🌸\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	str = "Wesh alors !"; w = -12; p = -9;
	printf("\n👀  TEST str = %s | width = %d | precision = %d 👀\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	str = "Hola"; w = -15; p = -10;
	printf("\n🐒  TEST str = %s | width = %d | precision = %d 🐒\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	str = "INT_MAX"; w = 15; p = -7;
	printf("\n🦁  TEST str = %s | width = %d | precision = %d 🦁\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	str = "Ta maman en stringue"; w = 22; p = 18;
	printf("\n😉  TEST str = %s | width = %d | precision = %d 😉\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)  //error n'15
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);

/*
	str = -42; w = 0; p = 0;  //segfault
	printf("\n🏓  TEST str = %s | width = %d | precision = %d 🏓\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
*/

	str = "Ta maman en string"; w = 16; p = 8;
	printf("\n🍣  TEST str = %s | width = %d | precision = %d 🍣\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	str = "Quand est-ce qu'on mange ?"; w = 8; p = 1;
	printf("\n🍑  TEST str = %s | width = %d | precision = %d 🍑\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	str = "Ta maman en string"; w = 0; p = 110;
	printf("\n🌵  TEST str = %s | width = %d | precision = %d 🌵\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	str = "Ta maman en string"; w = 25; p = 0;
	printf("\n🍌  TEST str = %s | width = %d | precision = %d 🍌\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);

	str = "666"; w = 6; p = 6;
	printf("\n☠️  TEST str = %s | width = %d | precision = %d ☠️\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	str = "Tarpin bien"; w = 11; p = 6;
	printf("\n🌲  TEST str = %s | width = %d | precision = %d 🌲\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	str = "Grosse Salope"; w = 22; p = 9;
	printf("\n🤡  TEST str = %s | width = %d | precision = %d 🤡\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	str = "donc, tu disais ?"; w = 22; p = -15;
	printf("\n🤙  TEST str = %s | width = %d | precision = %d 🤙\n", str, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	ret_2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}\n", str, str, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	ret_2 = ft_printf(".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	ret_2 = ft_printf(".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n", str, w, str, w, str, w, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	ret_2 = ft_printf(".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n", p, str, p, str, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	ret_2 = ft_printf(".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}  .17 {%-0*.*s}\n", w, p, str, w, p, str, w, p, str, w, p, str);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);

	return 0;
}
