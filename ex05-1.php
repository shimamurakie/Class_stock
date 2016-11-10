<?php
function h($s) {
  return htmlspecialchars($s, ENT_QUOTES, 'UTF-8');
}



$text = h($_POST['data']);
$array = explode("\n", $text); // とりあえず行に分割
$array = array_map('trim', $array); // 各行にtrim()をかける
$array = array_filter($array, 'strlen'); // 文字数が0の行を取り除く
$array = array_values($array); // これはキーを連番に振りなおしてるだけ

$b = explode(",",$array[1]);

var_dump($array);
echo '<br>';
var_dump($b);

?>