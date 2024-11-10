#include <iostream>
#include <string>

void logo()
{
    std::cout << "\x1b[34m   ____ _       _               \n";
    std::cout << "  / ___(_)_ __ | |__   ___ _ __ \n";
    std::cout << " | |   | | '_ \\| '_ \\ / _ \\ '__|\n";
    std::cout << " | |___| | |_) | | | |  __/ |   \n";
    std::cout << "  \\____|_| .__/|_| |_|\\___|_|   \n";
    std::cout << "         |_|                    \n \x1b[0m";
}

std::string code(std::string process)
{
    int len = process.length();
    int ascii[len];
    int cascii[len];
    for (int i = 0; i <= len - 1; i++)
    {
        ascii[i] = process[i];
        // start ciphering
        cascii[i] = ascii[i] + len;
        while (cascii[i] > 126)
        {
            cascii[i] -= 94;
        }
        process[i] = cascii[i];
    }

    return process;
}
std::string decode(std::string process)
{
    int len = process.length();
    int ascii[len];
    int cascii[len];
    for (int i = 0; i <= len - 1; i++)
    {
        ascii[i] = process[i];
        // start deciphering
        cascii[i] = ascii[i] - len;
        while (cascii[i] < 32)
        {
            cascii[i] += 94;
        }
        process[i] = cascii[i];
    }

    return process;
}

void selection()
{
    std::string text;
    char selection;
    logo();

    std::cout << "\nWhat do you want to do:\n1.Cipher\n2.Decipher\n-> ";
    std::cin >> selection;

    // little repeating code but the making
    switch (selection)
    {
    case '1':
        std::cout << "gimme some text bro -> ";
        std::getchar();
        std::getline(std::cin, text);
        std::cout << "\"" << code(text) << "\"";
        break;
    case '2':
        std::cout << "gimme some text bro -> ";
        std::getchar();
        std::getline(std::cin, text);
        std::cout << "\"" << decode(text) << "\"";
        break;

    default:
        std::cout << "error entering selection";
        break;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        selection();
    }
    
    return 0;
}