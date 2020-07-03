using System;
using System.Windows.Forms;

namespace Btc_project
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            /*
            WebBrowser tmpWeb = new WebBrowser();
            tmpWeb.Navigate("http://www.microsoft.com");
            this.Controls.Add(tmpWeb);
            tmpWeb.Dock = DockStyle.Fill;*/
        }

        private void button4_Click(object sender, EventArgs e)//Функция открытия LoginForm
        {
            Form LoginForm = Application.OpenForms[0];
            LoginForm.StartPosition = FormStartPosition.Manual;
            LoginForm.Left = this.Left;
            LoginForm.Top = this.Top;
            LoginForm.Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)//Функция открытия HistoryTransactions
        {
            Form HistoryTransactions = new Btc_project.HistoryTransactions();
            HistoryTransactions.Left = this.Left;
            HistoryTransactions.Top = this.Top;
            HistoryTransactions.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)//Функция открытия Purse_form
        {
            Form Purse_form = new Btc_project.Purse_form();
            Purse_form.Left = this.Left;
            Purse_form.Top = this.Top;
            Purse_form.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)//Функция открытия Requisites
        {
            Form Requisites = new Btc_project.Requisites();
            Requisites.Left = this.Left;
            Requisites.Top = this.Top;
            Requisites.Show();
            this.Hide();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            //this.webBrowser1.Navigate("http://www.microsoft.com");

        }
    }
}
    

