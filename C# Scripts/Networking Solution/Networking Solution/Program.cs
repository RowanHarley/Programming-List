using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace Networking_Solution
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] test = { "Test1", "Test2", "Test3" };
            Network n = new Network();
            byte[] testByte = n.ConvertStringArrayToByte(test);
            Console.WriteLine(testByte);
            n.ConvertByteStringArrayToArray(testByte);

        }
    }
}
