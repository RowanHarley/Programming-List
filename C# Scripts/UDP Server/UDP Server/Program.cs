using System;
using System.Text;
using System.Net.Sockets;
using System.Net;
using System.Collections;

namespace UDP_Server
{
    class Program
    {
        struct ClientInfo
        {
            //Socket of the client
            public EndPoint endpoint;
            //Name by which the user logged into the chat room
            public string strName;
        }
        static void Main(string[] args)
        {
            //The collection of all clients logged into 
            //the room (an array of type ClientInfo)
            ArrayList clientList;

            //The main socket on which the server listens to the clients
            Socket serverSocket;

            byte[] byteData = new byte[1024];
        }
    }
}