<?php
function h($s) {
  return htmlspecialchars($s, ENT_QUOTES, 'UTF-8');
}



$text = h($_POST['data']);
$array = explode("\n", $text); // �Ƃ肠�����s�ɕ���
$array = array_map('trim', $array); // �e�s��trim()��������
$array = array_filter($array, 'strlen'); // ��������0�̍s����菜��
$array = array_values($array); // ����̓L�[��A�ԂɐU��Ȃ����Ă邾��

$b = explode(",",$array[1]);

var_dump($array);
echo '<br>';
var_dump($b);

?>