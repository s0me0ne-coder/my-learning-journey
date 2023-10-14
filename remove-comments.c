#include <stdio.h>

int getline2(char s[], int lim);
void clear(char s[], int lim);

int main()
{
    /* some random comment */
    int backslash = 0;
    char s[10000];
    int empty_lines = 0;
    int in_string = 0;
    int in_char = 0;
    int in_comment = 0;
    int in_slash_comment = 0;
    for(int i = getline2(s,10000); i != -1 ; i = getline2(s,10000))
    {
        for (int x = 0; x <= i; ++x) {
            if(s[x] == '"') {
                in_string = 1;
            } else if(s[x] == '\'') {
                in_char = 1;
            } else if(s[x] == '/' && x + 1 <= i &&  s[x+1] == '*') {
                in_comment = 1;
                x += 1;
                continue;
            } else if(s[x] == '/' && x + 1 <= i && s[x+1] == '/') {
                in_slash_comment = 1;
                x += 1;
                continue;
            }

            if(in_slash_comment == 1 && s[x] == '\n') {
                in_slash_comment = 0;
                putchar(s[x]);
                continue;
            }

            if(in_comment == 0 && in_slash_comment == 0) {
                putchar(s[x]);
            }  else if(s[x] == '*' && x + 1 <= i && s[x+1] == '/') {
                in_comment = 0;
                x += 1;
                continue;
            }

        }
    }
    return 0;
}


int getline2(char s[], int lim)
{
    int i,c = 0;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n' ; ++i)
    {
        s[i] = c;
    }
    if(c == '\n')
    {
        s[i] = c;
    }
    if(c == EOF) return -1;
    return i;
}

void clear(char s[], int lim)
{
    for(int i = 0; i < lim; ++i)
    {
        s[i] = '\0';
    }
}
