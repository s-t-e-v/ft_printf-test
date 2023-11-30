#include "../ft_printf.h"
#include <stdio.h>
#define FT "ft_printf"

static int  nb_test = 0;
static int  test_passed = 0;

typedef struct s_test_data {
	char expected[1000];
	char actual[1000];
    int     id;
} t_test_data;

void    test_assert(int condition, t_test_data test)
{
    nb_test++;
    if (!condition)
    {
        printf("\nFail test #%d\n", test.id);
        printf("   Expected: %s\n", test.expected);
        printf("   Actual: %s\n", test.actual);
    }
    test_passed++;
}

int main(void) {

    t_test_data test;
    int res;
    int res_og;

    // test 1
    test.id = 1;
    res = ft_printf("Hello World!\n"); // Use the function
    res_og = printf("Hello World!\n"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    // test 2
    test.id = 2;
    res = ft_printf("Steven starts with %c!\n", 'S'); // Use the function
    res_og = printf("Steven starts with %c!\n", 'S'); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 3
    test.id = 3;
    res = ft_printf("%c", 'u'); // Use the function
    res_og = printf("%c", 'u'); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 4
    test.id = 4;
    res = ft_printf("A%c", 'u'); // Use the function
    res_og = printf("A%c", 'u'); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 5
    test.id = 5;
    res = ft_printf("%co", 'u'); // Use the function
    res_og = printf("%co", 'u'); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 5
    test.id = 5;
    res = ft_printf("Le R%cR A est ok.", 'E'); // Use the function
    res_og = printf("Le R%cR A est ok.", 'E'); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 6
    test.id = 6;
    res = ft_printf("Le R%cR %c est ok.", 'E', 'C'); // Use the function
    res_og = printf("Le R%cR %c est ok.", 'E', 'C'); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 7
    test.id = 7;
    res = ft_printf("Le R%cR %; est ok.", 'E', 'C'); // Use the function
    res_og = printf("Le R%cR %; est ok.", 'E', 'C'); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 8
    test.id = 8;
    res = ft_printf("Probleme a la fin %"); // Use the function
    res_og = printf("Probleme a la fin %"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 9
    test.id = 9;
    res = ft_printf("%=ldd"); // Use the function
    res_og = printf("%=ldd"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 10
    test.id = 10;
    res = ft_printf("%"); // Use the function
    res_og = printf("%"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 11
    test.id = 11;
    res = ft_printf("ab%cdef%", 'c'); // Use the function
    res_og = printf("ab%cdef%", 'c'); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 12
    test.id = 12;
    char    *null_ptr = NULL;
    res = ft_printf(null_ptr); // Use the function
    res_og = printf(null_ptr); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 13
    test.id = 13;
    res = ft_printf("abc%=%"); // Use the function
    res_og = printf("abc%=%"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // // test 14
    // test.id = 14;
    // res = ft_printf("abc%d%"); // Use the function
    // res_og = printf("abc%d%"); // Use the function
    // sprintf(test.expected, "retvalue: %d", res_og);
    // sprintf(test.actual, "retvalue: %d", res);
    // test_assert(res == res_og, test);
    // printf("\n");
    // test 15
    test.id = 15;
    res = ft_printf("abc%=%="); // Use the function
    res_og = printf("abc%=%="); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // // test 16
    // test.id = 16;
    // res = ft_printf("abc%=%d"); // Use the function
    // res_og = printf("abc%=%d"); // Use the function
    // sprintf(test.expected, "retvalue: %d", res_og);
    // sprintf(test.actual, "retvalue: %d", res);
    // test_assert(res == res_og, test);
    // printf("\n");
    // test 17
    test.id = 17;
    res = ft_printf("abc%=%\n"); // Use the function
    res_og = printf("abc%=%\n"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 18
    test.id = 18;
    res = ft_printf("abc%=%c"); // Use the function
    res_og = printf("abc%=%c"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 19
    test.id = 19;
    res = ft_printf("abc%c=%"); // Use the function
    res_og = printf("abc%c=%"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 20
    test.id = 20;
    res = ft_printf("abc%==%"); // Use the function
    res_og = printf("abc%==%"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");

    if (test_passed == nb_test)
        printf("\nAll tests passed (%d/%d)\n", test_passed, nb_test);
    else
        printf("\nSome tests failed (%d/%d)\n", test_passed, nb_test);
    return 0;
}
