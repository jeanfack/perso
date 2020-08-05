using System;
//using System.Linq;
using System.Data.SQLite;

namespace T2S
{
    class Program
    {
        static string Version()
        {
            string cs = "Data Source=:memory:";
            string stm = "SELECT SQLITE_VERSION()";

            using var con = new SQLiteConnection(cs);
            con.Open();

            using var cmd = new SQLiteCommand(stm, con);
            string version = cmd.ExecuteScalar().ToString();

            return version;
        }

        static void Main(string[] args)
        {

            Console.WriteLine(Version());

            Console.WriteLine("Bye");
        }
    }
}
