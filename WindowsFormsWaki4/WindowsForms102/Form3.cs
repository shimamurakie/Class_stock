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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void comboBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                try
                {
                    // Uri の設定 
                    string nextUrl = comboBox1.Text;
                    // ナビゲート 
                    webBrowser1.Navigate(new Uri(nextUrl));
                }
                catch { }
            } 
        }

        private void webBrowser1_Navigated(object sender, WebBrowserNavigatedEventArgs e)
        {
            // コンボボックスのテキスト変更 
            comboBox1.Text = webBrowser1.Url.AbsoluteUri; 
        }

        private void homebtn_Click(object sender, EventArgs e)
        {
            this.Close();
        }

    }
}
