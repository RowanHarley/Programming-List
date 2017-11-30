using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ThreadedServer
{
    class Program
    {
        static void Main(string[] args)
        {
            int port = 5555;
            Server server = new Server(port);
            server.Start();
            Console.WriteLine("Server Started on port {0}", port);
            Console.WriteLine("Press [Q] to Stop Server");
            while (true)
            {
                ConsoleKeyInfo c = Console.ReadKey(true);
                if(c.Key == ConsoleKey.Q)
                {
                    Console.WriteLine("Closing Down Server...");
                    server.Stop();
                    return;
                }
            }
        }
    }
}
