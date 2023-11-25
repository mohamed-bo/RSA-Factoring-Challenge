#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void factorize_number(long long int num) {
    if (num % 2 == 0) {
		printf("%lld=%lld*%d\n",num,num/2,2);
		return;
    }

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            printf("%lld=%lld*%d\n",num,num/i,i);
            return;
        }
    }
    printf("%lld=%lld*%d\n",num,num,1);
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
		factorize_number(atoll(buffer));
	}

    return 0;
}
