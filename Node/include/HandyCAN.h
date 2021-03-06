/**
 * @file    HandyCAN.h
 * @author  SirVolta
 * @date    Sep 18, 2017
 * @brief   HandyCAN node library
 * @note    Function descriptions are in source file
 */
/*
 Copyright (C) 2017 Pelle Sepp Florens Jansen

 This file is part of HandyCAN Node

 HandyCAN is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 HandyCAN is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with HandyCAN.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef HANDYCAN_H_
#define HANDYCAN_H_
#include "stm32f10x_conf.h"

/// The current version of handycan
#define HC_VERSION 1

/// Destination address mask
#define HC_DEST_MASK 0x1F

/// Source address mask
#define HC_SRC_MASK 0x3E0
/// Source address offset
#define HC_SRC_OFFSET 5

/// Reserved ID bit
#define HC_RESERVED_BIT 0x400
/// Reserved ID bit offset
#define HC_RESERVED_BIT_OFFSET 10

///HandyCAN broadcast address
#define HC_BROADCAST_ADDR 0x1F

///CAN transmit timeout (unused at the moment)
#define HC_CAN_SEND_TIMEOUT 0xFFFFF

/// If this is set to 1, statistsics are kept
#define HC_KEEP_STATISTICS 1

/// @brief local state and configuration info
struct HandyCAN_package
{
  /// Destination address
  uint8_t dest_adress;
  /// Source address
  uint8_t source_adress;
  /// Data length
  uint8_t len;
  /// Data array
  uint8_t data[8];
};

int8_t
HandyCAN_init (CAN_TypeDef* CANx, uint8_t local_addr, uint8_t CAN_Mode,
	       IRQn_Type FIFO0_IRQ, IRQn_Type FIFO1_IRQ);

int8_t
HandyCAN_transmit (uint8_t destination, uint8_t * data, uint8_t len);

int8_t
HandyCAN_recievePackage (uint8_t FIFONumber, struct HandyCAN_package* package);

int8_t
HandyCAN_remainingMailboxes (void);

int8_t
HandyCAN_isTransmitting (void);

uint64_t
HandyCAN_sentPackets (void);

uint64_t
HandyCAN_recievedPackets (void);

uint64_t
HandyCAN_failCount (void);

//For debug only
void
HandyCAN_dumpRxPackage (struct HandyCAN_package* package);
void
HandyCAN_dumpCanRxMessage (CanRxMsg* rx_msg);

#endif /* HANDYCAN_H_ */
