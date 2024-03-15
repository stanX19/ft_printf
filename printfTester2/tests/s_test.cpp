extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"

# define TEST_LIMIT 10

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: s" << RESET_ALL;

	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print("%s", ""));
	TEST(2, print(" %s", ""));
	TEST(3, print("%s ", ""));
	TEST(4, print(" %s ", ""));
	TEST(5, print(" %s ", "-"));
	TEST(6, print(" %s %s ", "", "-"));
	TEST(7, print(" %s %s ", " - ", ""));
	TEST(8, print(" %s %s %s %s %s", " - ", "", "4", "", s2));
	TEST(9, print(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
	TEST(10, print(" NULL %s NULL ", NULL));
	TEST(11, print("%s\n", "Hello"));
	TEST(12, print("%7s\n", "Hello"));
	TEST(13, print("%5.3s\n", "Hello"));
	TEST(14, print("%-5.3s\n", "Hello"));
	TEST(15, print("%5.7s\n", "Hello"));
	TEST(16, print("%7.7s\n", "Hello"));
	TEST(17, print("%-5s\n", "Hello"));
	TEST(18, print("%7.100s", "Hello"));
	TEST(19, print("%10.7s\n", "Hello"));
	TEST(20, print(" NULL %s NULL \n", NULL));

	char	*null_str = 0;
	TEST(21, print("%7s\n", null_str));
	cout << ENDL;
	return (0);
}
