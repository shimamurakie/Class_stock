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
if (empty($_POST['isbn'])) {
	$msg .= "ISBNコードが指定されていません。<br />";
} else {
	$isbn = trim($_POST['isbn']);
	if (!preg_match("/^978-[0-9]{10}$/", $isbn))
		$msg .= "ISBNコードに誤りがあります。<br />";
}

// 書名のチェック
if (empty($_POST['title'])) {
	$msg .= "書名が指定されていません。<br />";
} else {
	$title = trim($_POST['title']);
}

// 本体価格のチェック
if (empty($_POST['price'])) {
	$msg .= "本体価格が指定されていません。<br />";
} else {
	$price = trim($_POST['price']);
	if (!is_numeric($price))
		$msg .= "本体価格に誤りがあります。<br />";
}

// 出版社のチェック
if (empty($_POST['publish'])) {
	$msg .= "出版社が指定されていません。<br />";
} else {
	$publish = trim($_POST['publish']);
}

// 刊行日のチェック
if (empty($_POST['published'])) {
	$msg .= "刊行日が指定されていません。<br />";
} else {
	$published = trim($_POST['published']);
	if (!preg_match("/^[0-9]{4}-[0-1][0-9]-[0-3][0-9]$/", $published))
		$msg .= "刊行日に誤りがあります。<br />";
}
?>