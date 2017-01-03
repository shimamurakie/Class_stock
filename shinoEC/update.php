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
    $action = "update2tr.php";
    $submit = "更新する";
    $instruct = "情報を更新してください";
    $noedit = '';
    $cedit = 'readonly = "readonly"';

    require("fromdb.php");

    if (strlen($msg) > 0)
        die($msg);

    require("form.php");
?>
