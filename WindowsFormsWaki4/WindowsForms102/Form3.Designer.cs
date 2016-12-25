namespace WindowsForms102
{
    partial class Form3
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form3));
            this.homebtn = new System.Windows.Forms.Button();
            this.webBrowser1 = new System.Windows.Forms.WebBrowser();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // homebtn
            // 
            this.homebtn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("homebtn.BackgroundImage")));
            this.homebtn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.homebtn.FlatAppearance.BorderSize = 0;
            this.homebtn.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.homebtn.Location = new System.Drawing.Point(121, 579);
            this.homebtn.Name = "homebtn";
            this.homebtn.Size = new System.Drawing.Size(74, 60);
            this.homebtn.TabIndex = 0;
            this.homebtn.UseVisualStyleBackColor = true;
            this.homebtn.Click += new System.EventHandler(this.homebtn_Click);
            // 
            // webBrowser1
            // 
            this.webBrowser1.Location = new System.Drawing.Point(25, 97);
            this.webBrowser1.MinimumSize = new System.Drawing.Size(20, 20);
            this.webBrowser1.Name = "webBrowser1";
            this.webBrowser1.Size = new System.Drawing.Size(284, 476);
            this.webBrowser1.TabIndex = 1;
            this.webBrowser1.Navigated += new System.Windows.Forms.WebBrowserNavigatedEventHandler(this.webBrowser1_Navigated);
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(25, 78);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(284, 20);
            this.comboBox1.TabIndex = 2;
            this.comboBox1.KeyDown += new System.Windows.Forms.KeyEventHandler(this.comboBox1_KeyDown);
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(334, 651);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.webBrowser1);
            this.Controls.Add(this.homebtn);
            this.Name = "Form3";
            this.Text = "Form3";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button homebtn;
        private System.Windows.Forms.WebBrowser webBrowser1;
        private System.Windows.Forms.ComboBox comboBox1;
    }
}