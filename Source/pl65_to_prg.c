/* Convert EOL from Unix to Atari
   Also skip PL65 comments !
 */
#include <stdio.h>

void display_usage(void);

#define A8_EOL 0x9b

int main (int argc, char* argv[])
{
    FILE* fp; 
    unsigned char ch;
    char state = 0;

    if (argc != 2)
    {
        display_usage();
        return(1);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        fprintf (stderr, "Unable to open [%s] for read\n", argv[1]);
        return(1);
    }

    /* while (!feof(fp)) */
    while (state >= 0)
    {
        ch = fgetc(fp);
        if (feof(fp)) { state = -1; }
        else
        {
            /* Convert Unix EOL to Atari 8-bit EOL */
            if (ch == '\n') { ch = A8_EOL; }

            if (state == 0 && ch == '"') 
                state = 1;
            else if (state == 1 && (ch == '"' || ch == A8_EOL))
                state = 0;
            else if (state == 0 && ch == '!') 
                state = 2;
            else if (state == 2 && (ch == A8_EOL))
                state = 3;
            else if (state == 3 && (ch == '!'))
                state = 2;
            else if (state == 3 && (ch != '!'))
                state = 0;

            /* Skip comments (!) */
            if (state == 0 || state == 1) fputc(ch, stdout);
        }
    }

    fclose(fp);
    
    return(0);
}

void display_usage(void)
{
    fprintf(stderr, "Usage: ascii2atascii <filename>\n");
    fprintf(stderr, "Output sent to stdout\n");
    return;
}
