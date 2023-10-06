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


// TODO: review flow of this function so returning does not cause memory leaks,
// but is also useful to the user
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

    // try setting the interface
    if ((ret_code = ftdi_set_interface(ftdi_ctx, INTERFACE_ANY)) < 0)
    {
        ftdi_free(ftdi_ctx);
        perror("Error setting FTDI interface");
        return ret_code;
    }

    // check list of FTDI USB devices connected to the system
    //     if ret_code is 0 or less, then no USB devices were found
    if ((ret_code = ftdi_usb_find_all(ftdi_ctx, &devlist, 0, 0)) > 0)
    {
        // try to open one of the devices
        printf("Found %d FTDI devices...\n", ret_code);
        while (
            (ret_code = ftdi_usb_open_dev(ftdi_ctx, devlist->dev)) < 0
        ) {
            devlist = devlist->next;  // memory leak?
        }
    }

    // check for unsuccessful connection
    if (ret_code < 0)
    {
        ftdi_free(ftdi_ctx);
        ftdi_list_free(&devlist);
        perror("Error connecting to an FTDI device");
        return ret_code;
    }
    
    // try setting the baudrate
    if ((ret_code = ftdi_set_baudrate(ftdi_ctx, baudrate)) < 0)
    {
        ftdi_free(ftdi_ctx);
        ftdi_list_free(&devlist);
        perror("Error setting baudrate for FTDI device");
        return ret_code;
    }

    // TODO: get a full grasp of what these properties mean
    // try setting line properties
    if ((ret_code = ftdi_set_line_property(ftdi_ctx, BITS_8, STOP_BIT_2, NONE)) < 0)
    {
        ftdi_free(ftdi_ctx);
        ftdi_list_free(&devlist);
        perror("Error setting line properties for FTDI device");
        return ret_code;
    }

    // assume connection and setup was a success
    return ret_code;
}


int close_device(void)
{
    signal(SIGINT, SIG_DFL);
    ftdi_free(ftdi_ctx);
    
    return ftdi_usb_close(ftdi_ctx);
}


// TODO: make use of command()
int get_adapter_num(char* adapt_num)
{
    int ret_code = -1;  // assume failure
    char cmd[DEFAULT_BUF_SIZE] = ADAPT_NUM_REQ;
    char response[DEFAULT_BUF_SIZE];

    // TODO: might need to open wires for communication

    if ((ret_code = command(cmd, response)) < 0)
    {
        perror("Error completing adapter number request");
        return ret_code;
    }

    return ret_code;
}


int command(const char* cmd, char* response)
{
    int ret_code = -1;  // assume failure
    
    return ret_code;
}


#endif /* DEVICE_OPS_C */
