using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Chat_Client
{
    class Client
    {
        private string data;
        private readonly string name;

        public Client(string name, string ip)
        {
            this.name = name;

            byte[] bytes = new byte[1024];

            try
            {
                Socket sender = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                try
                {
                    sender.Connect(new IPEndPoint(IPAddress.Any, 11000));
                    sender.Send(Encoding.ASCII.GetBytes(name));

                    Console.WriteLine(name + ", you are now speaking with " + Encoding.ASCII.GetString(bytes, 0, sender.Receive(bytes)) + ".");

                    new Thread(ShowMessages).Start(sender);
                    new Thread(SendToClientMessages).Start(sender);
                }
                catch (ArgumentNullException ane)
                {
                    Console.WriteLine("ArgumentNullException : {0}", ane.ToString());
                }
                catch (SocketException se)
                {
                    Console.WriteLine("SocketException : {0}", se.ToString());
                }
                catch (Exception e)
                {
                    Console.WriteLine("Unexpected exception : {0}", e.ToString());
                }

            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
            Console.ReadKey();
        }

        private void ShowMessages(object h)
        {
            byte[] bytes = new byte[1024];
            Socket sender = (Socket)h;

            while (true)
            {
                try {
                    int bytesRec = sender.Receive(bytes);
                    data = Encoding.ASCII.GetString(bytes, 0, bytesRec);

                    if (!sender.Connected)
                    {
                        sender.Shutdown(SocketShutdown.Both);
                        sender.Close();
                        Environment.Exit(0);
                    }

                    Console.WriteLine(data);
                }
                catch(Exception e)
                {
                    Console.WriteLine("Unknown Exception: {0}", e.Message);
                    Console.ReadKey(true);
                    Environment.Exit(-1);
                }
            }
        }

        private void SendToClientMessages(object h)
        {
            Socket sender = (Socket)h;

            while (true)
            {
                string text = Console.ReadLine();

                if (text == null)
                    continue;

                if (text == "exit")
                {
                    sender.Shutdown(SocketShutdown.Both);
                    sender.Close();
                }

                byte[] msg = Encoding.ASCII.GetBytes(name + ": " + text);
                sender.Send(msg);
            }
        }
    }
}
