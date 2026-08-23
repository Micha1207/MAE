/*
 * alu.h
 * This is part of the Micha1207's CPU Architecture Emulator program (MAE).
 *
 * Header file for src/alu.c
 *
 * Author:  Micha1207
 * Project: MAE (https://github.com/Micha1207/MAE)
 * Date:    Aug 21, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef ALU_H
#define ALU_H

#include <stdint.h>
#include <stdbool.h>

#include "registers.h"

bool op_not_bit(bool a);
bool op_or_bit(bool a, bool b);
bool op_xor_bit(bool a, bool b);
bool op_and_bit(bool a, bool b);
void op_add_bit(bool a, bool b, bool c_in, bool *sum, bool *c_out);
uint8_t op_not(uint8_t a);
uint8_t op_or(uint8_t a, uint8_t b);
uint8_t op_xor(uint8_t a, uint8_t b);
uint8_t op_and(uint8_t a, uint8_t b);
uint8_t op_add(uint8_t a, uint8_t b, uint8_t c_in);
uint8_t op_sub(uint8_t a, uint8_t b);
uint8_t op_mul(uint8_t a, uint8_t b);
uint8_t op_div(uint8_t a, uint8_t b);
uint8_t op_shl(uint8_t a, uint8_t count);
uint8_t op_shr(uint8_t a, uint8_t count);
uint8_t op_rol(uint8_t a, uint8_t count);
uint8_t op_ror(uint8_t a, uint8_t count);
uint8_t alu(uint8_t op, uint8_t a, uint8_t b);


#endif
