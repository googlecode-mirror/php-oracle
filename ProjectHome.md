# PHP Source Code Security Framework #

PHP-AST/ORACLE is a C++ framework which allows user to perform lots of different operations on a source code. The tool has been developed mainly for:

  * Implementing source code (security) metrics]
  * Gathering information on the source code (data-flow variable paths, etc.) by building the model
  * Creating personal source code obfuscations (currently only pattern based is supported, no data-type)
  * Source to source converter (e.g. PHP to C++ code for static analysis purposes)
  * Checking for security vulnerabilities: PHP Security Oracle]


## How it works ##
The source code repository is divided in 2 parts:
  * php-ast is the converter from PHP to XML ([yaxx](http://code.google.com/p/yaxx/))
  * php-oracle is the actual engine

php-oracle get a XML file as input which is the output of php-ast. In the SVN there are some python scripts I used in order to combine the 2 tools (they may be outdated i.e. doesn't work with the current php-oracle).


## How I think you could use php-oracle ##
I do not attend to make a clean build with an executable etc. I just provide source code. I decided to give only the source code because I don't want to spend too much time on creating a clean software, it's only research oriented stuff. Furthermore, there is not much documentation in the source code (advantages of being alone to develop such a tool) and then, only really interested people will download this! I can then help them if they have some question about how it works etc.


## Building ##
You need to have libxml2(-dev) and that's all.

To build the php-ast, you need to:

```
   make ast
```

and to build the php-oracle:

```
   make oracle
```


## Bugs ##
There are plenty of bugs! I'm sure of that... I just release it (under my name) because I think people may be interested in the Obfuscation pattern engine or, Source to Source converter or the metrics (there is a first implementation of a source code security metric I am developing right now).

## Contact ##
Romain Gaucher -- http://rgaucher.info