/*
 * DendroDoggie backend driver
 *
 * Translate and extended by DendroDawgz from October 1st, 2023 to Present
 */

#include <stdio.h>
#include <stdlib.h>
// other includes


int main(int argc, char* argv[])
{
    int ret_code = -1; // assume device open failure
    char cmd_response[0xffff];  // 65535

    printf("Opening FTDI device...\n");
    ret_code = open_device(DEFAULT_BAUD_RATE);  // set to 500000
    // check and report device openning op
    if (ret_code < 0)
    {
        printf("Error opening device");
        exit(EXIT_FAILURE);
    }

    // get adapter number
    char adapter[ADAPTER_LENGTH];  // set to 21
    ret_code = get_adapter_num(adapter);
    printf("res = %d, adapter = %s\n", ret_code, adapter);

    // set pointer to flash -> better desc
    ret_code = command("S=$000000", cmd_response);
    if (ret_code)
    {
        printf("%s\n", cmd_response);
    }

    FILE* file_h = fopen()
}
