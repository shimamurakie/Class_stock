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
<!DOCTYPE html>
<html lang="ja">
<head>
<meta charset="utf-8">
<title>ようこそ</title>
</head>
<body>
<h2>ようこそ</h2>
<p><?php echo $uname; ?>さん　こんにちは。</p>
<h2>書籍管理システムへようこそ</h2>
<p><a href="select.php">検索・更新・削除</a></p>
<p><a href="insert.php">追加</a></p>
<form id="loginForm" method="post" action="login.php" />
  <input type="submit" value="ログアウト" />
</form>
</body>
</html>