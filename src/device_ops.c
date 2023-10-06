/*
 * Source for device operations
 *
 * Translated and extended by DendroDawgz from October 3rd, 2023 to Present
 */

#ifndef DEVICE_OPS_C
#define DEVICE_OPS_C

#include "../include/device_ops.h"


// try to make this NOT a global?
struct ftdi_context* ftdi_ctx;


int open_device(int baudrate)
{
    int ret_code = -1;  // assume failure
    struct ftdi_device_list* devlist;

    ftdi_ctx = ftdi_new();
    // check device was created and initialized
    if (ftdi_ctx == NULL)
    {
        perror("Error creating FTDI context");
        return ret_code;  // early bail since it is easy
    }

    // check list of FTDI USB devices connected to the system
    //     if ret_code is 0 or less, then no USB devices were found
    if ((ret_code = ftdi_usb_find_all(ftdi_ctx, &devlist, 0, 0)) > 0)
    {
        // try to open one of the devices
        printf("Found %d USB devices!\n", ret_code);
        while (
            (ret_code = ftdi_usb_open_dev(ftdi_ctx, devlist->dev)) < 0
        ) {
            devlist = devlist->next;  // memory leak?
        }
    }
    
    // try setting the interface
    if ((ret_code = ftdi_set_interface(ftdi_ctx, INTERFACE_ANY)) < 0)
    {
        perror("Error setting FTDI interface");
    }

    // try setting the baudrate
    if ((ret_code = ftdi_set_baudrate(ftdi_ctx, baudrate)) < 0)
    {
        perror("Error setting baudrate for FTDI device");
    }

    // TODO: get a full grasp of what these properties mean
    // try setting line properties
    if ((ret_code = ftdi_set_line_property(ftdi_ctx, BITS_8, STOP_BIT_2, NONE)) < 0)
    {
        perror("Error setting line properties for FTDI device");
    }

    // check process was unsuccessful
    if (ret_code < 0)
    {
        ftdi_free(ftdi_ctx);
        ftdi_list_free(&devlist);
    }
    
    return ret_code;
}

int close_device(void)
{
    signal(SIGINT, SIG_DFL);
    ftdi_usb_close(ftdi_ctx);
    ftdi_free(ftdi_ctx);
    
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
