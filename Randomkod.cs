using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace KauSocialNetwork.Controllers
{
    public class FriendRequestController : Controller
    {
        // GET: FriendRequest
        public ActionResult Index(int id)
        {
            DAL.DatabaseContext db = new DAL.DatabaseContext();
            var q = from u in db.Users where u.UserID == id select u;
            var loggedinuser = (Models.User)Session["user"];
            var sendingrecs = new Models.FriendRequests();
            sendingrecs.user1 = loggedinuser.UserID;
            sendingrecs.user2 = ((Models.User)q.First()).UserID;

            loggedinuser.Requests.Add(sendingrecs);
            db.FriendRequests.Add(sendingrecs);
            Session["user"] = loggedinuser;
            return RedirectToAction("Show", controllerName:"User");
        }
    }
}
