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
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }

        private void homebtn_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label1_DoubleClick(object sender, EventArgs e)
        {
            MessageBox.Show("弊社製品をご利用いただきありがとうございます。\n今後とも変わらずご愛顧のほどよろしくお願いいたします。", "TOTO北千住店");
        }

        private void label3_DoubleClick(object sender, EventArgs e)
        {
            MessageBox.Show("ご登録いただきありがとうございます。\n登録を完了するには、このリンクよりメールアドレスの確認をしてください。\nメールの確認\n今後とも変わらずご愛顧のほどよろしくお願いいたします。", "エイトプリンス清瀬店");
        }

        private void label5_DoubleClick(object sender, EventArgs e)
        {
            MessageBox.Show("(****@***.**.**): ***.***.***.*** \ndoes not like recipient.Remote host said: 550 \nInvalid recipient:(****@***.**.**):Giving up on ***.***.***.***.", "MAILER-DAEMON");
        }
    }
}
