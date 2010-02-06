/* This header file is part of the ATMEL AVR-UC3-SoftwareFramework-1.6.1 Release */

/*This file has been prepared for Doxygen automatic documentation generation.*/
/*! \file *********************************************************************
 *
 * \brief Navigation automatic Services.
 *
 * Automatic navigation has been developed for the player and viewer.
 * The plug-in provides a specific "file list".
 * The "file list" contains all files included in a playlist or it is built with the following user specifications :
 *   - extension filter
 *   - limitation scan (folder, folder and sub folder, one disk, all disks)
 * The plug-in can manage a random feature.
 * Note: The play list limitations is 65535 files.
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.no/
 *
 *****************************************************************************/

/* Copyright (c) 2009 Atmel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an Atmel
 * AVR product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE
 *
 */

#ifndef _NAVAUTO_H_
#define _NAVAUTO_H_

#include "fs_com.h"
#include "fat.h"
#include "navigation.h"
#include "play_list.h"

//! Structure to store the directory limitation of the file list
typedef  U8    Navauto_mode;

//! \name Definition of the directory limitations of the file list
//! @{
#define  NAVAUTO_MODE_DISKS          0
#define  NAVAUTO_MODE_DISK           1
#define  NAVAUTO_MODE_DIRONLY        2
#define  NAVAUTO_MODE_DIRSUB         3
#define  NAVAUTO_MODE_NB             4
//! @}

//! Structure to store the random state
typedef  U8    Navauto_rand;

//! \name Definition of the random states
//! @{
#define  NAVAUTO_RAND_OFF            0
#define  NAVAUTO_RAND_ON             1
//! @}

typedef union
{
  U8 all;
  struct
  {
    U8                      : 7;
    U8 folder_change        : 1;
  };
} Navauto_mov_bitfield_status;

//! Structure to store the status from function navauto_mov()
typedef struct
{
  U8 status;
  Navauto_mov_bitfield_status bitfield;
} Navauto_mov_state;


//! \name Status list of function navauto_mov()
//! @{
#define  NAVAUTO_MOV_OK              0
#define  NAVAUTO_MOV_OK_LOOP         1
#define  NAVAUTO_MOV_EMPTY           2
#define  NAVAUTO_MOV_DISKNOPRESENT   3
#define  NAVAUTO_MOV_DISKERROR       4
//! @}

Navauto_mode   navauto_getmode        ( void );
Bool           navauto_setmode        ( Navauto_mode exp_mode );
Navauto_rand   navauto_getrand        ( void );
void           navauto_setrand        ( Navauto_rand rand );
void           navauto_init           ( const FS_STRING sz_filterext );
Bool           navauto_open           ( Bool b_playlist , U16 pos );
U16            navauto_close          ( void );
U16            navauto_getnb          ( void );
U16            navauto_getpos         ( void );
Bool           navauto_setpos         ( U16 u16_pos );
typedef enum
{
  NAVAUTO_MOV_OPTS_NONE               = 0,
  NAVAUTO_MOV_OPTS_STAY_CURRENT_DIR   = 1
} navauto_mov_options_t;
Navauto_mov_state navauto_mov         ( Bool b_direction, navauto_mov_options_t options );

#endif  // _NAVAUTO_H_
