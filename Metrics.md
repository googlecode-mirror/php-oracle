# Source Code Security Metric #
A source code security metric is a tool which try to evaluate the size of the security problem of a given source code. The aim of such metrics is to approximate the number of weaknesses that a Static Analysis Tool can find.

## The metrics in PHP-ORACLE ##
Currently, there are few metrics (and few are security related) in the PHP-ORACLE, I am planning to implements others and especially McCabe's (which I want to correlate with another I'm developing). Here are the metrics present in the project:
  * Number of classes
  * Number of functions
  * Number of distinct variables
  * Number of [wiki:PhpSinks PHP Sinks functions])
  * Number of functions considered as resources for the rest of the source code (getting information from database, files etc.)
  * Number of direct inputs coming from:	$_GET,$_POST,$_FILE,$_COOKIE,$_SESSION,$_REQUEST,$_SERVER
  * Number of direct [wiki:InputDiffusion inputs diffused] in other variables
  * Number of direct inputs diffused in other variables that are going to a possible sink (this is the metric I'm currently testing)_

## Contact ##
Romain Gaucher -- http://rgaucher.info