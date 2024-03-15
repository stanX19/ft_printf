extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 29

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: u" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %u ", 0));
	TEST(2, print(" %u ", -1));
	TEST(3, print(" %u ", 1));
	TEST(4, print(" %u ", 9));
	TEST(5, print(" %u ", 10));
	TEST(6, print(" %u ", 11));
	TEST(7, print(" %u ", 15));
	TEST(8, print(" %u ", 16));
	TEST(9, print(" %u ", 17));
	TEST(10, print(" %u ", 99));
	TEST(11, print(" %u ", 100));
	TEST(12, print(" %u ", 101));
	TEST(13, print(" %u ", -9));
	TEST(14, print(" %u ", -10));
	TEST(15, print(" %u ", -11));
	TEST(16, print(" %u ", -14));
	TEST(17, print(" %u ", -15));
	TEST(18, print(" %u ", -16));
	TEST(19, print(" %u ", -99));
	TEST(20, print(" %u ", -100));
	TEST(21, print(" %u ", -101));
	TEST(22, print(" %u ", INT_MAX));
	TEST(23, print(" %u ", INT_MIN));
	TEST(24, print(" %u ", LONG_MAX));
	TEST(25, print(" %u ", LONG_MIN));
	TEST(26, print(" %u ", UINT_MAX));
	TEST(27, print(" %u ", ULONG_MAX));
	TEST(28, print(" %u ", 9223372036854775807LL));
	TEST(29, print(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(30, print("%05u\n", 2));
	TEST(31, print("%05.u\n", 2));
	TEST(32, print("%5u\n", 20));
	TEST(33, print("%.12u\n", -3));
	TEST(34, print("%10.5u\n", 211110));
	TEST(35, print("%.5u\n", 20));
	TEST(36, print("%-5u\n", 20));
	TEST(37, print("%010.5u\n", 20));
	TEST(38, print("%03.0u\n", 0));
	TEST(39, print("[%.u]\n", 0));
	TEST(40, print("[%.u]\n", 0));
	TEST(41, print("[%10.u]\n", 0));
	TEST(42, print("[%10.u]\n", 0));
	TEST(43, print("[%-10.u]\n", 0));
	TEST(44, print("[%-10.u]\n", 0));
	TEST(45, print("[%10.5u]\n", 0));
	TEST(46, print("[%10.5u]\n", 0));
	TEST(47, print("[%.u]\n", 0));
	TEST(48, print("[%.u]\n", 0));
	TEST(49, print("[%10.u]\n", 0));
	TEST(50, print("[%10.u]\n", 0));
	TEST(51, print("[%-10.u]\n", 0));
	TEST(52, print("[%-10.u]\n", 0));
	TEST(53, print("[%10.5u]\n", 0));
	TEST(54, print("[%10.5u]\n", 0));
	cout << ENDL;
	return (0);
}
