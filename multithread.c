//Question :- 3.	Write a multithreaded program in C that outputs prime numbers.
//This program should work as follows: The user will run the program and will enter
//a number on the command line. The program will then create a separate thread that
//outputs all the prime numbers less than or equal to the number entered by the user.

#include <stdio.h>
#include <pthread.h>


void *PrimeNum(int num1)
{
    int num2 = 0;
    int num3 = 1;
    int i;
    while (num2 < num1)
    {
        num3++;
        for (i = 2; i <= num3 - 1; i++)
        {
            if (num3 % i == 0)
                break;
        }
        if (i >= num3 - 1)
        {
            printf("%d ", num3);
            num2++;
        }
    }
    printf("\n\n");
}

int main()
{
    int num4;

    printf("\nEnter prime numbers you want to print: ");
    scanf("%d", &num4);

    if (num4 < 1)
    {
        printf("value must be greater than 1");
        return 1;
    }
    printf("\nFirst %d prime numbers are: ", num4);

    pthread_t primeThread;
    pthread_create(&primeThread, NULL, &PrimeNum, num4);
    pthread_join(primeThread, NULL);
}
