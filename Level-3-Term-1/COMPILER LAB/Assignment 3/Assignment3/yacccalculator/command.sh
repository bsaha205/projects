bison -d -y simplecalc.y
g++ -w -c -o yFile.o y.tab.c
flex simplecalc.lex
g++ -fpermissive -w -c -o lFile.o lex.yy.c
g++ -o myCompiler lFile.o yFile.o -lfl -ly
./myCompiler
