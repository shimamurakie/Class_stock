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
<meta http-equiv="content-style-type" content="text/css">
<link rel="stylesheet" type="text/css" href="style/menu.css">
<LINK rel="SHORTCUT ICON" href="favicon.ico">
<title>欲しいものリスト</title>
</head>
<body>

<h2 class="titlem">欲しいものリスト</h2>
<p>ユーザ名：<?php echo $uname; ?></p>
<p><input class="menub" type="button" onclick="location.href='search.php'"value="通常表示へ"></p>
<p><input class="menub" type="button" onclick="location.href='select.php'"value="更新・削除"></p>
<p><input class="menub" type="button" onclick="location.href='insert.php'"value="追加"></p>
<form id="loginForm" method="post" action="login.php" />
  <input class="submitb" type="submit" value="ログアウト" />
</form>
</body>
</html>
