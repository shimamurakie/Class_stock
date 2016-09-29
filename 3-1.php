<?php
// おみくじの群れを用意する
$mikuji_array = array(
  '<img src="daikichi.gif">',
  '<img src="chukichi.gif">',
    '<img src="shokichi.gif">',
	'<img src="suekichi.gif">',
	'<img src="daikyo.gif">',
	'<img src="kyo.gif">',
	'<img src="kichi.gif">',
);
//var_dump($mikuji_array);
//var_dump($mikuji_array[0]);

// おみくじを引く
$i = mt_rand(0, count($mikuji_array) - 1 );
$mikuji_string = $mikuji_array[$i];

?>
<html>

<head>
  <title>おみくじ</title>
</head>

<body>
今日のあなたの運勢は
【<?php echo $mikuji_string; ?>】です！
</body>

</html>
