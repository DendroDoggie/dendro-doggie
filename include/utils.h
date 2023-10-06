#ifndef UTILS_H
#define UTILS_H


/*
 * Translates pseudo human-readable command to an FTDI chip command
 * @cmd command which needs to be sent to the device
 * @translated command translated to FTDI chip-reable
 */
int translate(char* cmd, unsigned char* translated);


#endif /* UTILS_H */
