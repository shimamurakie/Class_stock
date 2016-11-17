<?php
// HTML用エスケープ関数
function h($s) {
return htmlspecialchars($s, ENT_QUOTES, 'UTF-8');
}
// データを受信する
mb_regex_encoding("UTF-8");
$data = $_POST['data'];
// データを行の配列に変換する
$lines = explode(" ", $data);

echo"<br>";

$cot=array_count_values($lines);


?>
<!DOCTYPE html>
<html>
<head>
<style type="text/css">
table, th, td {border:solid 1px; border-collapse:collapse; padding:4px;}
th {background-color:#ddd;}
</style>
<title>データを表示</title>
</head>
<body>
<h2>語句の出現頻度</h2>
<table>
<tr><th>文字</th><th>回数</th></tr>
<?php

  foreach ($cot as $soe => $ata) {
	  if(($ata == "1") ){}
	else if( preg_match("/.{2,}/u", $soe) ){
				echo "<tr><td>$soe </td><td>$ata </td></tr>";
	}
    else{}

  }
?>
</table>
</body>
</html>