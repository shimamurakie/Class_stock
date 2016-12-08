<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<title>書籍情報の削除</title>
</head>
<body>
<?php
// ISBNコードをチェック
if (empty($_POST["isbn"])) {
	echo "<p class='error'>ISBNコードが指定されていません。<br /></p>\n";
} else {
	$isbn = trim($_POST["isbn"]);
	
	// DBに接続
	$dsn = "sqlite:database/books.db";
	try {
		$dbh = new PDO($dsn);
		$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	} catch (PDOException $e) {
		die("Database Connection failed: ".$e->getMessage());
	}
	
	// DBを更新
	$sql = "DELETE FROM books WHERE isbn=?";
	try {
		$pre = $dbh->prepare($sql);
		$result = $pre->execute(array($isbn));
	} catch  (PDOException $e) {
		die("Database Deletion failed: ".$e->getMessage());
	}
	if ($result) {
		$count = $pre->rowCount();
		if ($count == 1)
			echo "<p>書籍情報を 1 件削除しました。</p>\n";
		else
			echo "<p>削除する書籍情報がありません。</p>\n";
	} else {
		$err = $pre->errorCode();
		echo "<p class='error'>書籍情報を削除できません。(エラーコード: ", $pre->errorCode(), ")</p>\n";
	}
}
?>
<p>
	<input type="button" onClick="history.back();" value="戻る" />
</p>
</body>
</html>