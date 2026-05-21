#include <stdio.h>
#include <string.h>

int
main_memory ()
{
    int myInt;
    float myFloat;
    double myDouble;
    char myChar;
    char word5Letter[] = "123456789🏴󠁧󠁢󠁷󠁬󠁳󠁿";

    unsigned long longInt = 123;
    long ulongInt = 18446744073709551615U;
    short ushortInt = 11;

    unsigned short negativeInt = ushortInt + 100;
    short shortInt = ushortInt + 100;

    // printf("unsigned short int Value: %hu\n", negativeInt);
    printf ("unsigned long %lu\n", ulongInt);
    printf ("size signed short int %zu\n", sizeof (shortInt));
    printf ("size unsigned long big %zu\n", sizeof (longInt));
    printf ("size unsigned long small %zu\n", sizeof (ulongInt));
    printf ("size unsigned short small %zu\n", sizeof (ushortInt));

    // printf("%zu\n", sizeof(myInt));
    // printf("%zu\n", sizeof(myFloat));
    // printf("%zu\n", sizeof(myDouble));
    // printf("%zu\n", sizeof(myChar));

    // printf("Size %zu\n", sizeof(word5Letter));
    // printf("Len %zu\n", strlen(word5Letter));

    char strCopy[38];
    strcpy (strCopy, word5Letter);

    word5Letter[9] = 'x';

    printf ("Value %s\n", word5Letter);
    printf ("Size %zu\n", sizeof (word5Letter));

    printf ("Copy Value %s\n", strCopy);
    printf ("Copy Size %zu\n", sizeof (strCopy));

    int floatSize = sizeof (myFloat);
    int doubleSize = sizeof (myDouble);
    int word5LettersSize = sizeof (word5LettersSize);

    printf ("END OF main_memory\n\n");

    return 0;
}
