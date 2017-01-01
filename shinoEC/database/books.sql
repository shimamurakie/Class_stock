BEGIN TRANSACTION;
CREATE TABLE books (
  isbn VARCHAR(17) PRIMARY KEY,
  title VARCHAR(100),
  price INT(11),
  publish VARCHA(30),
  published date
);
INSERT INTO books VALUES ('978-4797339536','明解Java入門編',2600,'ソフトバンククリエイティブ','2007-08-17');
INSERT INTO books VALUES ('978-4844336778','スッキリわかるJava入門実践編',2800,'インプレス','2014-09-21');
INSERT INTO books VALUES ('978-4873115801','初めてのPHP5増補改訂版',2900,'オライリージャパン','2012-09-24');
INSERT INTO books VALUES ('978-4798135472','独習PHP第3版',3200,'翔泳社','2016-04-09');
COMMIT;
