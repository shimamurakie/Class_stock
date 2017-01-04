<?php
    require("validate.php");
?>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<meta http-equiv="content-style-type" content="text/css">
<link rel="stylesheet" type="text/css" href="style/menu.css">
<title>情報の更新</title>
</head>
<body>
<?php
if (strlen($msg) > 0) {
    echo "<p class='error'>$msg</p>\n";
} else {
    // DBに接続
    $dsn = "sqlite:database/wanna.db";
    try {
        $dbh = new PDO($dsn);
        $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    } catch (PDOException $e) {
        die("Database Connection failed: ".$e->getMessage());
    }

    // DBを更新
    $sql = "UPDATE wanna SET name=?, price=?, priority=?, entry=?, note=? WHERE num=?";
    try {
        $pre = $dbh->prepare($sql);
        $result = $pre->execute(array($name, $price, $priority, $entry, $note,  $num));
    } catch  (PDOException $e) {
        die("Database Update failed: ".$e->getMessage())
    }
    if ($result) {
        $count = $pre->rowCount();
        if ($count == 1)
            echo "<p>情報を 1 件更新しました。</p>\n";
        else
            echo "<p>更新する情報がありません。</p>\n";
    } else {
        $err = $pre->errorCode();
        echo "<p class='error'>情報を更新できません。(エラーコード: ", $pre->errorCode(), ")</p>\n";
    }
}
?>
<p>
    <input type="button" onClick="history.back();" value="戻る" />
</p>
</body>
</html>
