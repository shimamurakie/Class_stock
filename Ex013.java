
package Ex013;


/************************************************************
 * 文字列中の単語を取り出すメソッド extract を作成せよ。
 *
 * ［機能］ 文字列中に含まれるすべての単語を順に取り出して、文字列の配列として返却する。
 * ただし、単語はスペースで区切られた英数字からなる文字列とする
 * （英数字以外の文字はすべて削除すること）。
 * ［形式］ public static String[] extract(String s)
 * ［引数］ s: 任意の長さの文字列
 * ［戻り値］ 単語の配列
 * ［使用例］ String[] rt = extract("Yes, we can.");
 * // rt の値は {"Yes", "we", "can"}
 ************************************************************/

// TODO 必要に応じてパッケージをインポートすること
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Ex013 {
    // TODO 学籍番号と氏名を設定すること

    private static String gakuban = "14EC063";
    private static String yourname = "島村貴衣";

    public static String[] extract(String s) {
        String[] words;
        String[] nw;
        int i=0;
        words = s.split("[\\s]+");
        nw=words;
for(String wo : words){
    nw[i]= wo.replaceAll("[^a-zA-Z0-9]", "") ;
    i++;
}

List<String> list =new ArrayList<>(Arrays.asList(nw));
list.remove("");
String[] tmpw = (String[])list.toArray(new String[list.size()]);

        return tmpw; // もし必要なければこの行を削除すること
    }

/************************************************************
 ************************************************************
 * 実装したメソッドのテストプログラム。ここから下は変更禁止!!
 ************************************************************
 ************************************************************/
    private static String question = "Ex013";
    private static String method = "extract";

    // Execute test by comparing values Expected and Returned
    static void executeTest() {
        String[] param1 = { // Checkpoint 1
            "ab cd", "Yes, we can.", "Jan. 1, 2017", "Hello world <->",
            "Java Platform, Standard Edition (Java SE)",};
        String[][] expect = { // Checkpoint 2
            {"ab", "cd"}, {"Yes", "we", "can"}, {"Jan", "1", "2017"},
            {"Hello", "world"},
            {"Java", "Platform", "Standard", "Edition", "Java", "SE"},};
        System.out.printf("課題番号:%s, 学籍番号:%s, 氏名:%s\n",
                question, gakuban, yourname);
        int passed = 0;
        for (int i = 0; i < param1.length; i++) {
            String info1 = "", info2 = "";
            Exception ex = null;
            String[] returned = null; //3
            try {
                returned = extract(param1[i]); //4
                if (Arrays.equals(expect[i], returned)) { //5
                    info1 = "OK";
                    passed++;
                } else {
                    info1 = "NG";
                    info2 = String.format(" <= SHOULD BE %s", 
                            Arrays.toString(expect[i]));
                }
            } catch (Exception e) {
                info1 = "NG";
                info2 = "EXCEPTION!!";
                ex = e;
           } finally {
                String line = String.format("*** Test#%d %s %s(\"%s\") => ",
                    i + 1, info1, method, param1[i]);
                if (ex == null) {
                    System.out.println(line + Arrays.toString(returned) + info2);
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

