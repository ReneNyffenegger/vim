mingw32-make -f Make_ming.mak ARCH=x86-64
if errorlevel 1 (
   echo error
) else (
   start gvim -u NONE -U NONE --cmd "set guioptions+=M modeline nocompatible" -c "simalt ~x" tq84-debug.out
)

