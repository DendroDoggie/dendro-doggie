#ifndef UTILS_C
#define UTILS_C


#include "../include/utils.h"


int rec(struct ftdi_context* ftdi_ctx, unsigned char* rec, const int size)
{
    int rec_bytes = 0;
    int total_bytes = 0;

    while (total_bytes < size)
    {
        if ((rec_bytes = ftdi_read_data(ftdi_ctx, rec, size - total_bytes)) < 0)
        {
            perror("Error reading chip response");
            return rec_bytes;
        }

        total_bytes += rec_bytes;
    }

    return 0;  // assume all bytes were sent
}


int send(
    struct ftdi_context* ftdi_ctx,
    const unsigned char* chip_cmd,
    const int size
) {
    int sent_bytes = 0;
    int total_bytes = size;

    while (total_bytes > 0)
    {
        if (
            (sent_bytes = ftdi_write_data(
                ftdi_ctx, chip_cmd, total_bytes - sent_bytes
            )) < 0
        ) {
            perror("Error sending chip command");
            return sent_bytes;
        }

        total_bytes -= sent_bytes;
    }

    return 0;  // assume all bytes were sent
}


int translate(char* cmd, unsigned char* translated)
{
    int num = 0;
    size_t t_idx = 0;

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
        translated[t_idx + 1] = num;
        t_idx += 1;
    }

    // return number of bytes translated
    return t_idx;
}


#endif /* UTILS_C */
