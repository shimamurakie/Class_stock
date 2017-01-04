<?php
#入力変数
	#$action = "insert2.php";
	#$submit = "登録する";
	#$instruct = "新規登録する書籍情報を入力してください";
	#$isbn = "978-1234567890";
	#$title = "本のタイトル";
	#$price = 1000;
	#$publish = "ABC出版";
	#$published = "2016-11-22";
	#$noedit = 'readonly = "readonly"';
#出力変数
	#なし

// HTML用 エスケープ関数
function h($s) {
  return htmlspecialchars($s, ENT_QUOTES, 'UTF-8');
}
?>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<meta http-equiv="content-style-type" content="text/css">
<link rel="stylesheet" type="text/css" href="style/menu.css">
<LINK rel="SHORTCUT ICON" href="favicon.ico">
<title>欲しいものリスト</title>
</head>
<body>
<h2 class="list"><?php echo $instruct; ?></h2>
<form method="POST" action="<?php echo $action; ?>">
<p>
	<label class="hidden">コード(デバッグ用)：<br />
		<input class="hidden" type="text" name="num" size="50" value="<?php echo $num; ?>"
		<?php echo $cedit; ?> />
	</label>
</p>
<p>
	<label>商品名：<br />
		<input class="edit" type="text" name="name" size="50" value="<?php echo h($name); ?>"
		<?php echo $noedit; ?> /> 例: スッキリわかるJava
	</label>
</p>
<p>
	<label>価格：<br />
		<input class="edit" type="text" name="price" size="8" value="<?php echo $price; ?>"
		<?php echo $noedit; ?> />
	</label> 例: 2800
</p>
<p>
	<label>優先度(1から10までの数値で入力してください)：<br />
		<input class="edit" type="text" name="priority" size="8" value="<?php echo $priority; ?>"
		<?php echo $noedit; ?> />  例: 6
	</label>
</p>
<p>
	<label>登録日：<br />
		<input class="edit" type="text" name="entry" size="12" value="<?php echo $entry; ?>"
		<?php echo $noedit; ?> /> <br />
			※例のように[年(西暦)-月(1桁の場合先頭に0)-日(1桁の場合先頭に0)]と入力してください。
	</label> 例: 2016-01-23
</p>
<p>
	<label>備考：<br />
		<input class="edit" type="text" name="note" size="50" value="<?php echo h($note); ?>"
		<?php echo $noedit; ?> />
	</label> 例: ロフ○では定価
</p>
<p>
	<input class="change" type="submit" value="<?php echo $submit; ?>" />
	<input class="topb" type="button" onClick="history.back();" value="戻る" />

</p>
</form>
</body>
</html>
