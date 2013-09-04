#include <stdio.h>
#include "tester.h"

const int max_command = 1;
int command = 0;

void show_command()
{
    printf("Type the number to choose what to test:\n");
    
    printf("  (0) Exit.\n");
    printf("  (1) Assertion test.\n");

    printf("\n");
    printf("Please input: ");
}

bool receive_command()
{
    char cmd[256];
    scanf("%s", cmd);
    command = atoi(cmd);

    if(command < 0 || command > max_command)
    {
        return false;
    }

    return true;
}

bool test_command()
{
    switch(command)
    {
    case 1:
        {
            test_assertion();
            return false;
        }

    case 0:
    default: return true;
    }
}

int main()
{
    while(1)
    {
        show_command();
        if(receive_command())
        {
            if(test_command()) return 0;
        }
        else
        {
            printf("Please input a valid command.\n");
        }
    }

    return 0;
}
