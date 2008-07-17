<?php

	if (!empty($_GET['tID']))
	{
		$tID = (int)$_GET['tID'];

		function getFileSize($fichier)
		{
			$fileSize=@filesize($fichier);
			if ($fileSize >= 1073741824)
			{$fileSize = round($fileSize / 1073741824 * 100) / 100 . " Gb";}
			elseif ($fileSize >= 1048576)
			{$fileSize = round($fileSize / 1048576 * 100) / 100 . " Mb";}
			elseif ($fileSize >= 1024)
			{$fileSize = round($fileSize / 1024 * 100) / 100 . " Kb";}
			else
			{$fileSize = $fileSize . " bytes";}
			
			if($fileSize==0) {$fileSize="-";}
			return $fileSize;
		}

		// include the basket utility here
		include_once ('utils/testsuiteUtilities.php');

		// did you try to change some fields in your profile
		include_once ('view_testcase_form.php');

		$sql_contributions = "select t.testcaseid,flawed,author,associatedtestcases,fullname,name,typeoftestcase,ref,inputstring,outputstring,instruction,submissiondate,description,filename,status
		                      from `testcase` as t, `language` as l,`users` as u, `typeoftestcase` as y, `filestable` as f, `flawedcodemetadata` as w 
		                      where t.testcaseid ='$tID' and t.languageid = l.languageid and t.contributorid = u.contributorid and t.typeoftestcaseid = y.typeoftestcaseid and f.testcaseid = t.testcaseid and  t.testcaseid = w.testcaseid ";
		$results = $db->get_results($sql_contributions,ARRAY_N);

		$contributions = sizeof($results);
		if ($contributions > 0)
		{
			// Make editable the information
			// 'Have to check if the current user is the author
			$ownerName = getContributorNameNyFullName($results[0][4]);

			// Get the number of comments
			$sql_comments = "SELECT * FROM `comments` as c INNER JOIN `users` as u WHERE c.testcaseid = '$tID' AND c.contributorid = u.contributorid ORDER BY commentdate";
			$comments     = $db->get_results($sql_comments,ARRAY_A);

			$fileSizeArray = array();
			$flaw          = array();

			$sql_flaws = "SELECT flawid, flawname FROM flaw WHERE flawname != '0' ORDER BY lft";
			$flaws = $db->get_results($sql_flaws, ARRAY_N);
			$depth = $flawManager->depth();
			$nbFlaws = sizeof($flaws);

			// get the code complexities information
			$sql_ccplx = "SELECT complexityid,keyword FROM codecomplexity WHERE 1";
			$ccplx = $db->get_results($sql_ccplx, ARRAY_N);

			$flawArray = Array();
			// try to flatten the flaws for line number
			for ($i=0;$i<sizeof($flaw);++$i)
			{
				for ($j=0;$j<sizeof($flaw[$i]);++$j)
				{
					// only check for the 2 first data... the rest will be append to the current...
					if ($flaw[$i][$j][0] == $flaw[$i][$j+1][0] && $flaw[$i][$j][1] == $flaw[$i][$j+1][1])
					{
						$tmpFlawLine = $flaw[$i][$j];
						if ($tmpFlawLine[2] == '0')
							$tmpFlawLine[2] == '';
						while ($flaw[$i][$j][0] == $flaw[$i][$j+1][0] && $flaw[$i][$j][1] == $flaw[$i][$j+1][1])
						{
							$tmpFlawLine[2] .= ',' . $flaw[$i][$j+1][2];
							++$j;
						}
						if ($tmpFlawLine[2][0] == '0') {
							$tmpFlawLine[2][0] = '';
							$tmpFlawLine[2][1] = '';
						}
						//
						array_push($flawArray, $tmpFlawLine);
					}
					else
						array_push($flawArray, $flaw[$i][$j]);
				}
			}

			if (sizeof($flawArray) == 1)
			{
				$newFlaw = Array();
				array_push($newFlaw, $flawArray);
				$flawArray = $newFlaw;
			}
			else
			{
				$newFlaw = Array();
				for ($i=0;$i<sizeof($flawArray);++$i)
					array_push($newFlaw, Array($flawArray[$i]));
				$flawArray = $newFlaw;
			}

			// Assign the 6th column of flaws with the path
			for ($i=0;$i<sizeof($flawArray);++$i)
			{
				$resultFlawPath = $flawManager->path($flawArray[$i][0][1]);

				if (sizeof($resultFlawPath) > 0)
				{
					$str = Array();
					// set the value
					for ($j=0;$j<sizeof($resultFlawPath);++$j)
						if ($resultFlawPath[$j][0] != "Any...")
						{
							$put = $resultFlawPath[$j][0];
							if ($j == sizeof($resultFlawPath) - 1)
							{
								$put = "<span style='color:red'>" . $put . "</span>";
							}
							array_push($str, $put);
						}
					$flawArray[$i][0][6] = $str;
				}
			}
		}
		else
		{
        	$smarty->assign('warning_msg', "This TestCase no longer exists.");
			$smarty->display('template.tpl');
		}
	}

?>
