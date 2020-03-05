#include "libprintf.h"

/* Fonction pour afficher l'adresse d'un pointeur = %p
*/

  void            my_put_padress(va_list *my_list)
 {
   unsigned int  adr;
   char          *base;
   char          res[9];
   int           i;
 
   adr = va_arg(*my_list, unsigned int);
   base = "0123456789abcdef";
	i = 8;
   while ((adr / 16) > 0 || i >= 8)
     {
       res[i] = base[(adr % 16)];
       adr /= 16;
       i--;
     }
   res[i] = base[(adr % 16)];
  write(1, "0x10", 4);
  while (i < 9)
     write(1, &res[i++], 1);
 } 


/* Fonction pour afficher une chaine de caractere = %s
*/

void my_printf_str(va_list *my_list)
{
	char *src;
	src = va_arg(*my_list, char *);
	write(1, src, strlen(src));
}

/* Fonction pour afficher une chaine de caractere = %c
*/

void my_printf_char(va_list *my_list)
{
	char c = va_arg(*my_list, int);

	write(1, &c, 1);
}

/* Fonction qui gere les numero = %d
*/

void my_printf_nbr(va_list *my_list)
{
	int num = va_arg(*my_list, int);

	char buffer[20];
	sprintf(buffer, "%d", num);
	write(1, buffer, strlen(buffer));
}

/* si je trouve l'element return l index sinon je return -1
*/

int findIndex(char *tab, char element)
{
	int index = 0;

	while (tab[index] != 0)
	{
		if (tab[index] == element)
			return (index);
		index++;
	}
	return (-1);
}

/* stockage des arguments et modification
**
**	je cherche dans la chaine si je trouve un %,
**	Si j'en trouve un et qu´il est different de 0
**	(dans le cas ou il se trouve au debut).
**	Dans ce cas j'utilise un tableaux d'appelle de fonction
 */

void my_printf(char *src, ...)
{
	int i;
	void (*tabFonction[4])(va_list *) = {my_put_padress, my_printf_str, my_printf_char, my_printf_nbr};

	// tableaux qui contient les pinteurs sur les fonctions;
	// je le nomme tabFonction de type void (du meme type que les fonctions que je vais appeler)
	// avec le nombre de fonction. prend en parametre un pointeur sur une va_list.
	// + liste des fonctions necessaires.

	char tabIndex[5] = {'p', 's', 'c', 'd', 0}; // [5] = 4 flags + 0 de la fin;
	i = 0;
	int tmpIndex = 0;

	va_list my_list;

	va_start(my_list, src);
	while (src[i] != 0)
	{
		if (i != 0 && src[i - 1] == '%')
		{
			tmpIndex = findIndex(tabIndex, src[i]);
			if (tmpIndex != -1)
			{
				(*tabFonction[tmpIndex])(&my_list);
			}
			// si different de -1.
			// j'appelle mon tableau et l'index + la list de parametre.
			// redirige vers la bonne fonction.
		}
		else if (src[i] != '%')
			write(1, &src[i], 1);

		i++;
	}
}

/*	Detecte le type de pourcentage (dans le main) apres le % et le 
**	renvoie a la fonction qui correspond.
**	Cette fonction renvoi la liste de tous les argumetns et parametre.
**	Si j ai deux parametres Va_arg va repasser une deuxieme fois et
**	ainsi de suite en lisant les parametres d'apres.
**
**	On redirige grace aux pointeurs sur fonction :
**	Cela sert a savoir a quel fonction va servire On va parcourir jusqu'a ce que l'index
**	corresponde a la lettre dans le tableau de fonction.  Du  coup l'index va changer
**	ex : i = s / i =0; i = c / i = 1
**	On va pouvoir renvoyer a la fonction que l on veux grace a la fonction findIndex.
**	
*/