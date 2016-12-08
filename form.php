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
<title>書籍情報</title>
</head>
<body>
<h2><?php echo $instruct; ?></h2>
<form method="POST" action="<?php echo $action; ?>">
<p>
	<label>ISBNコード：<br />
		<input type="text" name="isbn" size="20" value="<?php echo $isbn; ?>" 
		<?php echo $noedit; ?> />
	</label> 例: 978-1234567890
</p>
<p>
	<label>書名：<br />
		<input type="text" name="title" size="50" value="<?php echo h($title); ?>" 
		<?php echo $noedit; ?> />
	</label>
</p>
<p>
	<label>本体価格：<br />
		<input type="text" name="price" size="6" value="<?php echo $price; ?>" 
		<?php echo $noedit; ?> />
	</label> 例: 2800
</p>
<p>
	<label>出版社：<br />
		<input type="text" name="publish" size="50" value="<?php echo h($publish); ?>" 
		<?php echo $noedit; ?> />
	</label>
</p>
<p>
	<label>刊行日：<br />
		<input type="text" name="published" size="12" value="<?php echo $published; ?>" 
		<?php echo $noedit; ?> />
	</label> 例: 2016-01-23
</p>
<p>
	<input type="submit" value="<?php echo $submit; ?>" />
	<input type="button" onClick="history.back();" value="戻る" />

</p>
</form>
</body>
</html>