/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <amepocch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:19 by vserra            #+#    #+#             */
/*   Updated: 2020/12/06 22:38:03 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int ret_1 = 0;
	int ret_2 = 0;

	int w = 18; // Change width here !
	int p = 12; // Change precision here !
	char *str = "Hola que tal";

	//str = NULL;
	// INT_MAX 2147483647
	// UINT_MAX 4294967295


 /* SIMPLE TESTS --------------------------------- */

 	printf("\n\n* TYPE P ------------------------- *\n");

	printf("\n* BLOC 0 - Just p & flags *\n\n");

	ret_1 = printf("{%p}\n", str);
	ret_2 = ft_printf("{%p}\n", str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0p}\n", str);
	ret_2 = ft_printf("{%0p}\n", str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-p}\n", str);
	ret_2 = ft_printf("{%-p}\n", str);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n* BLOC 1 - Just width *\n\n");

	ret_1 = printf("{%*p}\n", w, str);
	ret_2 = ft_printf("{%*p}\n", w, str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*p}\n", w, str);
	ret_2 = ft_printf("{%-*p}\n", w, str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*p}\n", w, str);
	ret_2 = ft_printf("{%0*p}\n", w, str);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 2 - Width & Precision = 0 *\n\n");

	ret_1 = printf("{%.p}\n", str);
	ret_2 = ft_printf("{%.p}\n", str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%*.p}\n", w, str);
	ret_2 = ft_printf("{%*.p}\n", w, str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.p}\n", w, str);
	ret_2 = ft_printf("{%0*.p}\n", w, str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.p}\n", w, str);
	ret_2 = ft_printf("{%-*.p}\n", w, str);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 3 - Just precision *\n\n");

	ret_1 = printf("{%.*p}\n", p, str);
	ret_2 = ft_printf("{%.*p}\n", p, str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-.*p}\n", p, str);
	ret_2 = ft_printf("{%-.*p}\n", p, str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0.*p}\n", p, str);
	ret_2 = ft_printf("{%0.*p}\n", p, str);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 4 - Width & Precision *\n\n");

	ret_1 = printf("{%*.*p}\n", w, p, str);
	ret_2 = ft_printf("{%*.*p}\n", w, p, str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.*p}\n", w, p, str);
	ret_2 = ft_printf("{%-*.*p}\n", w, p, str);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.*p}\n", w, p, str);
	ret_2 = ft_printf("{%0*.*p}\n", w, p, str);
	printf("%d | %d\n\n", ret_1, ret_2);




	ret_1 = printf("%9.1p\n", 1234);
	ret_2 = ft_printf("%9.1p\n", 1234);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("%9.2p\n", 1234);
	ret_2 = ft_printf("%9.2p\n", 1234);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("%9.3p\n", 1234);
	ret_2 = ft_printf("%9.3p\n", 1234);
	printf("%d | %d\n\n", ret_1, ret_2);


	printf("\n😎\n");
	return 0;
}
