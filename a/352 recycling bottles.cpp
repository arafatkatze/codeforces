#include <bits/stdc++.h>
using namespace std;
#define INF                         (int)1e9
#define bitcount                    __builtin_popcount  // counts 1 eg- 1101 has value 3
 
/* 
   const clock_t begin_time = clock();
   // do something
   cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
*/

/*
 Read from a file
 freopen("input.in","r",stdin);
 freopen("output.out","w",stdout);
*/   
void read(){};
template<typename T,typename... Args>
void read(T &a, Args&... args) {  cin>>a ; read(args...); }
void print(){cout <<"\n";};
template<typename T,typename... Args>
void print(T &a, Args&... args) {  cout << a << " "  ; print(args...); }
template<class T> T gcd(T a, T b) { return a ? gcd (b % a, a) : b; }
 
 
 
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
 
vector<string> split(const string& s, char c) {
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c)) v.emplace_back(x);
    return move(v);
}
 
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
    cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
    err(++it, args...);
}
 
 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// Useful container manipulation / traversal macros
#define fa(i, begin, end)           for (auto i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fe(v, c)                    for(auto v :c)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          emplace_back  // this will work almost always
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((auto)(a.size()))
#define mp                          make_pair
// comparision Guys 
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end()) //deletes repeat
#define sqr(x)                       ((x) * (x))
#define sqrt(x)                       sqrt(abs(x))
// The bit standard guys
#define bit(x,i)                    (x&(1<<i))  //select the bit of position i of x
#define lowbit(x)                   ((x)&((x)^((x)-1))) //get the lowest bit of x
#define higbit(x)                   (1 << ( auto) log2(x) )
#define what_is(x) cerr << #x << " is " << x << endl;
 
// The vectors and pairs
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int>pa;
#define ft                 first
#define sd                 second
#define pq                 priority_queue
// the data types
#define ll unsigned long long
#define st string
#define ld long double
typedef complex<double> point;
point points[100000];
int main() {
  point adil, bera, bin;
  double a, b, c, d, e , f, dist, d2;
  cin >> a >> b >> c >> d >> e >> f;
  adil = {a, b};
  bera = {c, d};
  bin =  {e, f};
  int test, farthestbin = 0;
  f = 0;
  cin >> test;
  dist = 1e18;
  fa(i, 0 ,test)
  {
     cin >> a >> b; points[i] = {a, b};
     f += 2*abs(points[i]-bin);
  } 
  // case 1
  d = 1e18;
  fa(i,0,test)d = min(d, f - abs(points[i]-bin) + abs(points[i]-adil));
  dist = min(d,dist);
  // case 2
  fa(i,0,test)d = min(d, f - abs(points[i]-bin) + abs(points[i]-bera));
  dist = min(d,dist);
  // case 3 a
  farthestbin = 0;
  d = 1e18;
  fa(i,0,test)
  {
    if (d > f - abs(points[i]-bin) + abs(points[i]-adil))
      {d = min(d, f - abs(points[i]-bin) + abs(points[i]-adil)); farthestbin = i;};
  }
  d2 = d;
  fa(i,0,test)
  {
    if (i!=farthestbin)
    if (d > d2 - abs(points[i]-bin) + abs(points[i]-bera))
      {d = min(d, d2 - abs(points[i]-bin) + abs(points[i]-bera));};
  }
  dist = min(d,dist);
  // cas 3 b
  farthestbin = 0;
  d = 1e18;
  fa(i,0,test)
  {
    if (d > f - abs(points[i]-bin) + abs(points[i]-bera))
      {d = min(d, f - abs(points[i]-bin) + abs(points[i]-bera)); farthestbin = i;};
  }
  d2 = d;
  fa(i,0,test)
  {
    if (i!=farthestbin)
    if (d > d2 - abs(points[i]-bin) + abs(points[i]-adil))
      {d = min(d, d2 - abs(points[i]-bin) + abs(points[i]-adil));};
  }
  dist = min(d,dist);
      std::cout << std::fixed;
    std::cout << std::setprecision(8);
    std::cout <<  dist << "\n";
}
