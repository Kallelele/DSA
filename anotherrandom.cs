using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace KauSocialNetwork.Models
{
    public class FriendRequests
    {
        public int FriendRequestsID {get; set;}
        public int user1 { get; set; }
        public int user2 { get; set; }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace KauSocialNetwork.Controllers
{
    public class FriendController : Controller
    {
        // GET: Friend
        public ActionResult Index(int id)
        {
            DAL.DatabaseContext db = new DAL.DatabaseContext();
            var loggedinuser = (Models.User)Session["user"];
            var friendq = from u in db.Users where u.UserID == id select u;
            var friend = (Models.User)friendq.First();
            var q = from u in db.FriendRequests where loggedinuser.UserID == u.user2 && id==u.user1 select u;

            if (q.Count() > 0)
            {
                loggedinuser.Friends.Add(friend);
                friend.Friends.Add(loggedinuser);
                friend.Requests.Remove(q.First());
                db.Users.Add(loggedinuser);
                db.Users.Add(friend);
                Session["user"] = loggedinuser;
            }
            return View();
        }
    }
}
