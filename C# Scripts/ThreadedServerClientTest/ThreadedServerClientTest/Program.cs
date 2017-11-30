using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ThreadedServerClientTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Client[] clients = new Client[5];
            string[] payloads = new string[5]
            {
                "Hello",
                "Test1",
                "Test2",
                "Test3",
                "Test4"
            };
            for(int i = 0; i < clients.Length; i++)
            {
                clients[i] = new Client();
                clients[i].port = 5555;
                clients[i].ip = "127.0.0.1";
                clients[i].Connect();
            }
            for(int i = 0; i < clients.Length; i++)
            {
                string answer = clients[i].GetPayloadAnswer(payloads[i]);
                Console.WriteLine("Sent: '{0}'", payloads[i]);
                Console.WriteLine("Recieved: '{0}'", answer);
            }
            Console.ReadKey(true);
        } 
    }
}
