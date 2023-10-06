#ifndef UTILS_C
#define UTILS_C


#include "../include/utils.h"


int rec_response(unsigned char* rec, const int size)
{
    return -1;
}


int send_cmd(const unsigned char* chip_cmd, const int size)
{
    return -1;
}


int translate(char* cmd, unsigned char* translated)
{
    int num = 0;
    int t_idx = 0;

    char* tok = strtok(cmd, ";");
    while (tok != NULL)
    {
        if (tok[0] == '$')
        {
            sscanf(tok + 1, "%x", &num);
        }
        else
        {
            sscanf(tok, "%d", &num);
        }
        tok = strtok(NULL, ";");
        translated[t_idx += 1] = num;
    }

    // return number of bytes translated
    return t_idx;
}


#endif /* UTILS_C */
