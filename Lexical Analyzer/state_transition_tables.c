typedef int (*StateFunc) (char c);

#define MAX_STATE	6
#define TOKEN_SHIFT	(MAX_STATE + 1)
#define TOKEN(t)	TOKEN_SHIFT+(t)
#define STATE(s)	s
#define istoken(s)	((s) > MAX_STATE)

int sf0 (char c){
	if(c == '<')	return STATE(1);
	if(c == '!')	return STATE(2);
	if(c == '=')	return STATE(3);
	if(c == '>')	return STATE(4);
	if(isalpha(c))	return STATE(5);
	if(isspace(c))
		{ CheckLine(c); return STATE(6); }
	return STATE(-1);
}

int sf1(char c){
	if(c == '=') { ExtendLexeme(c); return TOKEN(LE); }
	Retract(c); return TOKEN(LT);
}

int sf2(char c){
	if(c == '=') { ExtendLexeme(c); return TOKEN(NE); }
	Retract(c); return TOKEN(NOT);
}

int sf3(char c);
int sf4(char c);

int sf5(char c){
	if(isalpha(c) || isdigit(c))
		return STATE(5);
	Retract(c);
	return TOKEN(IDENTIFIER);
}

int sf6(char c){
	if(isspace(c))
		{ CheckLine(c); return STATE(6); }
	Retract(c); return STATE(0);
}

StateFunc stateFuncs[MAX_STATE + 1]={
	&sf0, &sf1, &sf2, &sf3, &sf4, &sf5, &sf6
};

unsigned gettoken2(void){
	state = 0;
	ResetLexime();
	while(1){
		if(feof(inputFile))
			return END_OF_FILE;

		char c = GetNextChar();

		state = (*stateFuncs[state])(c);

		if(state == -1)
			return UNKNOWN_TOKEN;
		else if(istoken(state))
			return state - TOKEN_SHIFT;
		else
			ExtendLexeme(c);
	}
}