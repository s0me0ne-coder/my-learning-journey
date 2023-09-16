#include <stdio.h>
#define ARRAY_SIZE 1000000
#define FOLD_AFTER 10
/* writes the first line
 * from stdin into input_array
 * until lim is reached 
 * returns line length
 */
int getline2(char input_array[], int lim);

/*
 * initializes an empty character array with \0
*/
void clear(char array[], int array_size);

int main() {
    /*test getline2 real quick*/
    char s[ARRAY_SIZE];
    clear(s,ARRAY_SIZE);

    /* a loop over all lines obtained from user input */
    for(int i = getline2(s,ARRAY_SIZE); i > 0; i = getline2(s,ARRAY_SIZE))
    {

        /* print something to pick apart the result and input */
        /*printf("*");*/
        /* a loop over all characters of given line */

        int y = 0;
        for(int x = 0; x <= i; ++x)
        {
            if(y > FOLD_AFTER) {
                putchar('\n');
                putchar(s[x]);
                y = 0;
            }
            else {
                putchar(s[x]);
            }
            y += 1;
        }
    }
}


int getline2(char s[], int lim)
{
    int c = 0;
    int i = 0;
    for(; i < lim - 1  && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    /* add in the detected newline for convinence */
    if(c == '\n')
    {
        s[i] = c;
    }
    return i;
}

void clear(char s[], int size) {
    for (int i = 0; i < size; ++i)
    {
        s[i] = '\0';
    }
}