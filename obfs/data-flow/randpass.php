<?php
	$rand_name_1 = 42;
	$rand_name_2 = 3;
	do
	{
		if ($rand_name_2 < 3) {
			// here
			$enter_the_new_statement;
			break;
		}
		else {
			$rand_name_2 = rand() % 4;
		}
		$rand_name_1 -= 1;
	}
	while ($rand_name_1 > 0);
?>
