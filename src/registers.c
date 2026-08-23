/*
 * registers.c
 * This is part of the Micha1207's CPU Architecture Emulator program (MAE).
 *
 * Register definitions and helper functions.
 *
 * Author:  Micha1207
 * Project: MAE (https://github.com/Micha1207/MAE)
 * Date:    Aug 21, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "registers.h"

uint8_t A = 0;
uint8_t X = 0;
uint8_t Y = 0;

uint8_t get_reg(char *reg){
  *reg = tolower(*reg);
  if (!strcmp(reg, "a")) return A;
  if (!strcmp(reg, "x")) return X;
  if (!strcmp(reg, "y")) return Y;
  return 0;
}

uint8_t set_reg(char *reg, uint8_t val){
  *reg = tolower(*reg);
  if (!strcmp(reg, "a")) A = val;
  if (!strcmp(reg, "x")) X = val;
  if (!strcmp(reg, "y")) Y = val;
  return 0;
}
