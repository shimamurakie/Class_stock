
package Ex012;


/************************************************************
 * 学籍番号をチェックするメソッド validate を作成せよ。
 *
 * ［機能］ 引数で与えられた文字列が学籍番号として正しいか判定する。
 * ただし、学籍番号は半角 nnECmmm の形式で、nn の部分は 00 から 17 までの 2 桁数字、
 * EC の部分は英字（小文字も可）、mmm の部分は 001 から 999 までの 3 桁数字とする。
 * ［形式］ public static boolean validate(String s)
 * ［引数］ s: 任意の長さの文字列
 * ［戻り値］ 学籍番号として正しい場合に true、正しくない場合に false
 * ［使用例］ boolean rt = validate("16Ec900");  // rt の値は true
 ************************************************************/

// TODO 必要に応じてパッケージをインポートすること

public class Ex012 {
    // TODO 学籍番号と氏名を設定すること

    private static String gakuban = "14EC063";
    private static String yourname = "島村貴衣";

    public static boolean validate(String s) {
        boolean tf =true;
        tf = s.matches("[01][0-9][Ee][Cc][0-9]{3}");
        if(s.matches("1[89].{5}"))
            tf=false;
       
        if(s.matches(".{4}000"))
            tf=false;

        return tf; 
    }

/************************************************************
 ************************************************************
 * 実装したメソッドのテストプログラム。ここから下は変更禁止!!
 * **********************************************************
 ************************************************************/
    private static String question = "Ex012";
    private static String method = "validate";

    // Execute test by comparing values Expected and Returned
    static void executeTest() {
        String[] param1 = { // Checkpoint 1
            "01ec123", "17Ec900", "18EC789", "11EC000", "12ec3456",};
        boolean[] expect = { // Checkpoint 2
            true, true, false, false, false,};
        System.out.printf("課題番号:%s, 学籍番号:%s, 氏名:%s\n",
                question, gakuban, yourname);
        int passed = 0;
        for (int i = 0; i < param1.length; i++) {
            String info1 = "", info2 = "";
            Exception ex = null;
            boolean returned = false; //3
            try {
                returned = validate(param1[i]); //4
                if (expect[i] == returned) { //5
                    info1 = "OK";
                    passed++;
                } else {
                    info1 = "NG";
                    info2 = String.format(" <= SHOULD BE %s", expect[i]);
                }
            } catch (Exception e) {
                info1 = "NG";
                info2 = "EXCEPTION!!";
                ex = e;
            } finally {
                String line = String.format("*** Test#%d %s %s(\"%s\") => ",
                        i + 1, info1, method, param1[i]);
                if (ex == null) {
                    System.out.println(line + returned + info2);
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
