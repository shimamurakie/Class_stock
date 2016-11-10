<!DOCTYPE html>
<html lang="ja">
<head>
<meta charset="UTF-8">
  <title>CSV形式のデータ送信2</title>
  <style type="text/css">
<!--
body {font-size: 100%;}
td {font-size: 100%;padding:2px; border: 1px #666666 solid;}
tr.top {font-size: 110%; background-color:#cccc77; font-weight:bold; padding:1px;
border: 1px #333333 solid;}
table{
border: 2px #333333 solid; border-spacing: 0px;
}

h1 {font-size:160%; }
h2 {font-size:140%; }
--> </style>
</head>
<body>
<h1>出力結果</h1>
<?php
function h($s) {
  return htmlspecialchars($s, ENT_QUOTES, 'UTF-8');
}


$i=0;
$k=0;
$arr2= array('T1');
$text = h($_POST['data']);
$array = explode("\n", $text); 
$array = array_map('trim', $array); 
$array = array_filter($array, 'strlen'); 
$array = array_values($array); 
while(true){
	if(isset($array[$i])==false)break;
$arr1 = explode(",",$array[$i]);

array_push($arr2,$arr1);

$i ++;
}
unset($arr2[0]);

echo "<table border='1'>";
foreach ($arr2 as $row) {
	if($k==0){
		
		    echo "<tr class=\"top\">";
    foreach ($row as $val) // ネストされたforeach
        echo "<td>$val</td>";
    echo "</tr>";
	$k=1;
	}
	else{
    echo "<tr>";
    foreach ($row as $val) // ネストされたforeach
        echo "<td>$val</td>";
    echo "</tr>";
	}
}
echo "</table>";

?>

</body>
</html>