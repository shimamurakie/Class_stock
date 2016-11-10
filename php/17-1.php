<?php

$i = PHP_INT_MAX;
var_dump($i);
$i ++;
var_dump($i); // Œ^‚ªfloat‚É‚È‚é
echo "<br>\n";
//
$i = PHP_INT_MAX * -1;
var_dump($i);
$i --;
var_dump($i);
$i --;
var_dump($i); // Œ^‚ªfloat‚É‚È‚é
