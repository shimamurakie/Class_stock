<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<title>書籍情報の更新</title>
</head>
<body>
<?php
// ISBNコードをチェック
if (empty($_POST["isbn"])) {
	echo "<p class='error'>ISBNコードが指定されていません。<br /></p>\n";
} else {
	$isbn = trim($_POST["isbn"]);
	$title = trim($_POST["title"]);
	$price = trim($_POST["price"]);
	$publish = trim($_POST["publish"]);
	$published = trim($_POST["published"]);
	
	// DBに接続
	$dsn = "sqlite:database/books.db";
	try {
		$dbh = new PDO($dsn);
		$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	} catch (PDOException $e) {
		die("Database Connection failed: ".$e->getMessage());
	}
	
	
	// DBを更新
	$sql = "UPDATE books SET isbn=?,title=?,price=?,publish=?,published=? WHERE isbn=?";
	try {
	//	var_dump(array($isbn, $title, $price, $publish, $published,$isbn));
		$pre = $dbh->prepare($sql);
		$result = $pre->execute(array($isbn, $title, $price, $publish, $published,$isbn));
		//$result = $pre->execute(array($isbn));
	} catch  (PDOException $e) {
		die("Database Deletion failed: ".$e->getMessage());
	}
	if ($result) {
		$count = $pre->rowCount();
		if ($count == 1)
			echo "<p>書籍情報を更新しました。</p>\n";
		else
			echo "<p>ISBNコードは変更できません。</p>\n";
	} else {
		$err = $pre->errorCode();
		echo "<p class='error'>書籍情報を更新できません。(エラーコード: ", $pre->errorCode(), ")</p>\n";
	}
}
?>
<p>
	<input type="button" onClick="history.back();" value="戻る" />
</p>
</body>
</html>