/*
 * run-ins.c
 * This is part of the Micha1207's CPU Architecture Emulator program (MAE).
 *
 * Functions responsible for running instructions.
 *
 * Author:  Micha1207
 * Project: MAE (https://github.com/Micha1207/MAE)
 * Date:    Aug 21, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "run-ins.h"

#include "alu.h"
#include "registers.h"
#include "print-bin.h"
#include "colors.h"

int exec_cmd(char *arg[8], int idx){ 
  if (!strcmp(arg[0], "ld")){
    if (arg[1] && arg[2]) set_reg(arg[1], get_val(arg[2]));
    else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "not")){
    if (arg[1]){
      uint8_t val = get_reg(arg[2]);
      set_reg(arg[1], alu(0, val, 0));
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "or")){
    if (arg[1] && arg[2]){
      uint8_t val_a = get_reg(arg[1]);
      uint8_t val_b = get_val(arg[2]);
      set_reg(arg[1], alu(1, val_a, val_b));
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "xor")){
    if (arg[1] && arg[2]){
      uint8_t val_a = get_reg(arg[1]);
      uint8_t val_b = get_val(arg[2]);
      set_reg(arg[1], alu(2, val_a, val_b));
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "and")){
    if (arg[1] && arg[2]){
      uint8_t val_a = get_reg(arg[1]);
      uint8_t val_b = get_val(arg[2]);
      set_reg(arg[1], alu(3, val_a, val_b));
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "add")){
    if (arg[1] && arg[2]){
      uint8_t val_a = get_reg(arg[1]);
      uint8_t val_b = get_val(arg[2]);
      set_reg(arg[1], alu(4, val_a, val_b));
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "sub")){
    if (arg[1] && arg[2]){
      uint8_t val_a = get_reg(arg[1]);
      uint8_t val_b = get_val(arg[2]);
      set_reg(arg[1], alu(5, val_a, val_b));
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "mul")){
    if (arg[1] && arg[2]){
      uint8_t val_a = get_reg(arg[1]);
      uint8_t val_b = get_val(arg[2]);
      set_reg(arg[1], alu(6, val_a, val_b));
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "div")){
    if (arg[1] && arg[2]){
      uint8_t val_a = get_reg(arg[1]);
      uint8_t val_b = get_val(arg[2]);
      set_reg(arg[1], alu(7, val_a, val_b));
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "shl")){
    if (arg[1] && arg[2]){
      uint8_t val_a = get_reg(arg[1]);
      uint8_t val_b = get_val(arg[2]);
      set_reg(arg[1], alu(8, val_a, val_b));
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "shr")){
    if (arg[1] && arg[2]){
      uint8_t val_a = get_reg(arg[1]);
      uint8_t val_b = get_val(arg[2]);
      set_reg(arg[1], alu(9, val_a, val_b));
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "rol")){
    if (arg[1] && arg[2]){
      uint8_t val_a = get_reg(arg[1]);
      uint8_t val_b = get_val(arg[2]);
      set_reg(arg[1], alu(10, val_a, val_b));
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "ror")){
    if (arg[1] && arg[2]){
      uint8_t val_a = get_reg(arg[1]);
      uint8_t val_b = get_val(arg[2]);
      set_reg(arg[1], alu(11, val_a, val_b));
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "prtr")){
    if (arg[1] && arg[2]){
      uint8_t val = get_reg(arg[1]);
      if (!strcmp(arg[2], "d")) printf("%d\n", val);
      else if (!strcmp(arg[2], "b")) { printf("0b");
	print_bin8(val); }
      else if (!strcmp(arg[2], "x")) printf("0x%X\n", val);
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "prtt")){
    if (arg[1]){
      for (int i = 1; i < idx; i++){
	printf("%s ", arg[i]);
      }
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "prttn")
	     || !strcmp(arg[0], "prtn")){
    if (arg[1]){
      for (int i = 1; i < idx; i++){
	printf("%s ", arg[i]);
      }
      printf("\n");
    } else {
      print_uerr(arg[0]);
      return -2;
    }
  } else if (!strcmp(arg[0], "list")){
      instr_list();
  } else {
    fprintf(stderr, "%sE: %s%s%s: Not understood.%s\n", COLOR_RED, COLOR_YELLOW,
	    arg[0], COLOR_WHITE, COLOR_RESET);
  }

  return 0;
}

int process_line(char line[64]){
  char *arg[8];
  int idx = 0;
  char *token = strtok(line, " \",\n\t\r");
  while (token != NULL && idx < 7){
    arg[idx] = token;
    idx++;
    token = strtok(NULL, " \",\n\t\r");
  }
  arg[idx] = NULL;
    
  if (arg[0] == NULL || arg[0][0] == ';')
    return 0;
  
  for (int i = 0; arg[0][i] != '\0'; i++){
    arg[0][i] = (char)tolower((unsigned char)arg[0][i]);
  }

  if (!strcmp(arg[0], "exit")) return 1;
  int ins_estatus = exec_cmd(arg, idx);
  if (ins_estatus != 0) return ins_estatus;
  return 0;
}

uint8_t get_val(char *input){
  if (input == NULL) return 0;
  
  if (input[0] >= '0' && input[0] <= '9'){
    return (uint8_t)strtol(input, NULL, 0);
  }
  
  return get_reg(input);
}

void print_uerr(char *cmd){
  fprintf(stderr,
	  "%sE:%s Incorrect usage for '%s'. See 'list' command.\n",
	  COLOR_RED, COLOR_RESET, cmd);
}

void instr_list(){
  fprintf(stderr, "%sList of available instructions.%s\n", COLOR_YELLOW,
	  COLOR_RESET);
  fprintf(stderr, "\n%s Math (ALU):%s\n", COLOR_RED, COLOR_RESET);
  fprintf(stderr, "%s  not [A] | or [A], [B] | xor [A], [B] | and [A], [B] | add [A], [B] \n",
	  COLOR_GREEN);
  fprintf(stderr, "  sub [A], [B] | mul [A], [B] | div [A], [B] | shl [A], [count] \n");
  fprintf(stderr, "  shr [A], [count] | rol [A], [count] | ror [A], [count]%s\n",
	  COLOR_RESET);
  fprintf(stderr, "\n%s Misc%s\n", COLOR_RED, COLOR_RESET);
  fprintf(stderr, "%s  ld [A], [num] | prtr [REG], [FMT: d|b|x] | prtt [\"TEXT\"] | prttn [\"TEXT\"] (adds '\\n')\n",
	  COLOR_GREEN);
  fprintf(stderr, "  ; comment%s\n", COLOR_RESET);
}
