using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;
using WindowsFormsApp1;

namespace Btc_project
{
    public partial class HistoryTransactions : Form
    {
        public HistoryTransactions()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)//Функция открытия MainForm
        {
            Form MainForm = Application.OpenForms[1];
            MainForm.StartPosition = FormStartPosition.Manual;
            MainForm.Left = this.Left;
            MainForm.Top = this.Top;
            MainForm.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)//Заполнение таблицы
        {
            try
            {
                Login_window.ConToDB.Open();
                MySqlDataAdapter SDA = new MySqlDataAdapter("SELECT * FROM history_transactions where User_name = '" + Login_window.Users_name + "';", Login_window.ConToDB);//Формируем запрос на поиск по полям логина
                DataTable DATA = new DataTable();
                SDA.Fill(DATA);
                dataGridView1.DataSource = DATA;

                Login_window.ConToDB.Close();
            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.Message);
            }
            finally
            {
                Login_window.ConToDB.Close();
            }

        }
    }
}
