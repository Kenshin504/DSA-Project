char* replaceSubstring(const char str1[], const char cmp[], const char replace[]);


void replace()
{
    clearScreen();
    clearBuffer();
    char str1[100];
    char cmp[100];
    char replace[100];
    char *result = NULL;

    printf("------ %sString Replace%s -------\n", GRN, RESET);
    printf("Enter String: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter Substring to Replace: ");
    fgets(cmp, sizeof(cmp), stdin);
    cmp[strcspn(cmp, "\n")] = '\0';

    printf("Enter Replacement String: ");
    fgets(replace, sizeof(replace), stdin);
    replace[strcspn(replace, "\n")] = '\0';

    result = replaceSubstring(str1, cmp, replace);

    clearScreen();
    printf("---- %sString Replace Complete%s ----\n", GRN, RESET);
    printf("Old String: %s\n", str1);
    printf("New String: %s", result);

    free(result);
    getchar();
}


char* replaceSubstring(const char str1[], const char cmp[], const char replace[])
{
    char *result;
    int i, cnt = 0;
    int cmpLen = strlen(cmp);
    int replaceLen = strlen(replace);

    for(i = 0; str1[i] != '\0'; i++)
    {
        if(strstr(&str1[i], cmp) == &str1[i])
        {
            cnt++;
            i += cmpLen - 1;
        }
    }

    result = malloc(i + cnt * (replaceLen - cmpLen) - 1);

    i = 0; 
    while(*str1)
    {
        if(strstr(str1, cmp) == str1)
        {
            strcpy(&result[i], replace);
            i += replaceLen;
            str1 += cmpLen;
        }
        else
            result[i++] = *str1++;
    }

    result[i] = '\0';
    return result;
}