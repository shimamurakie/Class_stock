<?php

// 出したい広告を配列で所持しておく
$ads = array (
  '<a href="http://web.dendai.ac.jp/special2017/"><img src="http://atom.dendai.ac.jp/albums/abm00016979.png"></a>',
  '<a href="http://web.dendai.ac.jp/department/mirai/architecture.html"><img src="http://atom.dendai.ac.jp/albums/abm00017129.jpg"></a>',
  '<a href="http://web.dendai.ac.jp/about/gakuji/homecoming/program.html"><img src="http://atom.dendai.ac.jp/albums/abm00017540.jpg"></a>',
  '<a href="http://web.dendai.ac.jp/about/mission/"><img src="http://atom.dendai.ac.jp/albums/abm00001219.jpg"></a>',
);

// ランダムに1つを選んで出力する
echo $ads[ mt_rand(0, count($ads) - 1) ];
