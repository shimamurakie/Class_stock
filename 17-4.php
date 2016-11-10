<?php

// 誤った実装
function comparison($a, $b) {
  if ( false == strpos($a, $b) ) {
    echo "'{$a}'の中に'{$b}'は含まれていません<br>\n";
  } else {
    echo "'{$a}'の中に'{$b}'は含まれています<br>\n";
  }
}
// 正しい実装
function comparison_correct($a, $b) {
  if ( false === strpos($a, $b) ) {
    echo "'{$a}'の中に'{$b}'は含まれていません<br>\n";
  } else {
    echo "'{$a}'の中に'{$b}'は含まれています<br>\n";
  }
}



//
echo "call comparison<br>\n";
comparison('abcdefg', 'd');
comparison('abcdefg', 'z');
comparison('abcdefg', 'a');
echo "\n";
//
echo "call comparison_correct<br>\n";
comparison_correct('abcdefg', 'd');
comparison_correct('abcdefg', 'z');
comparison_correct('abcdefg', 'a');
