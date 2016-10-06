<h3>タイムゾーン設定</h3>
<?php
$tz = "Asia/Tokyo";
if (date_default_timezone_set($tz))
    echo $tz, " OK!";
?>

<h3>現在日時</h3>
<?php
$d = date("c"); // ISO8601
$day = date("Y-m-d"); // 年月日
$time = date("h:i:s"); // 時分秒
$ampm = date("a"); // am/pm
$week = date("D (w)"); // 曜日
echo $d, "<br>";
echo $day, "<br>";
echo $time, " ", $ampm, "<br>";
echo $week;
?>

<h3>エポックタイム</h3>
<?php
$now = time();
$epoc = strtotime("1970-01-01 00:00:00 +09:00");
echo $now, "<br>";
echo $epoc, "<br>";
?>

<h3>strtotime/checkdate関数</h3>
<?php
$after_a_month = strtotime("+1 month"); // 本日の1か月後
echo date("Y-m-d",$after_a_month), "<br>";
var_dump(checkdate(2, 29, 2016)); echo "<br>";
var_dump(checkdate(2, 29, 2017)); echo "<br>";
?>