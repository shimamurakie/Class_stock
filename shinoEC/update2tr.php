<?php
    require("validate.php");
?>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<title>書籍情報の更新(トランザクション使用例)</title>
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
    $sql1 = "DELETE FROM wanna WHERE num=?";
    $sql2 = "INSERT INTO wanna (num, name, price, priority, entry, note) VALUES (?, ?, ?, ?, ?, ?)";
    try {
        $dbh->beginTransaction(); // トランザクション開始
        $pre = $dbh->prepare($sql1);
        $result = $pre->execute(array($num)); // DELETE文実行
        if ($result && $pre->rowCount() == 1) {
        	 //exit('トランザクションを中断!!'); // わざと停止
            $pre = $dbh->prepare($sql2);
            $result = $pre->execute(array($num, $name, $price, $priority, $entry, $note)); // INSERT文実行
            if ($result && $pre->rowCount() == 1) {
                $dbh->commit(); // トランザクション正常終了
                echo "<p>情報を 1 件更新しました。</p>\n";
				echo "<p><input type=\"button\" onClick=\"history.back();\" value=\"戻る\" /></p>";
                exit();
            }
        }
        // どこかで異常が発生した
        $dbh->rollBack(); // トランザクション異常終了
        $err = $pre->errorCode();
        echo "<p class='error'>情報を更新できません。(エラーコード: ", $pre->errorCode(), ")</p>\n";
    } catch  (PDOException $e) {
        die("Database Update failed: ".$e->getMessage());
    }
}
?>
<p>
    <input type="button" onClick="history.back();" value="戻る" />
</p>
</body>
</html>