#include <unistd.h>
#include <stdarg.h>

int reverse_number(int num)
{
	int r, sum = 0;
	while (num != 0)
	{
		r = num % 10; // get the last digit
		sum = sum * 10 + r; // add it to the reversed number
		num = num / 10; // remove the last digit
	}
//    printf("The number in reverse order is : %d\n", sum);
	return sum;
}

void print_int(int num)
{
	char minus = '-';
	if (num < 0)
	{
		write(1, &minus, 1);
		num = num * -1;
	}
	num = reverse_number(num);
	int digit;
	char nL = '\n';
	while (num != 0)
	{
		digit = (num % 10) + '0';
		write(1, &digit, 1);
		num = num / 10;
	}
	//write(1, &nL, 1);
}

void print_str(char *str)
{
	write(1, str, sizeof(str)/sizeof(char));
}

void _printf(const char * const format, ...)
{
	va_list params;
	int i = 0, num;
	char nL = '\n';
	char *str;

	va_start(params, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
		}
		else
		{
			switch(format[i+1])
			{
				case 'd':
					num = va_arg(params, int);
					print_int(num);
					break;
				case 's':
					str = va_arg(params, char*);
					print_str(str);
			}
			i += 2;
		}
	}
	write(1, &nL, 1);
	va_end(params);
}

int main()
{
	//int i = +202321;
	//print_int(i);
	int annee = 2023;
	int jour = 27;
	int mois = 3;
	char *nom = "Alfred";
	char *postnom = "Syatsukwa";
	_printf("Bonjour %s %s nous somme le %d - %d - %d", nom, postnom, jour, mois, annee);

}
