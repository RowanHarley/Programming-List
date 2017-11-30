using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace Networking_Solution
{
    class Network
    {
        UdpClient udp = null;
        public Exception JoinMulticastException()
        {
            return new Exception("Looks like you've tryed to join a multicast group before connecting! Use the Connect() statement before trying this!");
        }
        public void Connect(string ip,int port)
        {
            try {
                udp = new UdpClient(ip,port);
                Console.WriteLine("Server started!");
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error in Connect(int port) . Error Message: " + ex.ToString());
                Console.ReadKey();
            }
        }
        public void JoinMulticastGroup(string ip)
        {
            if(udp != null)
            {
                IPAddress ipAddr = IPAddress.Parse(ip);
                udp.JoinMulticastGroup(ipAddr);
                IPEndPoint ep = null;
            }
            else
            {
                throw JoinMulticastException();
            }
        }
        public byte[] ConvertStringArrayToByte(string[] array)
        {
            BinaryFormatter bf = new BinaryFormatter();
            using (MemoryStream ms = new MemoryStream())
            {
                bf.Serialize(ms, array);
                return ms.ToArray();
            }
        }
        public void ConvertByteStringArrayToArray(byte[] array)
        {
            string arraySerialized = Encoding.ASCII.GetString(array);
            Console.WriteLine(arraySerialized);
           
            //BinaryFormatter bf = new BinaryFormatter();
            //using (MemoryStream ms = new MemoryStream())
            //{
            //    bf.Deserialize(ar)
            //}

            //    bf.Deserialize();
        }

    }
}
