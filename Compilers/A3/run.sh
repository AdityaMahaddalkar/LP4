clear
yacc -d yacc_parser.y
lex lex.l
compile_output="$(gcc -w -std=c99 y.tab.c lex.yy.c -o parser)"
#./parser
#output=$(./parser)
#echo $compile_output

if [ -z "$compile_output" ]
then
	echo "Compiled Successfully"
	echo "No errors"
else
	echo "Error while compiling"
fi

./parser

date
