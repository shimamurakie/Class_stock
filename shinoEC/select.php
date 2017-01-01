<?php
// HTML用 エスケープ関数
function h($s) {
  return htmlspecialchars($s, ENT_QUOTES, 'UTF-8');
}

// DBに接続
$dsn = "sqlite:database/wanna.db";
try {
	$dbh = new PDO($dsn);
	$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
	die("Database Connection failed: ".$e->getMessage());
}

// DBを検索
$sql = "SELECT * FROM wanna";
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
<title>欲しいものリスト</title>
</head>
<body>
<h2>検索結果を表示します</h2>
<table>
<tr><th>コード</th><th>商品名</th><th>価格</th><th>優先度</th><th>登録日</th><th>備考</th>
<th colspan="2">操作</th></tr>
<?php
foreach ($result as $row) {
	echo "<tr>";
	echo "<td>", h($row['num']), "</td>";
    echo "<td>", h($row['name']), "</td>";
    echo "<td class='right'>", h($row['price']), "</td>";
    echo "<td>", h($row['priority']), "</td>";
    echo "<td>", h($row['entry']), "</td>";
	echo "<td>", h($row['note']), "</td>";
    echo "<td><a href='update.php?num=", h($row['num']), "'>更新</a></td>";
    echo "<td><a href='delete.php?num=", h($row['num']), "'>削除</a></td>";
    echo "</tr>\n";
}
?>
</table>
<p>
	<input type="button" onClick="history.back();" value="戻る" />
</p>
</body>
</html>