#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void trim_spaces(char *str)
{
    int i;
    int begin = 0;
    int end = strlen(str) - 1;

    while (isspace((unsigned char) str[begin]))
        begin++;

    while ((end >= begin) && isspace((unsigned char) str[end]))
        end--;

    for (i = begin; i <= end; i++)
        str[i - begin] = str[i];

    str[i - begin] = '\0'; 
}

void remove_blankets(char *input)
{
    int i = 0,j,n = strlen(input);

    trim_spaces(input);

    while (i < n) {
        if(input[i]==' ' && (input[i+1]==' ' || input[i-1]==' '))
        {
            for(j=i;j<n;j++)
            input[j]=input[j+1];
            n--;
        }
        else
        {
            i++;
        }
    }
    input[i] = '\0';
}

int count_char(char ch, char* str)
{
    int i, len = strlen(str), count = 0;
    for (i=0;i<len;i++) if (str[i]==ch) count++;
    return count;
}

char* handle_str(char* input)
{
    char *res, charToRemove;
    int i = 0, j, newLen, resultLen, charCount;

    while (input[i] == ' ')
    {
        i++;
    }
    charToRemove = input[i];

    charCount = count_char(charToRemove, input);

    newLen = strlen(input) - charCount;

    res = (char*)malloc(newLen*sizeof(char));
   
    for (i=0, j=i; i<newLen;i++, j++) 
    {
        if(input[j] == charToRemove)
        {
            i--;
        } else {
            res[i] = input[j];
        }
    }

    remove_blankets(res);
    trim_spaces(res);

    return res;
}

int main(int argc,char* argv[])
{
    char buffer[256], *res;
    int rc;

    while(rc != EOF)
    {
        rc = scanf("%[^\n]s", buffer);
        scanf("%*c");
        if (rc == 1) {
            res = handle_str(buffer);
            printf("%s\n", res);
        }
    }
    return 0;
}