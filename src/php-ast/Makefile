SRCS=./src/php-ast/php_lexer.c ./src/php-ast/php_parser.c ./src/php-ast/parse_tree.c
OBJS=$(patsubst %.c, %.o, $(SRCS))
EXEC=php-ast
CC=gcc
CFLAGS=-pedantic -O3 -std=c99 -g

%.o : %.c
	$(CC) -c $(CFLAGS) $*.c -o $@

$(EXEC) : $(OBJS)
	@$(CC) -o $(EXEC) $(OBJS) -g

.PHONY: clean
clean:
	@rm -f $(OBJS) $(EXEC)
