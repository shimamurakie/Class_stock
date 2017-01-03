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
	$action = "delete2.php";
	$submit = "削除する";
	$instruct = "削除する情報を確認してください";
	$noedit = 'readonly = "readonly"';
	$cedit = 'readonly = "readonly"';

	require("fromdb.php");

	if (strlen($msg) > 0)
		die($msg);

	require("form.php");
?>
