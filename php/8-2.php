<?php

// 「今日の日付」を取得
$todays_year = date('Y');
$todays_month = date('n');
$todays_date = date('j');

//var_dump($datetime);
?>
<!DOCTYPE html>
<html lang="ja">
<head>
<meta charset="UTF-8">
<style type="text/css">
<!--
body {font-size: 100%;}
p {font-size: 100%;}
td {font-size: 100%;}
td.top {font-size: 110%; background-color:#BBBBBB; }
h1{font-size : 160%;}
--> 
</style>
<title></title>
</head>

<body>
<?php
echo "<p>公開年を半角数字4桁で入力してください</p>";

echo "<form action=\"./mov-r.php\" method=\"post\">";
//
echo "<input name=\"year\" size=\"6\" maxlength=\"4\">\n";

//念


echo "<button type=\"submit\">送信する</button>";

echo "</form>";
?>

</body>
</html>
