<?php
// HTML用 エスケープ関数
function h($s) {
  return htmlspecialchars($s, ENT_QUOTES, 'UTF-8');
}
// セッションの開始
session_start();
unset($_SESSION['uname']);
// 来訪ルートの判定
if (isset($_POST['email']) AND isset($_POST['pass'])) {
	// POSTメソッドの場合
	$msg = '';
	// メールアドレスのチェック
	$email = $_POST['email'];
	if (empty($email))
		$msg.= "<p class='caution'>メールアドレス を入力してください。</p>\n";
	// パスワードのチェック
	$pass = $_POST['pass'];
	if (empty($pass))
		$msg.= "<p class='caution'>パスワード を入力してください。</p>\n";
	// チェック結果の判定
	if (!$msg) {
		// パスワードを暗号化する
		$pass = sha1($pass);
		// データベースに接続する
		$dsn = 'sqlite:database/members.db';
		$dbh = new PDO($dsn);
		// データベースを検索する
		$sql = "SELECT uid FROM members WHERE email= :email AND pass= :pass";
		// echo $sql, "<br />\n";
		$stmt = $dbh->prepare($sql);
		$stmt->execute(array(':email' => $email, ':pass' => $pass));
		// 検索結果を取得する
		$row = $stmt->fetch();
		// 検索結果の判定
		if ($row) {
			// ユーザ名の取得
			$uname = $row[0];
			// セッションへの登録
			$_SESSION['uname'] = $uname;
			// ホームページへリダイレクト
			header('Location: logged.php');
			exit();
		} else
			$msg.= "<p class='caution'>メールアドレスかパスワードに誤りがあります。</p>\n";
	}
} else {
	// GETメソッドの場合
	$email = "";
	$msg = "<p>ログインしてください。</p>\n";
}
?>
<!DOCTYPE html>
<html lang="ja">
<head>
<meta charset="utf-8">
<meta http-equiv="content-style-type" content="text/css">
<link rel="stylesheet" type="text/css" href="style/menu.css">
<LINK rel="SHORTCUT ICON" href="favicon.ico">
<title>ログイン</title>
</head>
<body>
<h2 class="titlem">欲しいものリスト</h2>
<form id="loginForm" method="post" action="" />
<p>メールアドレス<br />
  <input class="waku" type="text" name="email" value="<?php echo h($email); ?>" />
</p>
<p>パスワード<br />
  <input class="waku" type="password" name="pass" value="" />
</p>
<?php echo $msg; ?>
  <input class="submitb" type="submit" value="ログイン" />
</form>
</body>
</html>
