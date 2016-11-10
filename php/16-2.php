<pre>
<?php

//
var_dump(empty($undef));
$noval; var_dump(empty($noval));
echo "<br>";
//
$def = ""; var_dump(empty($def));
$def = "0"; var_dump(empty($def));
$def = 0; var_dump(empty($def));
$def = 0.0; var_dump(empty($def));
$def = array(); var_dump(empty($def));
$def = array(0, 1); var_dump(empty($def[2]));
$def = NULL; var_dump(empty($def));
$def = FALSE; var_dump(empty($def));
echo "<br>";
//
$def = " "; var_dump(empty($def));
$def = -1; var_dump(empty($def));
$def = TRUE; var_dump(empty($def));
echo "<br>";
//
$def = ""; var_dump(isset($def));
$def = "0"; var_dump(isset($def));
$def = 0; var_dump(isset($def));
$def = 0.0; var_dump(isset($def));
$def = array(); var_dump(isset($def));
$def = array(0, 1); var_dump(isset($def[2]));
$def = NULL; var_dump(isset($def));
$def = FALSE; var_dump(isset($def));
