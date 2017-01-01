<?php
	$action = "insert2.php";
	$submit = "登録する";
	$instruct = "登録する書籍情報を入力してください";
	$num = md5(uniqid(rand(), true));
	$name = "";
	$price = "";
	$priority = "";
	$today = date("Y-m-d");
	$entry = $today;
	$note = "";
	$noedit = "";
	
	require("form.php");
?>
