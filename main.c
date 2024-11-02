#include <stdio.h>
#include <string.h>

char *code(char process[])
{
    int length = strlen(process);
    int ascii[length];
    int cascii[length];
    for (int i = 0; i <= length - 1; i++)
    {
        ascii[i] = process[i];
        //start ciphering
        cascii[i] = ascii[i] + length;
        while (cascii[i] > 126)
        {
            cascii[i] -= 126;
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
        //start ciphering
        cascii[i] = ascii[i] - length;
        while (cascii[i] < 0)
        {
            cascii[i] += 126;
        }
        process[i] = cascii[i];
    }

    return process;
}

int main()
{
    char text[] = "";
    // get a text to code
    printf("gimme some text bro -> ");
    scanf("%s", text);

    printf("%s ", code(text));
}