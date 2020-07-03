using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WindowsFormsApp1;

namespace Btc_project
{
    public partial class Add_new_row : Form
    {
        public Add_new_row()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Login_window.ConToDB.Open();
            MySqlCommand cmd = Login_window.ConToDB.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "CALL new_row('" + textBox1.Text + "','" + Login_window.Users_name + "','" + textBox2.Text + "')";//Делаем запрос на добавление строки
            cmd.ExecuteNonQuery();
            Login_window.ConToDB.Close();
        }
    }
}
