<?php
	// !!! Http Response Splitting flaw
	if ($_GET['redir_tp']) {
		header("Location: ?dir=" . $_GET['redir_tp']);
		// !!! Need of exit();
	}
	else if ($_GET['redir_fp']) {
		header("Location: ?dir=" . escapeshellcmd($_GET['redir_tp']));
		exit();
	}

	// !!! No SQL Injection flaw -- declaration
	// !!! CWE Flaw: Password in the source code
	$db = mysql_connect("localhost", "testuser","testpass");
	if (!$db) {
		die("Could not connect to bdd: " . mysql_error());
	}
	mysql_select("foo");

	// !!! SQL Injection
	$r1 = mysql_query("SELECT * FROM bar WHERE barianStr = '". $_GET['sql_tp1'] ."' "); /* true */
	$r2 = mysql_query("SELECT * FROM bar WHERE barianStr = '". (string)$_GET['sql_tp2'] . "' "); /* true */
	$r2 = mysql_query("SELECT * FROM bar WHERE barianInt = ". (int)$_GET['sql_fp1']); /* false */
	$r3 = mysql_query("SELECT * FROM bar WHERE barianStr = '". mysql_real_escape_string($_GET['sql_fp2']) . "' "); /* false */

	// !!! Insert JS string into SQL db - Persistant XSS if no output validation
	$r4 = mysql_query("INSERT INTO bar VALUES(NULL, '" . mysql_real_escape_string($_GET['xss_tp1']) . "') " ); /* true */
	$r5 = mysql_query("INSERT INTO bar VALUES(NULL, '" . mysql_real_escape_string(htmlentities($_GET['xss_fp1'], ENT_QUOTES, 'UTF-8')) . "')" ); /* false */

	// !!! XSS
	echo "HelloStr: ". $_GET['xss_tp2'] . "<br />"; /* true */
	echo "HelloInt: ". (int)$_GET['xss_fp2'] . "<br />"; /* false */
	echo "HelloStr: ". htmlentities($_GET['xss_fp3'], ENT_QUOTES, 'UTF-8') . "<br />"; /* true */

	// !!! File Injection
	include ($_GET['file_tp1']); /* true */

	if (file_exists($_GET['file_tp2']))
		include ($_GET['file_tp2']); /* true */

	$inc = $_GET['file_fp1'];
	if (file_exists($inc) && ereg("^[^./][^/]*$", $inc))
		include ($inc); /* false */

	// !!! Path Manipulation
	$fp = fopen($_GET['path_tp1'] . '.ext', 'rb'); /* true */
	$content = file_get_contents($fp); echo $content; fclose($fp);

	$fp = fopen(escapeshellcmd($_GET['path_tp2']) . '.ext', 'rb'); /* true */
	$content = file_get_contents($fp); echo $content; fclose($fp);

	$name = escapeshellcmd($_GET['path_fp1']);
	if (ereg("^[^./][^/]*$", $name)) {
		$fp = fopen($name . '.ext', 'rb'); /* false */
		$content = file_get_contents($fp); echo $content; fclose($fp);
	}

	// !!! OS Command Injection
	system($_GET['cmd_tp1']); /* true */
	system(htmlentities($_GET['cmd_tp2'])); /* true */
	system(escapeshellcmd($_GET['cmd_fp1'])); /* false */
?>