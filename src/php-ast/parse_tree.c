#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "php_parse_tree.h"

int main(int argc, char *argv[])
{
	char filename[512] = "";
	extern FILE* yyin;
	extern char* _xml_output;
	extern int _error;

	if (argc < 2)
		return 0;
	strncpy(filename, argv[1], 512);
	yyin = fopen(filename, "r");
	if (!yyin) {
		return 0;
	}
	yyparse();
	fclose(yyin);
	if(_error){
		return 0;
	}
	char outfname[1024];
	if (argc == 3) {
		strncpy(outfname, argv[2], 1024);
	}
	else {
		strncpy(outfname, filename, 512);
		strcat(outfname, ".xml");
	}
	FILE *temp = (FILE *)NULL;
	if ((temp = fopen(outfname, "w")))
	{
		fprintf(temp, "%s",_xml_output);
	}
	fclose(temp);
	return 0;
}
