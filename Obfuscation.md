# Source code obfuscations #
An obfuscation is a transformation of a given source code with a unique constrain: the execution of the source code must produce the same output.
I used to play with source code analyzers tools and this in order to know how they performed with different code complexities. For this purpose, I created a pattern based obfuscator.

You can see some pattern here: ./obfs
Only the control flow obfuscations patterns are implemented for now, will do the data-flow soon as it's easy also. The data-type obfuscation may be trickier.

## Using/Creating a pattern ##
A pattern is a PHP source code using special names for function or obfuscation variables, here is an example:
```
<?php
	for ($rand_name = 0;$rand_name < 1; $rand_name++)
	{
		// here
		$enter_the_new_statement;
	}
?>
```
The obfuscation is to include the previous statements in this 1-loop. $rand\_name is the name of variables ($rand\_name, $rand\_name\_1, $rand\_name\_2, ...) and $enter\_the\_new\_statement is the place of the old statement in the new source code.

A more complicated example with a function and class definition:
```
<?php
	class rand_class_name
	{
		function rand_func_name_2($rand_name_1) 
		{
			return $rand_name_1 + 1;
		}
	}

	function rand_func_name_1($rand_name_2) 
	{
		return $rand_name_2 + 1;
	}
	
	if (rand_func_name_1(0) > 0 && rand_class_name::rand_func_name_2(0)) {
		$enter_the_new_statement;
	}
?>
```

Once you created the pattern, you can use php-ast to convert it into a XML Ast file, to be able to load it with the php-oracle. You can combine different obfuscations (order is kept) and the basic command is:
```
  php-oracle --obf:control-flow originalCode.xml outputCode.xml obfuscation-pattern_1.xml obfuscation-pattern_2.xml ...
```

## Contact ##
Romain Gaucher -- http://rgaucher.info