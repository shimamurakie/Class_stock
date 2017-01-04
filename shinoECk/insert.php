<?php
// セッションの開始
session_start();
// ユーザ名の取得
if (isset($_SESSION['uname'])) {
	$uname = $_SESSION['uname'];
} else {
	// ログインページへリダイレクト
	header('Location: login.php');
	exit();
}
?>

<?php
	$action = "insert2.php";
	$submit = "登録する";
	$instruct = "登録する情報を入力してください";
	$num = md5(uniqid(rand(), true));
	$name = "";
	$price = "";
	$priority = "";
	$today = date("Y-m-d");
	$entry = $today;
	$note = "";
	$noedit = "";
	$cedit = 'readonly = "readonly"';

	require("form.php");
?>
