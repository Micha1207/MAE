/*
 * run-ins.h
 * This is part of the Micha1207's CPU Architecture Emulator program (MAE).
 *
 * Header file for src/run-ins.c
 *
 * Author:  Micha1207
 * Project: MAE (https://github.com/Micha1207/MAE)
 * Date:    Aug 11, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef RUN_INS_H
#define RUN_INS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "alu.h"
#include "registers.h"
#include "print-bin.h"
#include "colors.h"

int exec_cmd(char *arg[8], int idx);
int process_line(char line[64]);
uint8_t get_val(char *input);
void print_uerr(char *cmd);
void instr_list();

#endif
