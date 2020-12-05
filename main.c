#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
  int ret_1 = 0;
	int ret_2 = 0;
    char a = 'a';
    int b = 100;
    int c = 7;
    char *s = "hola";

    // ft_printf("F.. : %108548603685085d\n", b);
   // double c = 333.33;


    // printf("//// NORMAL ////");
    // printf("\n");
    // printf("R. : %c\n", a);
    // ft_printf("F. : %c\n", a);

    //printf("//// WITH ////");
    // printf("\n");
    // printf("//Type C//\n");

    // printf("R.. : %4c\n", a);
    // ft_printf("F.. : %4c\n", a);
    // printf("R.0 : %4c\n", a);
    // ft_printf("F.0 : %4c\n", a);

    // printf("\n");
    // printf("//Type D//\n");

    // printf("R.. : %5d\n", b);
    // ft_printf("F.. : %5d\n", b);
    // printf("R.0 : %010d\n", b);
    // ft_printf("F.0 : %010d\n", b);
    // printf("%07d\n", -54);
    // ft_printf("%07d\n", -54);


    // printf("\n");
    // printf("//Type Xx//\n");
    // ret_1 = printf("R  : |%x|\n", 255);
    // printf("Ret  : %d\n", ret_1);

    // ret_2 = ft_printf("f  : |%x|\n", 255);
    // printf("Ret  : %d\n", ret_2);
    // printf("\n//Width//\n");

    // printf("\n");
    // printf("R.3  : |%3x|\n", 123456789);
    // ft_printf("F.3  : |%3X|\n", 123456789);
    // printf("R.7  : |%-7x|\n", 123456789);
    // ft_printf("F.7  : |%-7x|\n", 123456789);
    // printf("R.9  : |%-9x|\n", 123456789);
    // ft_printf("F.9  : |%-9x|\n", 123456789);
    // printf("R.11 : |%11x|\n", 123456789);
    // ft_printf("F.11 : |%11x|\n", 123456789);

    // printf("\n//precision//\n");

    // printf("R.0  : |%.0x|\n", 123456789);
    // ft_printf("F.0  : |%.0x|\n", 123456789);
    // printf("R.1  : |%.1x|\n", 123456789);
    // ft_printf("F.1  : |%.1x|\n", 123456789);
    // printf("R.7  : |%.7x|\n", 123456789);
    // ft_printf("F.7  : |%.9x|\n", 123456789);
    // printf("R.9  : |%.10x|\n", 123456789);
    // ft_printf("F.9  : |%.15x|\n", 123456789);
/*

*/

   /* printf("\n");
    printf("//Type s//\n");
    printf("Nor : |%s|\n", s);
    ft_printf("Nor : |%s|\n", s);

    printf("//Width//\n");
    printf("R.. : |%4s|\n", s);
    ft_printf("F.. : |%4s|\n", s);
    printf("R.. : |%9s|\n", s);
    ft_printf("F.. : |%9s|\n", s);
    printf("R.. : |%-9s|\n", s);
    ft_printf("F.. : |%-9s|\n", s);

    printf("\n//precision//\n");
    printf("R.. : |%6s|\n", NULL);
    ft_printf("F.. : |%4.4s|\n", NULL);
    printf("R.. : |%9.2s|\n", s);
    ft_printf("F.. : |%9.2s|\n", s);
    printf("R.. : |%-9.2s|\n", s);
    ft_printf("F.. : |%-9.2s|\n", s);
    printf("R.. : |%3.5s|\n", s);
    ft_printf("F.. : |%3.5s|\n", s);
   */

//    printf("ast|%2.2d|\n", -1);
//    printf("ast|%3.2d|\n", -1);
//    printf("ast|%-5d|\n", 143);
//    ft_printf("asf|%-5d|\n", 143);
//    printf("ast|%-5.1d|\n", 14);
//    ft_printf("asf|%-5.1d|\n", 14);
//    ft_printf("asf|%2.3d|\n", -1);
  // printf("ast|%4.4d|\n", -1);
//    printf("ast|%04d|\n", 555);
//    printf("ast|%4.2d|\n", -55);
//    printf("ast|%-7.*d|\n", 5, 5);
//    printf("ast|%-7.*d|\n", 5, -5);
//    ft_printf("ast|%-*d|\n", 3, 5); 


  // printf("ast|%*.*d|\n", 5, 3, 13);
  // printf("R.0 : %05s\n", s);
  // ft_printf("F.0 : %05x\n", b);

  // printf("//// NORMAL ////");
  // printf("\n");
  // printf("R. : %6p\n", &a);
  // printf("R. : %20p\n", &a);
  // printf("R. : %p\n", &s);
  // ft_printf("F. : %p\n", &s);

//   ret_1 = printf("R |%9.2p/\n/", 1234);
//   ret_2 = ft_printf("F |%9.2p
// ", 1234);

  // ret_1 = printf("%%d 0000042 == |%d|", 0000011);
  //  	printf("\n");
  // ret_2 = ft_printf("%%d 0000042 == |%d|", 0000011);
  //    	printf("\n");
 	// printf("%d | %d\n\n", ret_1, ret_2);
  // ft_printf("F |%05p|\n", 0);
  // printf("R |%5p|\n", 0);
  // ft_printf("F |%5p|\n", 0);
  // // printf("%.3p\n", 1);
  // // ft_printf("%.3p\n", 1);
  // printf("R |%-5p|\n", 0);
  // ft_printf("F |%-5p|\n", 0);
  //ft_printf("|%-3p|\n", 0);

    //printf("//// WITH ////");
    // printf("\n");
    // printf("//Type C//\n");

    // printf("R.. : %4c\n", a);
    // ft_printf("F.. : %4c\n", a);
    // printf("R.0 : %4c\n", a);
    // ft_printf("F.0 : %4c\n", a);





    //printf("real : %s\n", s);




    // printf("-%-5.i\n", 0);
    // printf("-%-5.0i\n", 0);
    // printf("-%-5.0i\n", 2);
    // printf("-%-5.2i\n", 0);
    //ft_printf("falso : %i\n", b);
    //ft_printf("falso : %d\n", c);
    //ft_printf("falso : %i\n", c);
    //system("leaks a.out");



//int w = 15, p = -7, nb = 4568;
  //   ret_1 = printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	// ret_2 = ft_printf(".14 {%*.*u}  .15 {%0*.*u}  .16 {%-*.*u}  .17 {%-0*.*u}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	// if (ret_1 == ret_2)
	// 	printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	// else
	// 	printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);

printf("Il fait au moins %u", -3);
printf("\n");
ft_printf("Il fait au moins %u", -3);
printf("\n");
printf("%u", -4);
printf("\n");
ft_printf("%u", -4);
printf("\n");

printf("%u", INT_MIN);
printf("\n");
ft_printf("%u", INT_MIN);
printf("\n");

printf("%u", INT_MAX + 1);
printf("\n");
ft_printf("%u", INT_MAX + 1);
//\n
    return(0);
}