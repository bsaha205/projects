yacc -d test.y
lex test.l
cc lex.yy.c y.tab.c -o test

#bison -d -y test.y
#g++ -w -c -o yaccDemo.o y.tab.c
#flex test.l
#g++ -fpermissive -w -c -o lexDemo.o lex.yy.c
#g++ -o myCompiler lexDemo.o yaccDemo.o -ll -ly
#./myCompiler
