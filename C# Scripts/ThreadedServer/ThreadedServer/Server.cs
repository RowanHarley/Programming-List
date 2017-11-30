using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Net;
using System.Threading;

namespace ThreadedServer
{
    class Server
    {
        public int Port { get; set; }
        public TcpListener listener;
        private Thread listenerThread;

        public Server(int port)
        {
            this.Port = port;
        }

        public void Start()
        {
            listener = new TcpListener(new IPEndPoint(IPAddress.Any, Port));
            listener.Start();
            listenerThread = new Thread(new ThreadStart(Listener));
        }
        public void Stop()
        {
            listener.Stop();
            listenerThread.Abort();
        }
        private void Listener()
        {
            while (true)
            {
                try
                {
                    TcpClient c = listener.AcceptTcpClient();
                    new Thread(new ThreadStart(() => HandleClient(c))).Start();
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Error in listener thread!");
                    Console.WriteLine(ex.Message);
                }
            }
        }

        private void HandleClient(TcpClient client)
        {
            byte[] packetIDData = new byte[2];
            client.GetStream().Read(packetIDData, 0, 2);
            ushort packetID = BitConverter.ToUInt16(packetIDData, 0);
            Console.WriteLine("Packet ID recieved: {0}", packetID);
            switch (packetID)
            {
                case 0:
                    byte[] data = new byte[4];
                    client.GetStream().Read(data, 0, 4);
                    int length = BitConverter.ToInt32(data, 0);
                    data = new byte[length];
                    client.GetStream().Read(data, 0, length);
                    Console.WriteLine(Encoding.ASCII.GetString(data));
                    List<byte> backData = new List<byte>();
                    backData.AddRange(BitConverter.GetBytes((short)0));
                    string response = "successfully recieved data!";
                    backData.AddRange(BitConverter.GetBytes(Encoding.ASCII.GetByteCount(response)));
                    backData.AddRange(Encoding.ASCII.GetBytes(response));
                    client.GetStream().Write(backData.ToArray(), 0, backData.ToArray().Length);

                    break;
            }
            client.Close();

        }
    }
}
