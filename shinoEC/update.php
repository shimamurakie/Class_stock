<?php
    $action = "update2tr.php";
    $submit = "更新する";
    $instruct = "情報を更新してください";
    $noedit = '';
    
    require("fromdb.php");
    
    if (strlen($msg) > 0)
        die($msg);

    require("form.php");
?>
