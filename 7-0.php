<!--<h3>タイムゾーン設定</h3>
<?php
$tz = "Asia/Tokyo";
if (date_default_timezone_set($tz))
    echo $tz, " OK!";
?>
-->
<?php
$d = date("c"); // ISO8601
$day = date("Y年m月d日"); // 年月日
$time = date("h時i分s秒"); // 時分秒
$ampm = date("a"); // am/pm
$week1 = array("日曜日", "月曜日", "火曜日", "水曜日", "木曜日", "金曜日", "土曜日");
$date = date_create();
$w = (int)date_format($date, 'w');
$week = $week1[$w];
//echo "<table border cellspacing=\"0\" cellpadding=\"3\">
//<tr>
//<td bgcolor=\"#778899\">1-1</td>
//<td>1-2</td>
//</tr>
//<tr>
//<td bgcolor=\"#778899\">2-1</td>
//<td>2-2</td>
//</tr>
//<tr>
//<td bgcolor=\"#778899\">3-1</td>
//<td>3-2</td>
//</tr>
//</table>";
echo "<table border cellspacing=\"0\" cellpadding=\"3\">
<tr>
<td bgcolor=\"#778899\">日付</td><td>";
echo $day,"</td>
</tr>
<tr>
<td bgcolor=\"#778899\">時刻</td><td>";
echo $time, "</td>
</tr>
<tr>
<td bgcolor=\"#778899\">曜日</td><td>";echo $week, "</td>
</tr>
</table>";

?>
