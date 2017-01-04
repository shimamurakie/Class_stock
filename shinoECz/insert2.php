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
	require("validate.php");
?>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<title>情報の登録</title>
<meta http-equiv="content-style-type" content="text/css">
<link rel="stylesheet" type="text/css" href="style/menu.css">
<LINK rel="SHORTCUT ICON" href="favicon.ico">
</head>
<body>
<?php
if (strlen($msg) > 0) {
	echo "<p class='error'>$msg</p>\n";
} else {
	// DBに接続
	$dsn = "sqlite:database/wanna.db";
	try {
		$dbh = new PDO($dsn);
		$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	} catch (PDOException $e) {
		die("Database Connection failed: ".$e->getMessage());
	}

	// DBを更新
	$sql = "INSERT INTO wanna (num, name, price, priority , entry ,note) VALUES (?, ?, ?, ?, ?, ? )";
	try {
		$pre = $dbh->prepare($sql);
		$result = $pre->execute(array($num, $name, $price, $priority , $entry ,$note));
	} catch  (PDOException $e) {
		die("Database Insertion failed: ".$e->getMessage());
	}
	if ($result) {
		$count = $pre->rowCount();
		echo "<p>情報を $count 件登録しました。</p>\n";
	} else {
		$err = $pre->errorCode();
		echo "<p class='error'>情報を登録できません。(エラーコード: ", $pre->errorCode(), ")</p>\n";
	}
}
?>
<p>
<input class="topb" type="button" onClick="history.back();" value="戻る" />
</p>
</body>
</html>
