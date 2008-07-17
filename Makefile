all: ast oracle pre cpp
ast:
	make -j2 -s -f ./src/php-ast/Makefile
oracle:
	make -j2 -s -f ./src/php-oracle/Makefile
pre:
	make -j2 -s -f ./src/php-preproc/Makefile
cpp:
	make -j2 -s -f ./src/php-cpp/Makefile
clean-ast:
	make -s -f ./src/php-ast/Makefile clean
clean-oracle:
	make -s -f ./src/php-oracle/Makefile clean
clean-pre:
	make -s -f ./src/php-preproc/Makefile clean
clean-cpp:
	make -s -f ./src/php-cpp/Makefile clean
clean: clean-ast clean-oracle clean-pre clean-cpp
