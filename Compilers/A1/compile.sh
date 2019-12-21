lex main.l
echo "Lex Compiled"
gcc lex.yy.c -o main
echo "GCC Compiled"
./main
echo "Successful run"
