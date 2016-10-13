<?php

// 出力時に必須の関数
// (HTML用 エスケープ関数)
$week = array("(日)", "(月)", "(火)", "(水)", "(木)", "(金)", "(土)");
$datetime = date("w", mktime(0, 0, 0, (int)$_POST['month'], (int)$_POST['date'], (int)$_POST['year']));
var_dump($datetime);

function h($s) {
  return htmlspecialchars($s, ENT_QUOTES, 'UTF-8');
}

// HTMLから受け取った要素を出力する
echo "入力された名前は" ;
echo h($_POST['year']);
echo h($_POST['month']);
echo h($_POST['date']) ;
echo $week[$datetime] ;
echo "です。<br>\n";


?>