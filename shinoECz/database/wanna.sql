BEGIN TRANSACTION;
CREATE TABLE wanna (
    num      VARCHAR (100) PRIMARY KEY,
    name     VARCHAR (100),
    price    INT (20),
    priority INT (20),
    entry    DATE,
    note     VARCHAR (100) 
);

INSERT INTO wanna VALUES ('45c7c7880d4d53a7e81255184d04bb17','独習PHP第3版',3200,1,'2016-04-09','いらないかも');
INSERT INTO wanna VALUES ('a403d252114f943d21b05d49fdd99e9c','初めてのPHP5増補改訂版',2900,4,'2012-09-24','そこまででもない');
INSERT INTO wanna VALUES ('f5285b34a850442373286ef63db1a252','スッキリわかるJava入門実践編',2800,8,'2014-09-21','わりと欲しい');
INSERT INTO wanna VALUES ('768499d6b5d184519facf33efbef78cb','明解Java入門編',2600,10,'2007-08-17','ほしい');

COMMIT;
