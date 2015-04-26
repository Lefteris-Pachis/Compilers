all:
	bison --yacc --defines --output=parser.c parser.y -v
	flex --outfile=scanner.c scanner.l
	gcc -g -o calc actions_handler.c symtable.c quads.c scanner.c parser.c 
clean:
	rm -rf parser.c parser.h scanner.c calc parser.output icode.txt