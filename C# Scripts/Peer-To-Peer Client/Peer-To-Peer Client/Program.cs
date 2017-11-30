using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.PeerToPeer;
using System.Text;
using System.Threading.Tasks;

namespace Peer_To_Peer_Client
{
    class Program
    {
        static void Main(string[] args)
        {
            // create a resolver object to resolve a peername
            PeerNameResolver resolver = new PeerNameResolver();
            // the peername to resolve must be passed as the first command line argument to the application
            PeerName peerName = new PeerName("3df33a18134282a04f56b887633e5a6640b7682e.RowansWebServer");
            // resolve the PeerName - this is a network operation and will block until the resolve completes
            PeerNameRecordCollection results = resolver.Resolve(peerName);

            // Display the data returned by the resolve operation
            Console.WriteLine("Results for PeerName: {0}", peerName);
            Console.WriteLine();
            int count = 1;
            foreach (PeerNameRecord record in results)
            {
                Console.WriteLine("Record #{0} results...", count);

                Console.Write("Comment:");
                if (record.Comment != null)
                {
                    Console.Write(record.Comment);
                }
                Console.WriteLine();

                Console.Write("Data:");
                if (record.Data != null)
                {
                    Console.Write(System.Text.Encoding.ASCII.GetString(record.Data));
                }
                Console.WriteLine();

                Console.WriteLine("Endpoints:");
                foreach (IPEndPoint endpoint in record.EndPointCollection)
                {
                    Console.WriteLine("\t Endpoint:{0}", endpoint);
                    Console.WriteLine();
                }

                count++;
            }

            Console.ReadKey();
        }
    }
}
