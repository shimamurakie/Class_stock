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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            //Form2クラスのインスタンスを作成する
            Form3 f = new Form3();
            //Form2を表示する
            //ここではモーダルダイアログボックスとして表示する
            //オーナーウィンドウにthisを指定する
            f.ShowDialog(this);
            //フォームが必要なくなったところで、Disposeを呼び出す
            f.Dispose();
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            //Form2クラスのインスタンスを作成する
            Form4 f = new Form4();
            //Form2を表示する
            //ここではモーダルダイアログボックスとして表示する
            //オーナーウィンドウにthisを指定する
            f.ShowDialog(this);
            //フォームが必要なくなったところで、Disposeを呼び出す
            f.Dispose();
        }

        private void label2_Click(object sender, EventArgs e)
        {
        }


        private void btn3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("時計ボタンが押されました", "iPone6ss");
        }

        private void btn4_Click(object sender, EventArgs e)
        {
            //Form2クラスのインスタンスを作成する
            Form5 f = new Form5();
            //Form2を表示する
            //ここではモーダルダイアログボックスとして表示する
            //オーナーウィンドウにthisを指定する
            f.ShowDialog(this);
            //フォームが必要なくなったところで、Disposeを呼び出す
            f.Dispose();
        }

        private void btn5_Click(object sender, EventArgs e)
        {
            MessageBox.Show("電話ボタンが押されました", "iPone6ss");
        }

        private void btn6_Click(object sender, EventArgs e)
        {
            MessageBox.Show("ミュージックボタンが押されました", "iPone6ss");
        }

        private void btn7_Click(object sender, EventArgs e)
        {
            MessageBox.Show("マップボタンが押されました", "iPone6ss");
        }

        private void btn8_Click(object sender, EventArgs e)
        {
            MessageBox.Show("メールボタンが押されました", "iPone6ss");
        }

        private void btn9_Click(object sender, EventArgs e)
        {
            MessageBox.Show("設定ボタンが押されました", "iPone6ss");
        }

        private void btn10_Click(object sender, EventArgs e)
        {
            MessageBox.Show("写真ボタンが押されました", "iPone6ss");
        }

        private void btn11_Click(object sender, EventArgs e)
        {
            MessageBox.Show("天気ボタンが押されました", "iPone6ss");
        }

        private void btn12_Click(object sender, EventArgs e)
        {
            //Form2クラスのインスタンスを作成する
            Form2 f = new Form2();
            //Form2を表示する
            //ここではモーダルダイアログボックスとして表示する
            //オーナーウィンドウにthisを指定する
            f.ShowDialog(this);
            //フォームが必要なくなったところで、Disposeを呼び出す
            f.Dispose();
        }

        private void homebtn_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
