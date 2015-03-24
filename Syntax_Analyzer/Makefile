all:
	bison --yacc --defines --output=parser.c parser.y -v
	flex --outfile=scanner.c scanner.l
	gcc -o calc actions_handler.c scanner.c parser.c
clean:
	rm -rf parser.c scanner.c calc parser.output