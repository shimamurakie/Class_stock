<?php
	$action = "update2.php";
	$submit = "更新する";
	$instruct = "書籍情報を変更できます";
	$noedit = "";
	
	require("fromdb.php");
	
	if (strlen($msg) > 0)
		die($msg);
	
	require("form.php");
?>