<h3>変数について</h3>
<?php
$val1 = 12;
$val_2 = 345;
echo $val1; echo "<br>";
echo $val_2; echo "<br>";
// $3wrong = 6789; // 誤った変数名
$val3 = $val1;
echo $val3; echo "<br>";
$val4 = $undef; // 未定義の変数名
echo $val4; // 未定義の変数名
?>

<h3>数値の扱い</h3>
<?php
$x = 8;
$y = 3;
echo $x + $y; echo "<br>";
echo $x - $y; echo "<br>";
echo $x * $y; echo "<br>";
echo $x / $y; echo "<br>";
echo $x % $y; echo "<br>";
$z = sqrt($y); // 平方根の計算
echo $z;
?>

<h3>文字列の扱い</h3>
<?php
$str1 = "日本語";
$str2 = "文字列";
echo $str1; echo "<br>";
echo $str2; echo "<br>";
echo $str1.$str2; // 文字列の連結
?>