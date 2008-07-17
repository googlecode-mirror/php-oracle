<?php
$myvar = mysql_real_escape_string(htmlentities($_GET['foo'], ENT_QUOTES, 'UTF-8')); 
$mystr = "select * from `mybdd` where truc='$myvar'";
?>
