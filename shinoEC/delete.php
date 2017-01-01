<?php
	$action = "delete2.php";
	$submit = "削除する";
	$instruct = "削除する情報を確認してください";
	$noedit = 'readonly = "readonly"';
	
	require("fromdb.php");
	
	if (strlen($msg) > 0)
		die($msg);
	
	require("form.php");
?>