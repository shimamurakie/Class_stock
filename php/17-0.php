<?php
// 一重引用符と二重引用符の違い
$x = 'abc';
echo $x, '\n';  // \nという文字列
echo '<br>';
echo $x, "\n";  // 改行文字
echo '<br><br>';

$y1 = '$x def';
echo $y1, "<br>\n";
$y2 = "$x def";
echo $y2, "<br>\n";
$y3 = "$xdef";
echo $y3, "<br>\n";
$y4 = "{$x}def";
echo $y4, "<br>\n";

// Here　documentとNowdoc
$str1 = <<<EOD
Example of string<br>
spanning multiple lines<br>
using heredoc syntax.<br>
$x is parsed.
EOD;
echo $str1;
echo '<br><br>';

$str2 = <<<'EOD'
Example of string<br>
spanning multiple lines<br>
using nowdoc syntax.<br>
$x is not parsed.
EOD;
echo $str2;