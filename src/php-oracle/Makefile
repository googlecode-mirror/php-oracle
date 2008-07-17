SRCS=./src/php-oracle/main.cpp ./src/php-oracle/AstContainer.cpp ./src/php-oracle/ProjectManager.cpp ./src/php-oracle/AstNode.cpp ./src/php-oracle/Utils.cpp ./src/php-oracle/Obfuscator.cpp ./src/php-oracle/Metric.cpp ./src/php-oracle/Translation.cpp ./src/php-oracle/Security.cpp
OBJS=$(patsubst %.cpp, %.o, $(SRCS))
EXEC=php-oracle
CC=g++-4.1
CFLAGS= -pedantic -O3 -g -std=c++98 -march=i386
LFLAGS=-lxml2
OFLAGS=-g
INC=-I/usr/include/libxml2/

%.o : %.cpp
	$(CC) -c $(CFLAGS) $(INC) $*.cpp -o $@

$(EXEC) : $(OBJS)
	$(CC) -o $(EXEC) $(OFLAGS) $(OBJS) $(LFLAGS)

.PHONY: clean
clean:
	@rm -f $(OBJS) $(EXEC)
