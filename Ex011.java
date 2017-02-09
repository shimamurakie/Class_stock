package Ex011;


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this temp
/************************************************************
 * 文字列を変換するメソッド normalize を作成せよ。
 * ［機能］ 文字列中のすべての英小文字を英大文字に変換し、さらに前後の空白を除去する。
 * ［形式］ public static String normalize(String s)
 * ［引数］ s: 任意の長さの文字列
 * ［戻り値］ 変換後の文字列
 * ［使用例］ String rt = normalize(" Java 8 ");  // rt の値は "Java 8" ************************************************************/

// TODO 必要に応じてパッケージをインポートすること

public class Ex011 {
    // TODO 学籍番号と氏名を設定すること
    private static String gakuban = "14EC063";
    private static String yourname = "島村貴衣";

    public static String normalize(String s) {
String ns= s.toUpperCase();
String es= ns.trim();

        return es; // もし必要なければこの行を削除すること
    }

/************************************************************
 ************************************************************
 * 実装したメソッドのテストプログラム。ここから下は変更禁止!!
 ************************************************************
 ************************************************************/
    private static String question = "Ex011";
    private static String method = "normalize";

    // Execute test by comparing values Expected and Returned
    static void executeTest() {
        String[] param1 = { // Checkpoint 1
            "abc", " Java 8 ", "  $99.99 usd", "ノートpc", "",};
        String[] expect = { // Checkpoint 2
            "ABC", "JAVA 8", "$99.99 USD", "ノートPC", "",};
        System.out.printf("課題番号:%s, 学籍番号:%s, 氏名:%s\n",
                question, gakuban, yourname);
        int passed = 0;
        for (int i = 0; i < param1.length; i++) {
            String info1 = "", info2 = "";
            Exception ex = null;
            String returned = ""; //3
            try {
                returned = normalize(param1[i]); //4
                if (expect[i].equals(returned)) { //5
                    info1 = "OK";
                    passed++;
                } else {
                    info1 = "NG";
                    info2 = String.format(" <= SHOULD BE \"%s\"", expect[i]);
                }
            } catch (Exception e) {
                info1 = "NG";
                info2 = "EXCEPTION!!";
                ex = e;
            } finally {
                String line = String.format("*** Test#%d %s %s(\"%s\") => ",
                        i + 1, info1, method, param1[i]);
                if (ex == null) {
                    System.out.println(line + "\"" + returned + "\""+ info2);
                } else {
                    System.out.println(line + info2);
                    ex.printStackTrace();
                    return;
                }
            }
        }
        System.out.printf("Summary: %s,%s,%s,%d/%d\n",
                question, gakuban, yourname, passed, param1.length);
    }

    // Main method
    public static void main(String[] args) {
        gakuban = gakuban.toUpperCase();
        if (!gakuban.matches("[1][0-9]EC[0-9]{3}")) {
            System.out.println("ERROR! 学籍番号に誤りがあります。");
        } else if (yourname.contains("千住")) {
            System.out.println("ERROR! 氏名に誤りがあります。");
        } else {
            executeTest();
        }
    }
}
