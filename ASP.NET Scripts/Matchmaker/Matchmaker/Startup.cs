using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(Matchmaker.Startup))]
namespace Matchmaker
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
