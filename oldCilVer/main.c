#include <stdio.h>
#include <string.h>

void logo()
{
    printf("\x1b[34m   ____ _       _               \n");
    printf("  / ___(_)_ __ | |__   ___ _ __ \n");
    printf(" | |   | | '_ \\| '_ \\ / _ \\ '__|\n");
    printf(" | |___| | |_) | | | |  __/ |   \n");
    printf("  \\____|_| .__/|_| |_|\\___|_|   \n");
    printf("         |_|                    \n \x1b[0m");
}

char *code(char process[])
{
    int length = strlen(process);
    int ascii[length];
    int cascii[length];
    for (int i = 0; i <= length - 1; i++)
    {
        ascii[i] = process[i];
        // start ciphering
        cascii[i] = ascii[i] + length;
        while (cascii[i] > 126)
        {
            cascii[i] -= 94;
        }
        process[i] = cascii[i];
    }

    return process;
}
char *decode(char process[])
{
    int length = strlen(process);
    int ascii[length];
    int cascii[length];
    for (int i = 0; i <= length - 1; i++)
    {
        ascii[i] = process[i];
        // start deciphering
        cascii[i] = ascii[i] - length;
        while (cascii[i] < 32)
        {
            cascii[i] += 94;
        }
        process[i] = cascii[i];
    }

    return process;
}
//little spaghetti
int main(int argc, char *argv[])
{
    char text[5000];
    char selection;
    logo();
    if (argv[1] == NULL)
    {
        printf("\nWhat do you want to do:\n1.Cipher\n2.Decipher\n-> ");
        selection = getchar();
        getchar();
    }
    else if (strcmp(argv[1], "code") == 0) {
        selection = '1';
    }
    else if (strcmp(argv[1], "decode") == 0){
        selection = '2';
    }
    else if (strcmp(argv[1], "help") == 0){
        printf("\n code - ciphering mode\n decode - deciphering mode\n Usage examples:\n ./main.exe code\n ./main decode\n ./main \n \n");
        return 0;
    }
    else{
        printf("Use ./main help for usage examples");
        return 1;
    }

    switch (selection)
    {
    case '1':
    case '2':
        printf("gimme some text bro -> ");
        fgets(text, sizeof(text), stdin);
        size_t len = strlen(text);
        if (len > 0 && text[len - 1] == '\n')
        {
            text[len - 1] = '\0';
        }
        break;
    default:
        printf("Selection error");
        break;
    }

    switch (selection)
    {
    case '1':
        printf("\"%s\"\n", code(text));
        break;
    case '2':
        printf("\"%s\"\n", decode(text));
        break;
    default:
        break;
    }

    return 0;
}