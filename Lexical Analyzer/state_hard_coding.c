#define UNKNOWN_TOKEN 	-1
#define END_OF_FILE		0
#define LE				1
#define LT				2
#define NE				3
#define NOT				4
#define IDENTIFIER		5

int state = 0;
unsigned gettoken(void){
	state = 0;
	ResetLexeme();
	while(1){
		if(state == 1)
			return UNKNOWN_TOKEN;
		if(feof(inputFile))
			return END_OF_FILE;
		char c = GetNextChar();

		switch(state){
			case 0:
				if(c == '<') state = 1; else
				if(c == '!') state = 4; else
				if(c == '=') state = 7; else
				if(c == '>') state = 10; else
				if(isalpha(c)) state = 13; else
				if(isspace(c))
					{ CheckLine(c); state = 15; continue; }
				else
					{ state = -1; continue; }
				break;
			case 1:
				if(c == '=') { ExtendLexeme(c); return LE; }
				Rectract(c); return LT;
			case 4:
				if(c == '=') { ExtendLexeme(c); return NE; }
				Rectract(c); return NOT;
			case 15:
				if(isspace(c))
					{ CheckLine(c); state = 15; }
				else
					{ Rectract(c); state = 0; }
				continue;
			case 13:
				if(isalpha(c) || isdigit(c)) state = 13;
				else { Rectract(c); return IDENTIFIER; }
				break;

			default: assert(0); /*Giwrgadakhs*/
		}
		ExtendLexeme(c);
	}
}