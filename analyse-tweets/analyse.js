var timeArr = [];
var weekdays = [
  {"day": "Mon", "count": 0},
  {"day": "Tue", "count": 0},
  {"day": "Wed", "count": 0},
  {"day": "Thu", "count": 0},
  {"day": "Fri", "count": 0},
  {"day": "Sat", "count": 0},
  {"day": "Sun", "count": 0}
];
var months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"];

for(var i = 0; i < tweets.length; i++)
{
  timeArr.push(tweets[i].tweet.created_at);

  //weekdays
  for(var wd = 0; wd < weekdays.length; wd++)
  {
    if(timeArr[i].substring(0, 3) == weekdays[wd].day)
    {
      weekdays[wd].count++;
    }
  }

  var cDiv = document.getElementById("creation_Date");
  var nChild = document.createElement("p");
  nChild.innerHTML = timeArr[i];
  cDiv.appendChild(nChild);
}


