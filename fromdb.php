<?php
#入力変数
	#$_GET['isbn'] = "978-1234567890";
#出力変数
	#$msg: エラーメッセージ（正常時は""）
	#$isbn, $title, $price, $publish, $published

// ISBNコードのチェック
$msg = "";
if (empty($_GET['isbn'])) {
	$msg = "ISBNコードが指定されていません。<br />";
} else {
	$isbn = trim($_GET['isbn']);
	
	// DBに接続
	$dsn = "sqlite:database/books.db";
	try {
		$dbh = new PDO($dsn);
		$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	} catch (PDOException $e) {
		die("Database Connection failed: ".$e->getMessage());
	}
	
	// DBを検索
	$sql = "SELECT isbn, title, price, publish, published FROM books WHERE isbn=?";
	try {
		$pre = $dbh->prepare($sql);
		$pre->execute(array($isbn));
		$result = $pre->fetchall(PDO::FETCH_ASSOC);
	} catch  (PDOException $e) {
		die("Database Selection failed: ".$e->getMessage());
	}
	
	// データを取得
	if (isset($result[0])) {
		$row = $result[0];
		$title = $row['title'];
		$price = $row['price'];
		$publish = $row['publish'];
		$published = $row['published'];
	} else {
		$msg = "該当する書誌情報がありません。<br />";
	}
}
?>