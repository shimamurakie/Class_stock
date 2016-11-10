<?php

ini_set('display_errors', 'on');
error_reporting(E_ALL);

// 存在しないファイルをopenしようとしている
$fp = fopen('dummy', 'r');
