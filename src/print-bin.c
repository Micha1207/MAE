/*
 * print-bin.c
 * This is part of the Micha1207's CPU Architecture Emulator program (MAE).
 *
 * Print uint8_t as 8-bit binary number.
 *
 * Author:  Micha1207
 * Project: MAE (https://github.com/Micha1207/MAE)
 * Date:    Aug 21, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <stdint.h>

#include "print-bin.h"

int print_bin8(uint8_t number){
  for (int i = 7; i >= 0; i--){
    printf((number & (1 << i)) ? "1" : "0");
  }
  printf("\n");
  
  return 0;
}
