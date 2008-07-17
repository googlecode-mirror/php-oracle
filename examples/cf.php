<?php
	$b = 0;
	$c = "Salut";
	$len = strlen($c);

	function fct($a) {
		return $a . "_1\n";
	}
	
	class T {
		function foo() {
			echo "test\n";
		}
	}
	echo fct(0);
	echo T::foo();
	
	echo $_GET['a'];
	die("foo");
	$b = str_replace($c, 'F', 'a');
	
?>
