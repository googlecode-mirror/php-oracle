<?php
	function validate($__str) {
		// losy SQL Injection protection
		return str_replace("'", "\'", $__str);
	}
	
	$username = "John Doe";
	$pass = False;
	if (isset($_POST['password'])) {
		$pass = validate($_POST['password']);
	}
	if (isset($_POST['uname'])) {
		$username = $_POST['uname'];
	}
	$id = isset($_GET['id']) ? (int)($_GET['id']) : -1;	



	$__START_OBF_HERE;
		
	echo "<html><body>";
	echo "<h1>Hello $username</h1>";
	echo "You password is: " . $pass. "<br />";
	echo "In case you didn't remember... your name is:" . $username;
	echo $id == -1 ? "plop" : "none";
	
	$__END_OBF_HERE;


	if (False) {
		echo "hegh/";
	}
?>
