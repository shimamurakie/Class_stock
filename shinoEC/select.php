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
<meta http-equiv="content-style-type" content="text/css">
<link rel="stylesheet" type="text/css" href="style/menu.css">

<title>欲しいものリスト</title>
</head>
<body>
<h2>検索結果を表示します</h2>
<table>
<tr><th>商品名</th><th>価格</th><th>優先度</th><th>登録日</th><th>備考</th>
<th colspan="2">編集</th></tr>
<?php
foreach ($result as $row) {
	echo "<tr>";
//	echo "<td>", h($row['num']), "</td>";
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
  <input class="change" type="button" onClick="location.reload();" value="最新情報を表示" />
  データの更新・削除を行った際はこちらをクリックしてください
</p>
<p>
	<input class="topb" type="button" onClick="history.back();" value="戻る" />
</p>
</body>
</html>
