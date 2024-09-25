#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit and covert it into 'int'
    int key;
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caeser key\n");
            return 1;
        }
    }
    key = atoi(argv[1]);

    // Prompt user for plaintext
    string text = get_string("Plaintext:  ");
    printf("Ciphertext: ");

    // Encipher the plaintext

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c;
        char p;

        if (isalpha(text[i]) && isupper(text[i]))
        {
            p = text[i] - 'A';
            c = (p + key) % 26 + 'A';
        }
        else if (isalpha(text[i]) && islower(text[i]))
        {
            p = text[i] - 'a';
            c = (p + key) % 26 + 'a';
        }
        else
        {
            c = text[i];
        }
        printf("%c", c);
    }
    printf("\n");
    return 0;
}
