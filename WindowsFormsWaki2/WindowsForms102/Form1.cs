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
            MessageBox.Show("ぼくは短気でね。\n帰ってもらうよ。", "Hideyo");
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("何で帰っちゃうの！？", "Hideyo");
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            MessageBox.Show("受け取りません", "Hideyo");
        }

        private void btn3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("お酒をください", "Hideyo");
        }

        private void btn4_Click(object sender, EventArgs e)
        {
            MessageBox.Show("お酒をください...", "Hideyo");
        }

        private void btn5_Click(object sender, EventArgs e)
        {

        }

        private void btn6_Click(object sender, EventArgs e)
        {

        }

        private void btn7_Click(object sender, EventArgs e)
        {

        }

        private void btn8_Click(object sender, EventArgs e)
        {

        }

        private void btn9_Click(object sender, EventArgs e)
        {

        }

        private void btn10_Click(object sender, EventArgs e)
        {

        }

        private void btn11_Click(object sender, EventArgs e)
        {

        }

        private void btn12_Click(object sender, EventArgs e)
        {
            MessageBox.Show("お酒をください!!", "Hideyo");
        }

        private void homebtn_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
