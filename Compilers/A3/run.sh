clear
yacc -d yacc_parser.y
sleep 1
lex lex.l
sleep 1
gcc y.tab.c lex.yy.c -o parser
./parser
#output="$(./parser)"
#echo $output

#if [ -z $output ]
#then
#	echo "Compiled Successfully"
#	echo "No errors"
#fi

date
