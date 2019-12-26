/* vi:set ts=8 sts=4 sw=4 noet:
 *
 * VIM - Vi IMproved		by Bram Moolenaar
 *				GUI support by Robert Webb
 *
 * Do ":help uganda"  in Vim to read copying and usage conditions.
 * Do ":help credits" in Vim to see a list of people who contributed.
 * See README.txt for an overview of the Vim source code.
 */
/*
 * Windows GUI: main program (EXE) entry point:
 *
 * Ron Aaron <ronaharon@yahoo.com> wrote this and the (now deleted) DLL support
 * code.
 */
#include "vim.h"

#define TQ84_DEBUG_ENABLED
#define TQ84_DEBUG_TO_FILE
#include "tq84-c-debug/tq84_debug.h"

// cproto doesn't create a prototype for VimMain()
#ifdef VIMDLL
__declspec(dllimport)
#endif
int VimMain(int argc, char **argv);
#ifndef VIMDLL
void SaveInst(HINSTANCE hInst);
#endif

#ifndef PROTO
# ifdef FEAT_GUI
    int WINAPI
wWinMain(
    HINSTANCE	hInstance,
    HINSTANCE	hPrevInst UNUSED,
    LPWSTR	lpszCmdLine UNUSED,
    int		nCmdShow UNUSED)
# else
    int
wmain(int argc UNUSED, wchar_t **argv UNUSED)
# endif
{
  TQ84_DEBUG_OPEN("tq84-debug.out", "w");
  tq84_debug_out("vim: foldmarker=<<<,>>> foldmethod=marker buftype=nofile\n");
  TQ84_DEBUG_INDENT_T("Entered wWinMain");
# ifndef VIMDLL
#  ifdef FEAT_GUI
    SaveInst(hInstance);
#  else
    SaveInst(GetModuleHandleW(NULL));
#  endif
# endif
    VimMain(0, NULL);

    return 0;
}
#endif
