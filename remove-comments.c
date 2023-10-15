#include <stdio.h>

int getline2(char s[], int lim);
void clear(char s[], int lim);

enum STATE {
    normal = 0,
    comment = 1,
    slash_comment = 2,
    string = 3,
    char_string = 4,
};

int main()
{
    /* some random comment */
    enum STATE state = normal;
    char s[10000];
    for(int i = getline2(s,10000); i != -1 ; i = getline2(s,10000))
    {
        for (int x = 0; x <= i; ++x) {
            if(state == normal) {
                // normal -> string/char
                if(s[x] == '"') {
                    state = string;
                    putchar(s[x]);
                }
                else if(s[x] == '\'') {
                    state = char_string;
                    putchar(s[x]);
                }
                // normal -> comment
                else if(s[x] == '/' && x + 1 <= i && s[x+1] == '*')
                {
                    state = comment;
                    x += 1;
                    continue;
                }
                // normal -> slash comment
                else if(s[x] == '/' && x + 1 <= i && s[x+1] == '/') {
                    state = slash_comment;
                    x += 1;
                    continue;
                }
                /* any other character */
                // any other character
                else {
                    putchar(s[x]);
                }
            }
            else if(state == string || state == char_string)
            {
                /* backslash ignorer */
                if(s[x] == '\\' && x + 2 <= i) {
                    putchar(s[x]);
                    x += 1;
                    putchar(s[x]);
                    continue;
                }
                // char_string -> normal
                else if(s[x] == '\'' && state == char_string) {
                    state = normal;
                    putchar(s[x]);
                }
                /* string -> normal */
                else if(s[x] == '"' && state == string){
                    state = normal;
                    putchar(s[x]);
                }
                else putchar(s[x]);
            }
            else if(state == comment)
            {
                if(s[x] == '*' && x + 1 <= i && s[x+1] == '/')
                {
                    state = normal;
                    x += 1;
                }
            }
            else if(state == slash_comment)
            {
                if(s[x] == '\n') {
                    state = normal;
                    putchar(s[x]);
                }
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
