<?php

// 「今日の日付」を取得
$todays_year = date('Y');
$todays_month = date('n');
$todays_date = date('j');

//var_dump($datetime);
?>

<?php
echo "<p>日付を入力してください</p>";

echo "<form action=\"./8-3.php\" method=\"post\">";
//
echo "<select name=\"year\">\n";

//念
for($i = 1900; $i <= 2100; $i ++) {
  if ($i == $todays_year) {
    // 書き出す日付と今日の日付が合致していたら、selectedを追記出来るようにしておく
    $atr1 = " selected";
  } else {
    $atr1 = "";
  }
  // 出力
  echo "<option value='" , $i , "'" , $atr1 , ">" , $i , "</option>\n";
}
//
echo "</select>\n"; echo "<select name=\"month\">\n";

//月
for($i = 1; $i <= 12; $i ++) {
  if ($i == $todays_month) {
    // 書き出す日付と今日の日付が合致していたら、selectedを追記出来るようにしておく
    $atr2 = " selected";
  } else {
    $atr2 = "";
  }
  // 出力
  echo "<option value='" , $i , "'" , $atr2 , ">" , $i , "</option>\n";
}
//
echo "</select>\n"; echo "<select name=\"date\">\n";

//日
for($i = 1; $i <= 31; $i ++) {
  if ($i == $todays_date) {
    // 書き出す日付と今日の日付が合致していたら、selectedを追記出来るようにしておく
    $atr3 = " selected";
  } else {
    $atr3 = "";
  }
  // 出力
  echo "<option value='" , $i , "'" , $atr3 , ">" , $i , "</option>\n";
}


//
echo "</select>\n";

echo "<button type=\"submit\">送信する</button>";

echo "</form>";
?>