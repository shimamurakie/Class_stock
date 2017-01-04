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
<LINK rel="SHORTCUT ICON" href="favicon.ico">
<title>欲しいものリスト</title>
</head>
<body>
<h2 class="list">欲しいものリスト</h2>
<table>
<tr><th>商品名</th><th>価格</th><th>優先度</th><th>登録日</th><th>備考</th>
</tr>
<?php
foreach ($result as $row) {
	echo "<tr>";
//	echo "<td>", h($row['num']), "</td>";
    echo "<td>", h($row['name']), "</td>";
    echo "<td class='right'>", h($row['price']), "</td>";
    echo "<td>", h($row['priority']), "</td>";
    echo "<td>", h($row['entry']), "</td>";
	echo "<td>", h($row['note']), "</td>";
   // echo "<td><a href='update.php?num=", h($row['num']), "'>更新</a></td>";
  //  echo "<td><a href='delete.php?num=", h($row['num']), "'>削除</a></td>";
    echo "</tr>\n";
}
?>
</table>
<p>
  <input class="descb" type="button" onclick="location.href='upbtm/priceup.php'"value="価格順(降順)">
  <input class="descb" type="button" onclick="location.href='upbtm/wantup.php'"value="欲しい順(降順)">
	  <input class="descb" type="button" onclick="location.href='upbtm/entryup.php'"value="登録順(降順)">
</p>
<p>
  <input class="ascb" type="button" onclick="location.href='upbtm/pricebtm.php'"value="価格順(昇順)">
  <input class="ascb" type="button" onclick="location.href='upbtm/wantbtm.php'"value="欲しい順(昇順)">
	  <input class="ascb" type="button" onclick="location.href='upbtm/entrybtm.php'"value="登録順(昇順)">
</p>
<p>
<!--	<input type="button" onClick="history.back();" value="戻る" /> -->
	<input class="topb" type="button" onclick="location.href='logged.php'"value="トップメニュー">
</p>
</body>
</html>
