/*
 * DendroDoggie backend driver
 *
 * Translate and extended by DendroDawgz from October 1st, 2023 to Present
 *
 * Resouces:
 * 1) https://www.intra2net.com/en/developer/libftdi/documentation/
 */

#include <stdio.h>
#include <stdlib.h>
// write repo in such a way we don't have to give relative path to headers
#include "../include/device_ops.h"
// other includes


int main(int argc, char* argv[])
{
    int ret_code = -1;  // assume device open failure
    char cmd_response[0xffff];  // 65535

    printf("Opening FTDI device...\n");
    ret_code = open_device(DEFAULT_BAUD_RATE);
    // check and report device openning op
    if (ret_code < 0)
    {
        exit(EXIT_FAILURE);
    }

    // get adapter number
    char adapter[DEFAULT_BUF_SIZE];
    ret_code = get_adapter_num(adapter);
    printf("Result = %d, Adapter = %s\n", ret_code, adapter);

    // set pointer to flash -> better desc
    ret_code = command("S=$000000", cmd_response);
    if (ret_code > 0)
    {
        printf("%s\n", cmd_response);
    }

    FILE* file_h = fopen("./output.txt", "w");
    for (int i = 0; i < 150; i += 1)
    {
        fprintf(file_h, "**************\n");

        ret_code = command("D", cmd_response);
        if (ret_code)
        {
            fprintf(file_h, "%s\n", cmd_response);
        }
    }
    fclose(file_h);

    ret_code = close_device();

    return 0;
}
