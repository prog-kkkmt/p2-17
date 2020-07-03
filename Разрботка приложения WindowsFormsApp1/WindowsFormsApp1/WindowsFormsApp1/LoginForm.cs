using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Login_window : Form
    {
        public static MySqlConnection ConToDB = new MySqlConnection("server=localhost;user id=root; password = ; database=bts_project");//формируем коннект
        public static string Users_name;
        int i;
        public Login_window()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            i = 0;
            ConToDB.Open();

            MySqlCommand cmd = ConToDB.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from Users_accounts where Users_name='" + Login_textBox.Text + "' and Users_password='" + Password_textBox.Text + "'";//Формируем запрос на поиск по полям логина и пароля
            //cmd.CommandText = "select * from Users_accounts where Users_name='Rt' and Users_password='123'";
            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            MySqlDataAdapter da = new MySqlDataAdapter(cmd);
            da.Fill(dt);
            i = Convert.ToInt32(dt.Rows.Count.ToString());//Переводим количество в int

            if (i == 0)
            {
                MessageBox.Show("Error");
                ConToDB.Close();
            }
            else 
            {
                //MessageBox.Show("Complete");
                ConToDB.Close();
                Users_name = Login_textBox.Text;//Запоминем логин 
                Form MainForm = new Btc_project.MainForm();
                MainForm.Left = this.Left; 
                MainForm.Top = this.Top; 
                MainForm.Show(); 
                this.Hide(); 
            }

        }
    }
}
