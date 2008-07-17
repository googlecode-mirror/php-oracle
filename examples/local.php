<?php
	function func($a) {
		echo $a;
		$a = 1;
		return $a;
	}
	
	function f() { return 1; }
	
	// function ref(&$b) {$b=1;}

	$b = array();
	$c = 1;
	$b[$c] = 2;
	//$b[0] = 1;
	$b[0] = $c;
	$b[0] = $b[$c];
	//$b[0] = "Salut `` this is cool!";
	//$b[0] = "Salut `` this is cool! $c";
	//$b[0] = f();
	$b[0] = func($c);
	
	
	//$_GET['falut'] = '`plop` ' . $b[1];
	//$a = $_GET['falut'];
	//echo $a;
	//$b[0] = $a . "foo"; 
	//if (!empty($a)) {
	//	$a = $b[0];
	//}
	echo $a;
	$d = $a;
	
	//ref($a);
	//$a = func($a);
	//$a = f();
	
?>
