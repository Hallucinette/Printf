#include "ft_printf.h"

int main()
{
    char a = 'a';
    int b = 100;
    char *s = "hola";
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

    // printf("Nor : %x\n", b);
    // ft_printf("Nor : %x\n", b);
    // printf("R.. : %8x\n", 163);
    // ft_printf("F.. : %8x\n", 163);
    // printf("R.0 : %03X\n", 1034);
    // ft_printf("F.0 : %03X\n", 1034);

    printf("\n");
    printf("//Type s//\n");
    printf("Nor : %s\n", s);
    ft_printf("Nor : %s\n", s);
    printf("R.. : %5s\n", s);
    ft_printf("F.. : %5s\n", s);
    printf("\n//precision//\n");
    printf("%1.2s\n", s);
    ft_printf("%1.2s\n", s);
    //printf("%0-0s", s);
    //printf("%-8.5x", 34);

   

//    printf("ast|%2.2d|\n", -1);
//    printf("ast|%3.2d|\n", -1);
   printf("ast|%-5d|\n", 143);
   ft_printf("asf|%-5d|\n", 143);
   printf("ast|%-5.1d|\n", 14);
   ft_printf("asf|%-5.1d|\n", 14);
   ft_printf("asf|%2.3d|\n", -1);
  // printf("ast|%4.4d|\n", -1);
//    printf("ast|%04d|\n", 555);
//    printf("ast|%4.2d|\n", -55);
//    printf("ast|%-7.*d|\n", 5, 5);
//    printf("ast|%-7.*d|\n", 5, -5);
//    ft_printf("ast|%-*d|\n", 3, 5); 


   printf("ast|%*.*d|\n", 5, 3, 13);
    // printf("R.0 : %05s\n", s);
    // ft_printf("F.0 : %05x\n", b);





    //printf("real : %s\n", s);




    printf("-%-5.i\n", 0);
    printf("-%-5.0i\n", 0);
    printf("-%-5.0i\n", 2);
    printf("-%-5.2i\n", 0);
    //ft_printf("falso : %i\n", b);
    //ft_printf("falso : %d\n", c);
    //ft_printf("falso : %i\n", c);
    //system("leaks a.out");
    return(0);
}