/******************************************************************************
 *   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER.
 *
 *   This file is part of Real VMX.
 *   Copyright (C) 2013 Surplus Users Ham Society
 *
 *   Real VMX is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Real VMX is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Real VMX.  If not, see <http://www.gnu.org/licenses/>.
 */

/* unistd.h - Unix I/O */

#ifndef _UNISTD_H
#define _UNISTD_H

#include <os/ioLib.h>
#include <os/pathLib.h>

/* File positions */
#define SEEK_SET        0       /* set file offset to offset */
#define SEEK_CUR        1       /* set file offset to current + offset */
#define SEEK_END        2       /* set file offset to EOF + offset */

/* Standard file descriptors */
#define STDIN_FILENO    0       /* Standard input */
#define STDOUT_FILENO   1       /* Standard output */
#define STDERR_FILENO   2       /* Standard error output */

/* Command names for pathconf and fpathconf */
#define _PC_2_SYMLINKS          1
#define _PC_ALLOC_SIZE_MIN      2
#define _PC_ASYNC_IO            3
#define _PC_CHOWN_RESTRICTED    4
#define _PC_FILESIZEBITS        5
#define _PC_LINK_MAX            6
#define _PC_MAX_CANON           7
#define _PC_MAX_INPUT           8
#define _PC_NAME_MAX            9
#define _PC_NO_TRUNC            10
#define _PC_PATH_MAX            11
#define _PC_PIPE_BUF            12
#define _PC_PRIO_IO             13
#define _PC_REC_INCR_XFER_SIZE  14
#define _PC_REC_MAX_XFER_SIZE   15
#define _PC_REC_MIN_XFER_SIZE   16
#define _PC_REC_XFER_ALIGN      17
#define _PC_SYMLINK_MAX         18
#define _PC_SYNC_IO             19
#define _PC_VDISABLE            20

#ifndef _ASMLANGUAGE

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * read - Read from a file or device
 *
 * RETURNS: Bytes read or ERROR
 */

int read(
    int    fd,
    void  *buffer,
    size_t nBytes
    );

/******************************************************************************
 * write - Write a file or device
 *
 * RETURNS: Bytes written or ERROR
 */

int write(
    int    fd,
    void  *buffer,
    size_t nBytes
    );

/******************************************************************************
 * isatty - Check if device is a terminal
 *
 * RETURNS: TRUE or FALSE
 */

int isatty(
    int fd
    );

/******************************************************************************
 * close - Close a file
 *
 * RETURNS: OK or ERROR
 */

int close(
    int fd
    );

/******************************************************************************
 * chdir - Set current working directory
 *
 * RETURNS: OK or ERROR
 */

int chdir(
    char *path
    );

/***************************************************************************
 * getcwd - get current working directory
 *
 * It is assumed that the current working directory will always have a
 * trailing '/' character.
 *
 * RETURNS: <buf> on success, NULL otherwise
 */

char* getcwd(
    char  *buf,
    size_t size
    );

/******************************************************************************
 * rmdir - remove a directory
 *
 * RETURNS: OK on success, ERROR otherwise
 */

STATUS rmdir(
    const char *path      /* path to directory to remove */
    );

/******************************************************************************
 * symlink - create a symlink
 *
 * RETURNS: OK on success, ERROR otherwise
 */

STATUS symlink(
    const char *path,     /* path to symlink to create */
    const char *target,   /* path against which to link */
    mode_t      mode      /* file permission bits */
    );

/******************************************************************************
 * readlink - read a symlink
 *
 * RETURNS: # of bytes in buffer on success, or ERROR otherwise
 */

ssize_t readlink(
    const char *path,
    char       *buf,
    size_t      bufsize
    );

/******************************************************************************
 * fpathconf - get configurable path variables
 *
 * RETURNS: current configurable value or limit on success, ERROR otherwise
 */

long fpathconf(
    int fd,
    int name
    );

/******************************************************************************
 * pathconf - get configurable path variables
 *
 * RETURNS: current configurable value or limit on success, ERROR otherwise
 */

long pathconf(
    const char *path,
    int         name
    );

/******************************************************************************
 * ftruncate - truncate a file
 *
 * RETURNS: OK on success, ERROR otherwise
 */

int ftruncate(
    int   fd,
    off_t length
    );

/***************************************************************************
 * lseek - seek to within a position in the file
 *
 * RETURNS: new position on success, ERROR otherwise
 */

off_t lseek(
    int   fd,
    off_t offset,
    int   whence
    );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ASMLANGUAGE */

#endif /* _UNISTD_H */

