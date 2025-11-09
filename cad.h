#ifndef CAD_H
#define CAD_H

/*
 * cad — a recreational-purposes edgy, yet cool cat command clone for UNIX/LINUX systems.
 *
 * This is a handmade reimplementation of the classic `cat` command,
 * built just for fun and learning. It’s small, and portable.
 *
 * Features:
 *   - Show line numbers with   : -ln
 *   - Show filename header with: -fn
 *   - Combine them for a clean, readable output.
 *
 * Example:
 *   ./cad file.c
 *   ./cad -ln file.c
 *   ./cad -fn -ln main.c
 *
 * Build:
 *   gcc -O2 -Wall -Wextra -std=c99 -o cad cad.c
 *
 * Author:
 *   aazis7 (https://github.com/aazis777)
 */

#include <stdio.h>

/* ---------- App Info ---------- */
#ifndef APP_NAME
#define APP_NAME    "cad"
#endif

#ifndef APP_VERSION
#define APP_VERSION "1.0.0"
#endif

#ifndef APP_BUILD_DATE
#define APP_BUILD_DATE __DATE__
#endif

#ifndef APP_BUILD_TIME
#define APP_BUILD_TIME __TIME__
#endif

/* ---------- Macros ---------- */
#define TRUE  1
#define FALSE 0
#define NL '\n'

#define GUTTER_WIDTH 4
#define GUTTER_FORMAT "%4d | "

/* ---------- Function Prototypes ---------- */
static int str_eq(const char *a, const char* b);
static void print_file(const char *filename, int show_ln, int show_fn);
static void print_usage(void);

#endif // CAD_H
