using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Chat
{
    class Server
    {
        private string data;
        private readonly string name;

        public Server(string name, string ip)
        {
            this.name = name;

            Socket listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            Console.WriteLine("Server created. Waiting for a connection...");

            try
            {
                byte[] bytes = new byte[1024];

                listener.Bind(new IPEndPoint(IPAddress.Any, 11000));
                listener.Listen(10);

                while (true)
                {

                    Socket handler = listener.Accept();
                    handler.Send(Encoding.ASCII.GetBytes(name));

                    Console.WriteLine(name + ", you are now speaking with " + Encoding.ASCII.GetString(bytes, 0, handler.Receive(bytes)) + ".");

                    new Thread(ShowMessages).Start(handler);
                    new Thread(SendToClientMessages).Start(handler);
                    break;
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }

            Console.Read();
        }

        private void ShowMessages(object h)
        {
            byte[] bytes = new byte[1024];
            Socket handler = (Socket)h;

            while (true)
            {
                try {
                    int bytesRec = handler.Receive(bytes);
                    data = Encoding.ASCII.GetString(bytes, 0, bytesRec);

                    if (!handler.Connected)
                    {
                        handler.Shutdown(SocketShutdown.Both);
                        handler.Close();
                        Environment.Exit(0);
                    }

                    Console.WriteLine(data);
                }
                catch (Exception e)
                {
                    Console.WriteLine("Unknown Exception: {0}", e.Message);
                    Environment.Exit(-1);
                }
            }
        }

        private void SendToClientMessages(object h)
        {
            Socket handler = (Socket)h;

            while (true)
            {
                string text = Console.ReadLine();

                if (text == null)
                    continue;

                if (text == "exit")
                {
                    handler.Shutdown(SocketShutdown.Both);
                    handler.Close();
                }

                byte[] msg = Encoding.ASCII.GetBytes(name + ": " + text);
                handler.Send(msg);
            }
        }
    }
}
