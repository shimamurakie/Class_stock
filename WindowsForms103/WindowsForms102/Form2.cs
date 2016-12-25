using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsForms102
{
    public partial class Form2 : Form
    {
        private bool init_flag = true; //  計算終了後の初期化フラグ

        public Form2()
        {
            InitializeComponent();
        }

        //  数値ボタン
        private void btnNumber_Click(object sender, EventArgs e)
        {
            textBoxCalc.Text += ((Button)sender).Text;
        }
        //  演算子ボタン
        private void Op_Click(object sender, EventArgs e)
        {
            textBoxCalc.Text += ((Button)sender).Text;
        }

        //  小数点ボタン
        private void point_Click(object sender, EventArgs e)
        {
            textBoxCalc.Text += '.';
        }

        //  クリア(C)ボタン
        private void Clear_Click(object sender, EventArgs e)  //  式の初期化
        {
            textBoxCalc.Text = String.Empty;
            init_flag = true;
        }

        private void eq_Click(object sender, EventArgs e)  //  式の計算を行う
        {
            int next_op_pos = 0;
            int before_op_pos = 0;
            char ch = ' ';
            char next_op = ' ';
            char before_op = ' ';
            string num = string.Empty;
            double left=0.0; //演算子で式を分けた時の左と右の数値
            double right = 0.0;
            double result = 0.0;
            bool calc_flag = true;  //  計算したかどうかのフラグ
            bool op_flag = true;  //  取得した

            textBoxCalc.Text += '=';

            // フォームに何も入れずに"="を押した場合
            if(textBoxCalc.Text == "")
            {
                MessageBox.Show("式を入力してください。",
                    "入力エラー", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if (init_flag == false)//計算終了後に=を押したときの対策
                return;

            for (int i = 0; i < textBoxCalc.Text.Length;i++) //フォームから1文字ずつ読みだす
            {
                ch = textBoxCalc.Text[i];
                if (Char.IsDigit(ch) == true || ch == '.') //数値もしくは小数点の場合
                {
                    num += ch;    //数値のコピーをとっておく
                }
                else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')//いずれかの演算子の場合
                {
                    if (ch != '=')
                    {
                        if (op_flag == true) //  演算子の場合
                        {
                            before_op_pos = i;
                            before_op = ch;
                            op_flag = false;
                        }
                        else
                        {
                            next_op_pos = i;
                            next_op = ch;
                        }

                    }

                    if (calc_flag)
                    {
                        left = double.Parse(textBoxCalc.Text.Substring(0, num.Length));//初回の計算のみleftを取得
                        calc_flag = false;
                        num = string.Empty; 
                    }
                    //  2回目以降の計算
                    else
                    {
                        right = double.Parse(textBoxCalc.Text.Substring(before_op_pos + 1, num.Length));
                        result = calc(left, right, before_op);
                        left = result;
                        num = string.Empty;
                        op_flag = true;
                        before_op_pos = next_op_pos;
                        before_op = next_op;

                    }
                }
                else
                    return;               
            }
            textBoxCalc.Text = result.ToString();
            init_flag = false;
            calc_flag = true;

        }
        //  計算用メソッド
        private double calc(double x, double y, char op)
        {
            double ans = 0.0;
            switch (op)
            {
                case '+':
                    ans = x + y;
                    break;
                case '-':
                    ans = x - y;
                    break;
                case '*':
                    ans = x * y;
                    break;
                case '/':
                    ans = x / y;
                    break;
            }
            return ans;
        }

        private void home_Click(object sender, EventArgs e)
        {
            this.Close();
        }        

    }
}
