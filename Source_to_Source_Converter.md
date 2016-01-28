# Source-to-Source converter #
As I said in other wiki pages, I created this framework in order to ''play'' with static analysis an really dive into the tool limitations. In order to use  more tools (especially commercials), I made a AST to PHP/C++ converter.

I think the more important is to see the syntactic correct output of that tool:
```
#include <iostream>
#include "libphp.h"

PhpObject _POST;
PhpObject db;
PhpObject i;
PhpObject q;
PhpObject result;
PhpObject row;

class Meeting{
	void foo(  ) {
	echo("1" );}
	 Meeting() {
	}
	 ~Meeting() {
	}
	 Meeting(const Meeting& ____c) {
	}
}
;
PhpObject print_db( PhpObject& loc_result ) {
	if ( ! loc_result ) return - 1 ;
	 print("<table><thead><td>ID</td><td>Name</td><td>Author</td></thead><tbody>" );
	 while ( row = mysql_fetch_array ( loc_result , MYSQL_ASSOC ) ) {
	 echo("<tr><td>"  + row [ "BookID" ]  + "</td><td>"  + row [ "Name" ]  + "</td><td>"  + row [ "Author" ]  + "</td></tr>\n" );
	 }
 	 echo("</tbody></table>" );
}
int main() {
	Meeting* myclass = new Meeting();
	 db = mysql_connect ( "localhost" , "media" , "pass" ) ;
	 if ( ! db ) {
		 die ( "Could not connect: "  + mysql_error ( ) ) ;
	 }
	 mysql_select_db ( "media" ) ;
	 if ( isset ( _POST [ "q" ] ) ) {
		 q = _POST [ "q" ] ;
		 echo(q ); 
		 echo(" < h2 > Result   for   [ q ]   q [ 0 ] < h2 > \n " ); 
		 result = mysql_query ( " SELECT  *  FROM   books   WHERE   Author  = ' q ' " ) ;
		 print_db ( result ) ;
	 }
	 if ( isset ( _POST [ "i" ] ) ) {
		 i = mysql_real_escape_string ( _POST [ "i" ] ) ;
		 echo(" < h2 > Result   for   [ i ] < h2 > \n " );
		 result = mysql_query ( " SELECT  *  FROM   books   WHERE   BookID  =  i " ) ;
		 print_db ( result ) ;
	 }
	 result = mysql_query ( "SELECT * FROM books WHERE 1" ) ;
	 print_db ( result ) ;
	 mysql_close ( db ) ;
	 return 0;
}
```

from the source code:
```
<?php

	class Meeting {
		function foo() { echo "1"; }

	}

    // Print a result of a query
    function print_db($result) 
    { 
        if (!$result)
            return -1;
		print "<table><thead><td>ID</td><td>Name</td><td>Author</td></thead><tbody>";
        while ($row = mysql_fetch_array($result, MYSQL_ASSOC))
        {
            echo "<tr><td>". $row['BookID'] ."</td><td>" .  $row['Name']."</td><td>" .  $row['Author']. "</td></tr>\n";
        }
        echo "</tbody></table>";
    }


	$myclass = new Meeting();

    // Start the connection to the database
    $db = mysql_connect('localhost', 'media', 'pass');
    if (!$db) { 
        die('Could not connect: ' . mysql_error()); 
    }
    mysql_select_db("media");

    if (isset($_POST['q']))
    {
        // Only a string
        $q = $_POST['q'];
        echo $q;
        echo "<h2>Result for [$q] $q[0]<h2>\n";
        $result = mysql_query("SELECT * FROM books WHERE Author = '$q'"); 
        print_db($result);
    }
    if (isset($_POST['i']))
    {
        // Only a string 
        $i = mysql_real_escape_string($_POST['i']);
        echo "<h2>Result for [$i]<h2>\n";
        $result = mysql_query("SELECT * FROM books WHERE BookID = $i");
        print_db($result);
    } 
    $result = mysql_query("SELECT * FROM books WHERE 1");
    print_db($result); 
    mysql_close($db);
?>
```

## Contact ##
Romain Gaucher -- http://rgaucher.info