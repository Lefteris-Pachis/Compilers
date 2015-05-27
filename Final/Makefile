all:
	bison --yacc --defines --output=parser.c parser.y -v
	flex --outfile=scanner.c scanner.l
	gcc -g -o calc actions_handler.c symtable.c quads.c scanner.c parser.c target_code.c generate.c avm.c dispatcher.c exec_relop.c exec_tables.c exec_arithm.c exec_func.c exec_assign.c
clean:
	rm -rf parser.c parser.h scanner.c calc parser.output icode.txt instructions.txt const.txt tcode.bin