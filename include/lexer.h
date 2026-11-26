#ifndef lexer

typedef enum
{
	TOKEN_INT,
	TOKEN_RETURN,
	TOKEN_VOID,
	TOKEN_IDENTIFIER,	// main
	TOKEN_NUMBER,		// '42'
	TOKEN_LPAREN,		// '('
	TOKEN_RPAREN,		// ')'
	TOKEN_LBRACE,		// '{'
	TOKEN_RBRACE,		// '}'
	TOKEN_SEMICOLON,
	TOKEN_EOF
} TokenType;

typedef struct
{
	TokenType type;
	char* lexeme;
} Token;

#endif
