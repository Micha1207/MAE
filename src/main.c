/*
 * main.c
 * This is part of the Micha1207's CPU Architecture Emulator program (MAE).
 *
 * Main file.
 *
 * Author:  Micha1207
 * Project: MAE (https://github.com/Micha1207/MAE)
 * Date:    Aug 23, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "run-ins.h"

int main(int argc, char *argv[]){
  if (argc <= 1 || !strcmp(argv[1], "help") || !strcmp(argv[1], "--help")){
    fprintf(stderr, "Enter one of below commands; nothing to do now.\n");
    fprintf(stderr, "%sUSAGE: %s [COMMAND]%s\n\n COMMANDs:\n", COLOR_YELLOW,
	    argv[0], COLOR_RESET);
    fprintf(stderr, "  %srun [FILE]%s       - Execute [FILE] in MAE Assembly.\n",
	    COLOR_CYAN, COLOR_RESET);
    fprintf(stderr, "  %slist%s             - List of all MAE Assembly instructions.\n",
	    COLOR_CYAN, COLOR_RESET);
    fprintf(stderr, "  %sshell%s, %srepl%s      - Shell for MAE.\n",
	    COLOR_CYAN, COLOR_RESET, COLOR_CYAN, COLOR_RESET);
    fprintf(stderr, "  %shelp%s, %s--help%s   - List of all available instructions for MAE program.\n",
	    COLOR_CYAN, COLOR_RESET, COLOR_CYAN, COLOR_RESET);
    return -1;
  }
  
  if (!strcmp(argv[1], "run")){
    if (!argv[2]){
      fprintf(stderr, "%sE:%s No file to run. See help.%s\n", COLOR_RED,
	      COLOR_YELLOW, COLOR_RESET);
      return -2;
    }
    
    printf("%sRunning:%s '%s%s%s'...\n\n", COLOR_GREEN, COLOR_RESET,
	   COLOR_YELLOW, argv[2], COLOR_RESET);
    
    FILE *fp = fopen(argv[2], "r");
    
    char line[64];
    while (fgets(line, sizeof(line), fp)){
      int status = process_line(line);
      if (status != 0) break;
    }
    
    fclose(fp);
  } else if(!strcmp(argv[1], "repl") || !strcmp(argv[1], "shell")){
    printf("%s>%s ", COLOR_YELLOW, COLOR_RESET);
    
    char line[64];
    while (fgets(line, 64, stdin)){
      int status = process_line(line);
      if (status < 0){
	continue;
      } else if (status == 1) break;
      
      printf("%s>%s ", COLOR_YELLOW, COLOR_RESET);
    }
  } else if (!strcmp(argv[1], "list")){
    instr_list();
  } else
    fprintf(stderr, "%sE: %s%s%s: Not understood.%s\n", COLOR_RED,
	    COLOR_YELLOW, argv[1], COLOR_WHITE, COLOR_RESET);
  
  return 0;
}
