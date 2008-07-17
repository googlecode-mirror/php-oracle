<?php
	class Foo {
		function foo() { echo "1"; }
	};
	function func(&$q) { $q = 1; }
	$a = $_GET['a'];
	$b = "1 and $a";
	$e = $_GET['e'];
	$e = "1";
	$f = "1 and $e";
	$d = $_COOKIE['d'];
	$c = Array();
	$c[0] = $_POST['c'];
	$a = str_replace($b, "1", "2");
	//$a = $b = $c = $d = 1;
	//$a = $b = $c[0] = $d;
	$d = Foo();
	$d = new Foo;
	Foo::foo();
	// affect $a
	func($a);
	//
	$c[0] = $a;
	$c[$b] = $a;
	
	echo $c[$b];
?>
