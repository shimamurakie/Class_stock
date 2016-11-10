<?php

$a = array( // 多次元配列
  array('A', 10, 0.5, 'apple'),
  array('B', 20, 0.25, 'banana'),
  array('C', 30, 0.125, 'cherry')
);

echo "<table border='1'>";
foreach ($a as $row) {
    echo "<tr>";
    foreach ($row as $val) // ネストされたforeach
        echo "<td>$val</td>";
    echo "</tr>";
}
echo "</table>";

echo count($a), "<br>\n";   // count関数で要素数を取得
print_r($a);    // print_r関数で配列の内容を表示
echo "<br>";

unset($a[1]);   // unset関数で真ん中の要素を削除

echo count($a), "<br>\n";
print_r($a);
