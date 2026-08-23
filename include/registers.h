/*
 * registers.h
 * This is part of the Micha1207's CPU Architecture Emulator program (MAE).
 *
 * Header file for src/registers.c
 *
 * Author:  Micha1207
 * Project: MAE (https://github.com/Micha1207/MAE)
 * Date:    Aug 21, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>
#include <string.h>
#include <ctype.h>

extern uint8_t A;
extern uint8_t X;
extern uint8_t Y;

uint8_t get_reg(char *reg);
uint8_t set_reg(char *reg, uint8_t val);

#endif
