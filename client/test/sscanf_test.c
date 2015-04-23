#include <stdio.h>

int
main(void)
{
    char key[20], value[20];
    char test[] = "user name=Joe";
    sscanf(test, "%s=%s", key, value);

    printf("key: %s, value: %s\n", key, value);
    return 0;
}