/*
 * Header for device operations
 *
 * Translated and extended by DendroDawgz from October 3rd, 2023 to Present
 */

#ifndef DEVICE_OPS_H
#define DEVICE_OPS_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <libftdi1/ftdi.h>


#define ADAPTER_LENGTH 21
#define DEFAULT_BAUD_RATE 500000

enum DeviceOpCodes
{
    FT_OPEN_OK = 0,
    FT_OPEN_FAIL = 1,
    WRITE_FAIL = 2,
    READ_FAIL = 3,
    // power off codes
};

/*
 * Open link to dendrometer over USB interface
 * @baudrate sets the number of bits per second which can be sent and
 *            recieved from the dendrometer
 * @return status code of operation
 */
int open_device(int baudrate);

/*
 * Closes link to dendrometer
 * @return status code of operation
 */
int close_device(void);

/*
 * Gets device's serial number - tentative
 * @adapt_num place in memory to store the serial number for later use
 * @return status code of operation
 */
int get_adapter_num(char* adapt_num);

/*
 * Sends command to dendrometer
 * @cmd command to send
 * @response place in memory to store dendrometer's response
 * @return status code of operation
 */
int command(const char* cmd, char* response);


#endif /* DEVICE_OPS_H */
