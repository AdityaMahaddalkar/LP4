lex lex.l
yacc -d yacc_parser.y
gcc y.tab.c lex.yy.c -o parser
output="$(./parser)"
echo $output

#if [ output -eq 0 ]
#then
#	echo "Compiled Successfully"
#	echo "No errors"
#fi

date
