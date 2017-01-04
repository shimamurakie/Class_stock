<?php
#入力変数
	#$_GET['isbn'] = "978-1234567890";
#出力変数
	#$msg: エラーメッセージ（正常時は""）
	#$isbn, $title, $price, $publish, $published

// ISBNコードのチェック
$msg = "";
if (empty($_GET['num'])) {
	$msg = "コードが指定されていません。<br />";
} else {
	$num = trim($_GET['num']);
	
	// DBに接続
	$dsn = "sqlite:database/wanna.db";
	try {
		$dbh = new PDO($dsn);
		$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	} catch (PDOException $e) {
		die("Database Connection failed: ".$e->getMessage());
	}
	
	// DBを検索
	$sql = "SELECT num, name, price, priority, entry ,note FROM wanna WHERE num=?";
	try {
		$pre = $dbh->prepare($sql);
		$pre->execute(array($num));
		$result = $pre->fetchall(PDO::FETCH_ASSOC);
	} catch  (PDOException $e) {
		die("Database Selection failed: ".$e->getMessage());
	}
	
	// データを取得
	if (isset($result[0])) {
		$row = $result[0];
		$name = $row['name'];
		$price = $row['price'];
		$priority = $row['priority'];
		$entry = $row['entry'];
		$note = $row['note'];
	} else {
		$msg = "該当する情報がありません。<br />";
	}
}
?>