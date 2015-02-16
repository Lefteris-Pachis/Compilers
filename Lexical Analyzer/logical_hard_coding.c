unsigned gettoken3(void){
	while(1){
		if(feof(inputFile))
			return END_OF_FILE;
		char c = GetNextChar();

		if(isspace(c)){
			if(c == '\n') ++lineNo;
		}
		else if(c == '<'){
			if((c = GetNextChar()) == '=')
				return LE;
			else { Retract(c); return LT; }
		}
		else if(c == '>'){
			if((c = GetNextChar()) == '=')
				return GE;
			else { Retract(c); return GT; }
		}
		else if(c == '!'){
			if((c = GetNextChar()) == '=')
				return NE;
			else { Retract(c); return NOT; }
		}
		else if(c == '='){
			if((c = GetNextChar()) == '=')
				return EQ;
			else { Retract(c); return ASSIGN; }
		}
		else if(isalpha(c)){
			do{
				lexeme[curr++] = c;
				c = GetNextChar();
			} while(isalpha(c) || isdigit(c));
			Retract(c);
			return IDENTIFIER;
		}
		else
			return UNKNOWN_TOKEN;
	}
}