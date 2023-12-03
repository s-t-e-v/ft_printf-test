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

static void    test_assert(int condition, t_test_data test)
{
    nb_test++;
    if (!condition)
    {
        printf("\nFail test #%d\n", test.id);
        printf("   Expected: %s\n", test.expected);
        printf("   Actual: %s\n", test.actual);
    }
    else
        test_passed++;
}

// Those tests requires to remove flags -Wall -Werror -Wextra
static void    weird_tests()
{
    t_test_data test;
    int res;
    int res_og;
    char    *null_ptr = NULL;
    int *n_ptr;


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
    // test 21
    test.id = 21;
    res = ft_printf("==%%%"); // Use the function
    res_og = printf("==%%%"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 22
    test.id = 22;
    res = ft_printf("===%=%%"); // Use the function
    res_og = printf("===%=%%"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 26 [Valgrind error uninitialized variable]
    test.id = 26;
    res = ft_printf("%s"); // Use the function
    res_og = printf("%s"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 27 [Valgrind error uninitialized variable]
    test.id = 27;
    res = ft_printf("%s%"); // Use the function
    res_og = printf("%s%"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n"); 
    // test 32
    test.id = 32;
    n_ptr = 1;
    res = ft_printf("%p\n", n_ptr); // Use the function
    res_og = printf("%p\n", n_ptr); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 33
    test.id = 33;
    n_ptr = 11;
    res = ft_printf("%p\n", n_ptr); // Use the function
    res_og = printf("%p\n", n_ptr); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 34
    test.id = 34;
    n_ptr = 243;
    res = ft_printf("%p\n", n_ptr); // Use the function
    res_og = printf("%p\n", n_ptr); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 46
    test.id = 46;
    n_ptr = (size_t)-1;
    res = ft_printf("%p\n", n_ptr); // Use the function
    res_og = printf("%p\n", n_ptr); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
     // // test 39
    // test.id = 39;
    // res = ft_printf("%i"); // Use the function
    // res_og = printf("%i"); // Use the function
    // sprintf(test.expected, "retvalue: %d", res_og);
    // sprintf(test.actual, "retvalue: %d", res);
    // test_assert(res == res_og, test);
    // printf("\n");
    // // test 40
    // test.id = 40;
    // res = ft_printf("%i\n"); // Use the function
    // res_og = printf("%i\n"); // Use the function
    // sprintf(test.expected, "retvalue: %d", res_og);
    // sprintf(test.actual, "retvalue: %d", res);
    // test_assert(res == res_og, test);
    // printf("\n");
}

static void    normal_tests()
{
    t_test_data test;
    int res;
    int res_og;

    int n = 50;
    int *n_ptr = &n;
    int *n_null = NULL;
    char    *null_ptr = NULL;


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
    // test 23
    test.id = 23;
    res = ft_printf("%%"); // Use the function
    res_og = printf("%%"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 24
    test.id = 24;
    res = ft_printf("%%%%"); // Use the function
    res_og = printf("%%%%"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 25
    test.id = 25;
    res = ft_printf("%s", "Bonjour"); // Use the function
    res_og = printf("%s", "Bonjour"); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
  
    // test 28
    test.id = 28;
    res = ft_printf("%s%c", "Oui: ",  'O'); // Use the function
    res_og = printf("%s%c", "Oui: ",  'O'); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 29
    test.id = 29;
    null_ptr = NULL;
    res = ft_printf("%s", null_ptr); // Use the function
    res_og = printf("%s", null_ptr); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 30
    test.id = 30;
    res = ft_printf("%p", n_null); // Use the function
    res_og = printf("%p", n_null); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 31
    test.id = 31;
    res = ft_printf("%p\n", n_ptr); // Use the function
    res_og = printf("%p\n", n_ptr); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
     // test 35
    test.id = 35;
    int n_int = -2147483648;
    res = ft_printf("%d\n", n_int); // Use the function
    res_og = printf("%d\n", n_int); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 36
    test.id = 36;
    n_int = -5200;
    res = ft_printf("%d\n", n_int); // Use the function
    res_og = printf("%d\n", n_int); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 37
    test.id = 37;
    n_int = 2147483647;
    res = ft_printf("%d\n", n_int); // Use the function
    res_og = printf("%d\n", n_int); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 38
    test.id = 38;
    n_int = 1;
    res = ft_printf("%i\n", n_int); // Use the function
    res_og = printf("%i\n", n_int); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
  
    // test 41
    test.id = 41;
    unsigned int n_uint = 0;
    res = ft_printf("%u\n", n_uint); // Use the function
    res_og = printf("%u\n", n_uint); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 42
    test.id = 42;
    n_uint = 120;
    res = ft_printf("%u\n", n_uint); // Use the function
    res_og = printf("%u\n", n_uint); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 43
    test.id = 43;
    n_uint = (unsigned int)-1;
    res = ft_printf("%u\n", n_uint); // Use the function
    res_og = printf("%u\n", n_uint); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 44
    test.id = 44;
    n_uint = (unsigned int)-1;
    res = ft_printf("%x\n", n_uint); // Use the function
    res_og = printf("%x\n", n_uint); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 45
    test.id = 45;
    n_uint = (unsigned int)-1;
    res = ft_printf("%X\n", n_uint); // Use the function
    res_og = printf("%X\n", n_uint); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 46
    test.id = 46;
    n_uint = 0;
    res = ft_printf("%X\n", n_uint); // Use the function
    res_og = printf("%X\n", n_uint); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 47
    test.id = 47;
    n_uint = 243;
    res = ft_printf("%x\n", n_uint); // Use the function
    res_og = printf("%x\n", n_uint); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");
    // test 48
    test.id = 48;
    n_uint = 243;
    res = ft_printf("%X\n", n_uint); // Use the function
    res_og = printf("%X\n", n_uint); // Use the function
    sprintf(test.expected, "retvalue: %d", res_og);
    sprintf(test.actual, "retvalue: %d", res);
    test_assert(res == res_og, test);
    printf("\n");

}

int main(void) {

    // weird_tests();
    normal_tests();

    if (test_passed == nb_test)
        printf("\nAll tests passed (%d/%d)\n", test_passed, nb_test);
    else
        printf("\nSome tests failed (%d/%d)\n", test_passed, nb_test);
    return 0;
}
