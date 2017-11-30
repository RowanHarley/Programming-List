using System;
using System.Collections.Generic;
using System.Net.WebSockets;
using System.Threading;
using System.Threading.Tasks;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Microsoft.Web.WebSockets;

namespace Matchmaker.Controllers
{
    public class Sockets2Controller : Controller
    {
        // GET: Sockets2
        public ActionResult Index()
        {
            return View();
        }
        public void ProcessRequest(HttpContext context)
        {
            if (context.IsWebSocketRequest)
            {
                context.AcceptWebSocketRequest(new MicrosoftWebSockets());
            }
        }
    }
}