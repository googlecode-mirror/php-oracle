<?php

	class rand_class_name
	{
		function rand_func_name_2($rand_name_1) 
		{
			return $rand_name_1 + 1;
		}
	}

	function rand_func_name_1($rand_name_2) 
	{
		return $rand_name_2 + 1;
	}
	
	if (rand_func_name_1(0) > 0 && rand_class_name::rand_func_name_2(0)) {
		$enter_the_new_statement;
	}
?>
