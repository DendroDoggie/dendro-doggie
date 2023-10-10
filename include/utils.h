#ifndef UTILS_H
#define UTILS_H


#include <stdio.h>
#include <string.h>
#include <libftdi1/ftdi.h>


/*
 * Receives a response from the FTDI device
 * @rec memory location to put the response
 * @size length of the response buffer
 * @return status of operation
 */
int rec(struct ftdi_context* ftdi_ctx, unsigned char* rec, const int size);


/*
 * Sends a chip command to the FTDI device
 * @chip_cmd command for the chip
 * @size length of the command
 * @return status of operation
 */
int send(
    struct ftdi_context* ftdi_ctx,
    const unsigned char* chip_cmd,
    const int size
 );


/*
 * Translates pseudo human-readable command to an FTDI chip command
 * @cmd command which needs to be sent to the device
 * @translated command translated to FTDI chip-reable
 */
int translate(char* cmd, unsigned char* translated);


#endif /* UTILS_H */
