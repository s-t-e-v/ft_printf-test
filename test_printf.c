#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int		n;
	char	*str;

	str = NULL;
	// NULL str test
	n = printf(str); // -1
	printf("\n(null):%d\n", n); // nothing happen
	// unique %
	n = printf("%"); // -1
	printf("\n%%:%d\n", n); // nothing happen
	// unique % with char(s) before
	n = printf("f%"); // -1
	printf("\nf%%:%d\n", n); // f
	// unique % with char(s) before
	n = printf("====%=%"); // 7
	printf("\n====%%=%%:%d\n", n); // ====%=% (as it is)
	
    n = printf("%s"); // Use the function
	printf("\n%%s:%d\n", n); // (null):-1
    n = printf("%s"); // Use the function
	printf("\n%%s:%d\n", n); // (null):-1
    n = printf("%s"); // Use the function
	printf("\n%%s:%d\n", n); // (null):-1
	return (0);
}