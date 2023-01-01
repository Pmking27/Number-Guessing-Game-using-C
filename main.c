#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LEN 128

void print_image(FILE *fptr);

int main(void)
{
    char *filename = "art/logo.txt";
    FILE *fptr = NULL;
    int number, guess, nguesses = 1;
    srand(time(0));
    number = rand() % 100 + 1;

    if ((fptr = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "error opening %s\n", filename);
        return 1;
    }

    print_image(fptr);

    fclose(fptr);

    do
    {
        printf("\nGuess the number between 1 to 100\n");
        scanf("%d", &guess);
        if (guess > number)
        {
            printf("Lower number please!\n");
        }
        else if (guess < number)
        {
            printf("Higher number please!\n");
        }
        else
        {
            printf("You guessed it in %d attempts\n", nguesses);
        }
        nguesses++;
    } while (guess != number);

    return 0;
}

void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];

    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s", read_string);
}