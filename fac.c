#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <gmp.h>

void factorize_number(const char *num_str) {
    mpz_t num;
    mpz_init_set_str(num, num_str, 10);
	gmp_printf("%Zd=", num);
    mpz_t factor;
    mpz_init(factor);

    while (mpz_cmp_ui(num, 1) > 0) {
        mpz_nextprime(factor, factor);
        if (mpz_divisible_p(num, factor)) {
            mpz_divexact(num, num, factor);
            gmp_printf("%Zd*%Zd\n", num, factor);
			break;
        }
    }
    mpz_clear(factor);
    mpz_clear(num);
}

int main(int argc, char *argv[]) {
	FILE *fil;
	size_t count;
	ssize_t line;
	char *buffer = NULL;
	int num;

	fil = fopen(argv[1], "r");
    if (argc != 2) {
        printf("Usage: ./factorize <filename>\n");
        exit(EXIT_FAILURE);
    }
	while((line = getline(&buffer, &count, fil)) != -1)
	{
		factorize_number(buffer);
	}

    return 0;
}
