<?php
function h($s) {
  return htmlspecialchars($s, ENT_QUOTES, 'UTF-8');
}


$i=0;
$arr2= array('T1');
$text = h($_POST['data']);
$array = explode("\n", $text); // とりあえず行に分割
$array = array_map('trim', $array); // 各行にtrim()をかける
$array = array_filter($array, 'strlen'); // 文字数が0の行を取り除く
$array = array_values($array); // これはキーを連番に振りなおしてるだけ
while(true){
	if(isset($array[$i])==false)break;
$arr1 = explode(",",$array[$i]);
//print_r($arr1);
array_push($arr2,$arr1);
//if(isset($array[$i])==false)break;
$i ++;
}
unset($arr2[0]);
print_r($arr2);
echo '<br>';
//var_dump($arr1);
echo '<br>';
//var_dump($arr2);
echo "<table border='1'>";
foreach ($arr2 as $row) {
    echo "<tr>";
    foreach ($row as $val) // ネストされたforeach
        echo "<td>$val</td>";
    echo "</tr>";
}
echo "</table>";

?>