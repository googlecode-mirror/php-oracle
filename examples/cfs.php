<?php
	$b = 0;
	$c = "Salut";
	$len = strlen($c);
	for ($i=0; $i<$len;$i++) {
		echo $c[$i];
		if ($b) echo $i;
	}
	
	if (!$b) {
		echo $c;
	}
	
	do {
		echo $c;
	} while(!$b);
	
	echo $c;
		
?>
