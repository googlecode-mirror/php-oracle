
<?php
	class Valid {
		function reb($string) {
			return $string;
		}
	};
	$valid = new Valid;

	$vars = "default";
	if (isset($_GET['vars']))
	{
		$vars = $_GET['vars'];
	}
	$b = $_GET['vars'];
	echo $_GET['vars'];


	$vars2 = Array();
	$c = 0;
	$a = $c;
	
	$vars2[0] = htmlentities($vars, ENT_QUOTES, 'UTF-8');
	$vars2[1] = $valid->reb($vars);
	
	echo $vars2[0];
	system($vars);

	for ($i=0;$i<5;$i++)
		echo $vars2[$i];
?>
