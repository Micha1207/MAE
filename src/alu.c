/*
 * alu.c
 * This is part of the Micha1207's CPU Architecture Emulator program (MAE).
 *
 * Simple ALU.
 *
 * Author:  Micha1207
 * Project: MAE (https://github.com/Micha1207/MAE)
 * Date:    Aug 21, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdint.h>
#include <stdbool.h>

#include "alu.h"

bool op_not_bit(bool a){         return !a;     }
bool op_or_bit(bool a, bool b){  return a || b; }
bool op_xor_bit(bool a, bool b){ return a != b; }
bool op_and_bit(bool a, bool b){ return a && b; }

void op_add_bit(bool a, bool b, bool c_in, bool *sum, bool *c_out){
  *sum   = op_xor_bit(op_xor_bit(a, b), c_in);
  *c_out = op_or_bit(op_and_bit(a, b), (op_and_bit(c_in, op_xor_bit(a, b))));
}

uint8_t op_not(uint8_t a){
  uint8_t res = 0;

  for (int i = 0; i < 8; i++){
    bool bit_a = (a >> i) & 1;
    bool bit_s = 0;

    bit_s = op_not_bit(bit_a);

    res |= ((uint8_t)bit_s << i);
  }

  return res; 
}

uint8_t op_or(uint8_t a, uint8_t b){
  uint8_t res = 0;

  for (int i = 0; i < 8; i++){
    bool bit_a = (a >> i) & 1;
    bool bit_b = (b >> i) & 1;
    bool bit_s = 0;

    bit_s = op_or_bit(bit_a, bit_b);

    res |= ((uint8_t)bit_s << i);
  }

  return res; 
}

uint8_t op_xor(uint8_t a, uint8_t b){
  uint8_t res = 0;

  for (int i = 0; i < 8; i++){
    bool bit_a = (a >> i) & 1;
    bool bit_b = (b >> i) & 1;
    bool bit_s = 0;

    bit_s = op_xor_bit(bit_a, bit_b);

    res |= ((uint8_t)bit_s << i);
  }

  return res; 
}

uint8_t op_and(uint8_t a, uint8_t b){
  uint8_t res = 0;

  for (int i = 0; i < 8; i++){
    bool bit_a = (a >> i) & 1;
    bool bit_b = (b >> i) & 1;
    bool bit_s = 0;

    bit_s = op_and_bit(bit_a, bit_b);

    res |= ((uint8_t)bit_s << i);
  }

  return res; 
}

uint8_t op_add(uint8_t a, uint8_t b, uint8_t c_in){
  bool c_cur = c_in;
  uint8_t res = 0;

  for (int i = 0; i < 8; i++){
    bool bit_a = (a >> i) & 1;
    bool bit_b = (b >> i) & 1;
    bool bit_s = 0;

    op_add_bit(bit_a, bit_b, c_cur, &bit_s, &c_cur);

    res |= ((uint8_t)bit_s << i);
  }

  return res; 
}

uint8_t op_sub(uint8_t a, uint8_t b){
  uint8_t b_not = op_not(b);
  return op_add(a, b_not, 1);
}

uint8_t op_mul(uint8_t a, uint8_t b){
  uint8_t res = 0;

  for (int i = 1; i <= b; i++){
    res = op_add(res, a, 0);
  }
  
  return res;
}

uint8_t op_div(uint8_t a, uint8_t b){
  int *res = 0;

  if (b == 0) return 0;
  while (a >= b){
    a = op_sub(a, b);
    (*res)++;
  }

  return *res;
}

uint8_t op_shl(uint8_t a, uint8_t count){
  return a << count;
}

uint8_t op_shr(uint8_t a, uint8_t count){
  return a >> count;
}

uint8_t op_rol(uint8_t a, uint8_t count){
  uint8_t shdl = 0; shdl = op_shl(a, count);
  uint8_t shdr = op_shr(shdl, 8 - count);
  return op_or(shdl, shdr);
}

uint8_t op_ror(uint8_t a, uint8_t count){
  uint8_t shdr = op_shr(a, count);
  uint8_t shdl = 0; shdl = op_shr(shdl, 8 - count);
  return op_or(shdr, shdl);
}

uint8_t alu(uint8_t op, uint8_t a, uint8_t b){
  switch (op){
  case 0:
    return op_not(a);
    break;
  case 1:
    return op_or(a, b);
    break;
  case 2:
    return op_xor(a, b);
    break;
  case 3:
    return op_and(a, b);
    break;
  case 4:
    return op_add(a, b, 0);
    break;
  case 5:
    return op_sub(a, b);
    break;
  case 6:
    return op_mul(a, b);
    break;
  case 7:
    return op_div(a, b);
    break;
  case 8:
    return op_shl(a, b);
    break;
  case 9:
    return op_shr(a, b);
    break;
  case 10:
    return op_rol(a, b);
    break;
  case 11:
    return op_ror(a, b);
    break;
  }

  return 0;
}
