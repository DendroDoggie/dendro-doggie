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
#include "./utils.h"


#define DEFAULT_BUF_SIZE 32
#define DEFAULT_BAUD_RATE 500000

// device commands
#define NOT_DEV_RESPONSE "-666"
#define ADAPT_NUM_REQ "1;$F0"


/*
 * Closes link to dendrometer
 * @return status code of operation
 */
int close_device(void);


/*
 * Sends command to dendrometer
 * @cmd command to send
 * @response place in memory to store dendrometer's response
 * @return status code of operation
 */
int command(char* cmd, char* response);


/*
 * Gets device's serial number - tentative
 * @adapt_num place in memory to store the serial number for later use
 * @return status code of operation
 */
int get_adapter_num(char* adapt_num);


/*
 * Open link to dendrometer over USB interface
 * @baudrate sets the number of bits per second which can be sent and
 *           recieved from the dendrometer
 * @return status of operation
 */
int open_device(int baudrate);


#endif /* DEVICE_OPS_H */
