all:
	bison --yacc --defines --output=parser.c parser.y -v
	flex --outfile=scanner.c scanner.l
	gcc -g -o calc symtable.c actions_handler.c scanner.c parser.c quads.c
clean:
	rm -rf parser.c parser.h scanner.c calc parser.output