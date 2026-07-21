void main(){
  import std.stdio, std.string, std.conv, std.algorithm;
  import std.array;
  
  int n; long c; rd(n, c);
  auto x=new long[](n), v=new long[](n);
  foreach(i; 0..n) rd(x[i], v[i]);

  // import std.exception;
  // enforce(n<=100);

  x=0L~x~c;
  v=0L~v~0L;

  long mx=0, inf=2e18.to!(long);
  mx=max(mx, fun(n, x, v));
  x=x.map!(e=>(c-e)).array;
  reverse(x); reverse(v);
  mx=max(mx, fun(n, x, v));

  long tot=reduce!"a+b"(0L, v);
  for(int i=0; i<=n; i++){
    long cl=x[i], cr=c-x[i+1];
    long cost=cl+cr+min(cl, cr);
    mx=max(mx, tot-cost);
  }
  writeln(mx);
}

long fun(int n, long[] d, long[] v){ // 0->l->0->r (l<r) distance : l*2+r
  import std.algorithm;
  auto best=new long[](n+2); // [i, $)
  fill(best, -2_000_000_000_000_000_000);
  best[n+1]=0;
  for(auto r=n, s=0L; r>0; r--){
    s+=v[r];
    best[r]=max(best[r+1], s-(d[$-1]-d[r]));
  }
  long ret=0;
  for(auto l=0, s=0L; l<=n; l++){
    s+=v[l];
    ret=max(ret, (s-d[l]*2)+best[l+1]);
  }
  return ret;
}

void rd(T...)(ref T x){
  import std.stdio, std.string, std.conv;
  auto l=readln.split;
  assert(l.length==x.length);
  foreach(i, ref e; x) e=l[i].to!(typeof(e));
}
