using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Chat
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("What is your name? ");
            string name = Console.ReadLine();
            Server server = new Server(name, "94.230.101.183");
        }
    }
}
