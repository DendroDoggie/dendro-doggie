/*
 * Source for device operations
 *
 * Translated and extended by DendroDawgz from October 3rd, 2023 to Present
 */

#ifndef DEVICE_OPS_C
#define DEVICE_OPS_C

#include "../include/device_ops.h"


struct ftdi_context* ftdi;


int open_device(int baud_rate)
{
    int ret_code = -1;  // assume failure
    struct ftdi_device_list* dev_list;

    ftdi = ftdi_new();
    // check device was created and initialized
    if (ftdi == NULL)
    {
        ftdi_free(ftdi);
        return FT_OPEN_FAIL;
    }

    ftdi_set_interface(ftdi, INTERFACE_ANY);
    // check list of FTDI USB devices connected to the system
    if ((ret_code = ftdi_usb_find_all(ftdi, &dev_list, 0, 0)) < 0)
    {
        ftdi_free(ftdi);
        return FT_OPEN_FAIL;
    }
    
    return FT_OPEN_OK;
}

int close_device(void)
{
    signal(SIGINT, SIG_DFL);
    ftdi_usb_close(ftdi);
    ftdi_free(ftdi);
    
    return FT_OPEN_OK;
}

int get_adapter_num(char* adapt_num)
{
    return FT_OPEN_OK;
}

int command(const char* cmd, char* response)
{
    return FT_OPEN_OK;
}


#endif /* DEVICE_OPS_C */
