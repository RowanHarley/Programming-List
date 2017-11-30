using System;
using System.Net.Sockets;
using System.Threading;
public class Client
{
    static public void Main(string[] Args)
    {
        TcpClient socketForServer;
        string ip = "192.168.0.100";
        int port = 3333;
        try
        {
            socketForServer = new TcpClient(ip, port);
        }
        catch
        {
            Console.WriteLine(
            "Failed to connect to server at {0}:{1}", ip,port);
            Console.ReadKey();
            return;
        }

        NetworkStream networkStream = socketForServer.GetStream();
        System.IO.StreamReader streamReader =
        new System.IO.StreamReader(networkStream);
        System.IO.StreamWriter streamWriter =
        new System.IO.StreamWriter(networkStream);
        Console.WriteLine("*******This is client program who is connected to {0} on port No:{1}", ip, port);

        try
        {
            string outputString;
            // read the data from the host and display it
            {
                //outputString = streamReader.ReadLine();
                //Console.WriteLine("Message Recieved by server:" + outputString);

                //Console.WriteLine("Type your message to be recieved by server:");

                
                Console.WriteLine("type: ");
                string str = Console.ReadLine();
                while (str != "exit")
                {
                    streamReader.ReadLine();
                    streamWriter.WriteLine(str);
                    streamWriter.Flush();
                    Console.WriteLine("type: ");
                    str = Console.ReadLine();
                }
                if (str == "exit")
                {
                    streamWriter.WriteLine(str);
                    streamWriter.Flush();

                }

            }
        }
        catch
        {
            Console.WriteLine("Exception reading from Server");
        }
        // tidy up
        networkStream.Close();
        Console.WriteLine("Press any key to exit from client program");
        Console.ReadKey();
    }

    private static string GetData()
    {
        //Ack from sql server
        return "ack";
    }
}
