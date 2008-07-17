<?php
	class Valid {
		function reb($string) {
			return $string;
		}
	}
	
	class Valid2 {
		function reb($string) {
			return $string + "2";
		}
	}	
	
	$valid = new Valid;
	$valid2 = new Valid2;
	
	$valid->reb("salut");
?>
