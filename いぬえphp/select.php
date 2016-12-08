<?php
// HTML用 エスケープ関数
function h($s) {
  return htmlspecialchars($s, ENT_QUOTES, 'UTF-8');
}

// DBに接続
$dsn = "sqlite:database/books.db";
try {
	$dbh = new PDO($dsn);
	$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
	die("Database Connection failed: ".$e->getMessage());
}

// DBを検索
$sql = "SELECT * FROM books";
try {
	$pre = $dbh->prepare($sql);
	$pre->execute();
	$result = $pre->fetchall(PDO::FETCH_ASSOC);
} catch (PDOException $e) {
	die("Database Selection failed: ".$e->getMessage());
}
?>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<style type="text/css">
	table, th, td {border:solid 1px; border-collapse:collapse; padding:8px;}
	th {background-color:#ddd;}
	.right {text-align:right;}
</style>
<title>書籍情報</title>
</head>
<body>
<h2>検索結果を表示します</h2>
<table>
<tr><th>ISBNコード</th><th>書名</th><th>本体価格</th><th>出版社</th><th>刊行日</th>
<th colspan="2">操作</th></tr>
<?php
foreach ($result as $row) {
	echo "<tr>";
	echo "<td>", h($row['isbn']), "</td>";
    echo "<td>", h($row['title']), "</td>";
    echo "<td class='right'>", h($row['price']), "</td>";
    echo "<td>", h($row['publish']), "</td>";
    echo "<td>", h($row['published']), "</td>";
    echo "<td><a href='update.php?isbn=", h($row['isbn']), "'>更新</a></td>";
    echo "<td><a href='delete.php?isbn=", h($row['isbn']), "'>削除</a></td>";
    echo "</tr>\n";
}
?>
</table>
<p>
	<input type="button" onClick="history.back();" value="戻る" />
</p>
</body>
</html>