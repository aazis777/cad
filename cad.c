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
 *   aazis777 (https://github.com/aazis777)
 */

#include "cad.h"

/* Minimal string comparison */
static int str_eq(const char *a, const char *b)
{
    int i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i])
            return FALSE;
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0') ? TRUE : FALSE;
}

/* Print contents of a file or stdin */
static void print_file(const char *filename, int show_ln, int show_fn)
{
    FILE *fp;
    int c;
    int ln_no = 1;
    int ln_start = TRUE;

    if (filename == NULL)
        fp = stdin;
    else {
        fp = fopen(filename, "r");
        if (!fp) {
            fprintf(stderr, "%s: cannot open %s\n", APP_NAME, filename);
            return;
        }
    }

    if (show_fn && filename != NULL)
        printf("%s\n\n", filename);

    while ((c = fgetc(fp)) != EOF) {
        if (ln_start && show_ln) {
            printf(GUTTER_FORMAT, ln_no++);
            ln_start = FALSE;
        }

        putchar(c);

        if (c == NL)
            ln_start = TRUE;
    }

    if (filename != NULL)
        fclose(fp);
}

/* Print usage info */
static void print_usage(void)
{
    printf(
        "%s — a cool cat clone\n"
        "Version: %s\n"
        "\nUsage:\n"
        "  %s [options] [files...]\n"
        "\nOptions:\n"
        "  -ln           Show line numbers\n"
        "  -fn           Show filename header\n"
        "  -v, --version Show version info\n"
        "  -h, --help    Show this help message\n"
        "\nExamples:\n"
        "  %s file.c\n"
        "  %s -ln file.c\n"
        "  %s -fn -ln main.c utils.c\n"
        "  %s -fn < file.txt\n"
        "\n",
        APP_NAME, APP_VERSION,
        APP_NAME,
        APP_NAME, APP_NAME, APP_NAME, APP_NAME
    );
}

/* ---------- Entry Point ---------- */
int main(int argc, char *argv[])
{
    int show_ln = FALSE;
    int show_fn = FALSE;
    int arg_idx = 1;

    if (argc == 1) {
        print_file(NULL, FALSE, FALSE);
        return 0;
    }

    /* Parse flags */
    for (; arg_idx < argc && argv[arg_idx][0] == '-'; arg_idx++) {
        if (str_eq(argv[arg_idx], "-ln"))
            show_ln = TRUE;
        else if (str_eq(argv[arg_idx], "-fn"))
            show_fn = TRUE;
        else if (str_eq(argv[arg_idx], "-show-all")) {
            show_ln = TRUE;
            show_fn = TRUE;
        } else if (str_eq(argv[arg_idx], "-h") || str_eq(argv[arg_idx], "--help")) {
            print_usage();
            return 0;
        } else if (str_eq(argv[arg_idx], "-v") || str_eq(argv[arg_idx], "--version")) {
            printf("%s version %s\n", APP_NAME, APP_VERSION);
            return 0;
        } else {
            fprintf(stderr, "%s: unknown option '%s'\n", APP_NAME, argv[arg_idx]);
            fprintf(stderr, "Try '%s -h' for help.\n", APP_NAME);
            return 1;
        }
    }

    /* If no filenames provided, read from stdin */
    if (arg_idx == argc) {
        if (show_fn)
            printf("(stdin)\n\n");
        print_file(NULL, show_ln, FALSE);
    } else {
        for (int i = arg_idx; i < argc; i++)
            print_file(argv[i], show_ln, show_fn);
    }

    return 0;
}
