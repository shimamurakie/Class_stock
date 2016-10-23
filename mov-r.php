<!DOCTYPE html>
<html lang="ja">
<head>
<meta charset="UTF-8">
<title></title>
<style type="text/css">
<!--
body {font-size: 100%;}
p {font-size: 100%;}
td {font-size: 100%;}
td.top {font-size: 110%; background-color:#BBBBBB; }
h1{font-size : 160%;}
--> 
</style>
</head>

<body>
<?php

// 出力時に必須の関数
// (HTML用 エスケープ関数)
function h($s) {
  return htmlspecialchars($s, ENT_QUOTES, 'UTF-8');
}
$y = h($_POST['year']);

	$year= (int)h($_POST['year']);

// DBに接続 
$dsn = 'sqlite:database/movie.db';
//
try {
  $dbh = new PDO($dsn);
} catch (PDOException $e) {
  echo "connect error!! (" , $e->getMessage() , ")";
  return;
}

// DBから情報を一式読み出す
// ------------------------------

// 「準備された文(SQL statement)」を用意する
$sql = "SELECT title_j,title_e,income FROM movie WHERE year = $year";
$dbc = "SELECT COUNT(*) FROM movie WHERE year = $year";


// SQLを実行する
$stmt = $dbh->query($sql);

    foreach ($dbh->query($dbc) as $row) {

        $dbca = (int)$row['COUNT(*)'] ;
    }

if (!$stmt) {
	echo "statement error!! (";
	print_r($dbh->errorInfo());

	return;
}
if (!$dbca){
    echo "条件に一致する項目はありません。";
	return;
	}

?>

<h1><?php echo $y; ?>年公開の映画</h1>

<?php
	
// 情報を取得し、テーブルとして出力する
echo "<table border='1' border cellspacing=\"0\";  cellpadding=\"4\";>\n";
    echo "  <tr>\n<td class=\"top\">タイトル名(日本語)</td><td class=\"top\">Title(English)</td>";
	echo "<td class=\"top\">興行収入</td></tr>";
//
while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
  //

  
  echo "  <tr>\n";
  foreach ($row as $key => $val) {
    echo "    <td>", h($val), "</td>\n";
  }
  echo "  </tr>\n\n";
}
echo "</table>\n";
?>
</body>
</html>
