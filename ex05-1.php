<?php
function h($s) {
  return htmlspecialchars($s, ENT_QUOTES, 'UTF-8');
}


$i=0;
$arr2= array('T1');
$text = h($_POST['data']);
$array = explode("\n", $text); // �Ƃ肠�����s�ɕ���
$array = array_map('trim', $array); // �e�s��trim()��������
$array = array_filter($array, 'strlen'); // ��������0�̍s����菜��
$array = array_values($array); // ����̓L�[��A�ԂɐU��Ȃ����Ă邾��
while(true){
	if(isset($array[$i])==false)break;
$arr1 = explode(",",$array[$i]);
//print_r($arr1);
array_push($arr2,$arr1);
//if(isset($array[$i])==false)break;
$i ++;
}
unset($arr2[0]);
print_r($arr2);
echo '<br>';
//var_dump($arr1);
echo '<br>';
//var_dump($arr2);
echo "<table border='1'>";
foreach ($arr2 as $row) {
    echo "<tr>";
    foreach ($row as $val) // �l�X�g���ꂽforeach
        echo "<td>$val</td>";
    echo "</tr>";
}
echo "</table>";

?>