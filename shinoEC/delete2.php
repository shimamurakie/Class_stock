<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<title>情報の削除</title>
</head>
<body>
<?php
// ISBNコードをチェック
if (empty($_POST["num"])) {
	echo "<p class='error'>コードが指定されていません。<br /></p>\n";
} else {
	$num = trim($_POST["num"]);
	
	// DBに接続
	$dsn = "sqlite:database/wanna.db";
	try {
		$dbh = new PDO($dsn);
		$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	} catch (PDOException $e) {
		die("Database Connection failed: ".$e->getMessage());
	}
	
	// DBを更新
	$sql = "DELETE FROM wanna WHERE num=?";
	try {
		$pre = $dbh->prepare($sql);
		$result = $pre->execute(array($num));
	} catch  (PDOException $e) {
		die("Database Deletion failed: ".$e->getMessage());
	}
	if ($result) {
		$count = $pre->rowCount();
		if ($count == 1)
			echo "<p>情報を 1 件削除しました。</p>\n";
		else
			echo "<p>削除する情報がありません。</p>\n";
	} else {
		$err = $pre->errorCode();
		echo "<p class='error'>情報を削除できません。(エラーコード: ", $pre->errorCode(), ")</p>\n";
	}
}
?>
<p>
	<input type="button" onClick="history.back();" value="戻る" />
</p>
</body>
</html>