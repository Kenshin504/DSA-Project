void deletion(char str[], char substr[]);


void delete()
{
    clearScreen();

    char str[100];
    char substr[100];
    
    printf("---- %sString Deletion%s ----\n", GRN, RESET);
    printf("Enter string: ");
    scanf(" %99[^\n]", str);
    while(getchar() != '\n');

    printf("Enter substring to delete: ");
    scanf(" %99[^\n]", substr);
    while(getchar() != '\n');

    deletion(str, substr);

    printf("---- %sDeletion Complete%s ----\n", GRN, RESET);
    printf("%s", str);

    getchar();
}


void deletion(char str[], char substr[])
{
    int i = 0;
    int string_length = strlen(str);
    int substring_length = strlen(substr);

    while(i < string_length)
    {
        if(strstr(&str[i], substr) == &str[i])
        {
            string_length -= substring_length;

            for(int j = i; j < string_length; j++)
                str[j] = str[j + substring_length];
        }
        else
            i++;
    }

    str[i] = '\0';
}