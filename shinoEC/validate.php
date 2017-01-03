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
#入力変数
	#$_POST['isbn'] = "978-1234567890";
	#$_POST['title'] = "本のタイトル";
	#$_POST['price'] = 1000;
	#$_POST['publish'] = "ABC出版";
	#$_POST['published'] = "2016-11-22";
#出力変数
	#$msg: エラーメッセージ（正常時は""）
	#$isbn, $title, $price, $publish, $published

// 入力データチェック
$msg = "";

// ISBNコードのチェック
if (empty($_POST['num'])) {
	$msg .= "コードが指定されていません。<br />";
} else {
	$num = trim($_POST['num']);
	if (!preg_match("/^[0-9a-f]{32}$/", $num))
		$msg .= "コードに誤りがあります。<br />";
}

// 書名のチェック
if (empty($_POST['name'])) {
	$msg .= "商品名が指定されていません。<br />";
} else {
	$name = trim($_POST['name']);
}

// 本体価格のチェック
if (empty($_POST['price'])) {
	$msg .= "価格が指定されていません。<br />";
} else {
	$price = trim($_POST['price']);
	if (!is_numeric($price))
		$msg .= "価格に誤りがあります。<br />";
}

// 出版社のチェック
if (empty($_POST['priority'])) {
	$msg .= "優先度が指定されていません。<br />";
} else {
	$priority  = trim($_POST['priority']);
		if (!is_numeric($priority))
		$msg .= "[優先度]に入力された値が誤りが数値ではありません。<br />";
	if ($priority<0 || $priority>10)
		$msg .= "[優先度]には0以上10以下の数値を入力してください。<br />";
}

// 刊行日のチェック
if (empty($_POST['entry'])) {
	$msg .= "日付が指定されていません。<br />";
} else {
	$entry = trim($_POST['entry']);
	if (!preg_match("/^[0-9]{4}-[0-1][0-9]-[0-3][0-9]$/", $entry))
		$msg .= "日付に誤りがあります。<br />";
}

	$note = trim($_POST['note']);

?>
