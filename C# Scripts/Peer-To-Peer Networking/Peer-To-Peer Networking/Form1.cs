using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.PeerToPeer;
using System.Net.PeerToPeer.Collaboration;
namespace Peer_To_Peer_Networking
{
    public partial class Form1 : Form, IQuickReturnTraderChat
    {
        [ServiceContract()]
        public interface IQuickReturnTraderChat
        {
            [OperationContract(IsOneWay = true)]
            void Say(string user, string message);
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }
    }
}
