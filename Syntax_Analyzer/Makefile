all:
	flex --outfile=al.c lex.l
	gcc al.c -o al
bonus:
	gcc scanner.c -o scanner
clean:
	rm -rf al.c al
	rm -rf scanner