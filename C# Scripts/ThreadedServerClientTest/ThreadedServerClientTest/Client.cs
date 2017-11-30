using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace ThreadedServerClientTest
{
    public class Client
    {
        public int port;
        public string ip;
        private TcpClient client;

        public void Connect()
        {
            client = new TcpClient();
            client.Connect(ip, port);
            Console.WriteLine("Successfully Connected to IP: {0} and Port: {1}", ip, port);
        }

        public string GetPayloadAnswer(string payload)
        {
            List<byte> payloadData = new List<byte>();
            payloadData.AddRange(BitConverter.GetBytes((short)0));
            payloadData.AddRange(MakeString(payload));
            client.GetStream().Write(payloadData.ToArray(), 0, payloadData.Count);
            client.GetStream().Read(new byte[2], 0, 2);
            string ans = ReadString(client);

            Console.WriteLine("Successfully got payload answer!");

            return ans;
        }
        private byte[] MakeInt(int i)
        {
            return BitConverter.GetBytes(i);
        }
        private byte[] MakeString(string input)
        {
            List<byte> data = new List<byte>();

            data.AddRange(MakeInt(Encoding.ASCII.GetByteCount(input)));
            data.AddRange(Encoding.ASCII.GetBytes(input));
            return data.ToArray();
        }

        private int ReadInt(TcpClient client)
        {
            byte[] data = new byte[4];
            client.GetStream().Read(data, 0, 4);
            return BitConverter.ToInt32(data, 0);
        }

        private string ReadString(TcpClient client)
        {
            byte[] data = new byte[ReadInt(client)];
            client.GetStream().Read(data, 0, data.Length);
            return Encoding.ASCII.GetString(data);
        }
    }
}
