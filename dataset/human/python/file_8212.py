void main(){
  import std.stdio, std.string, std.conv, std.algorithm;

  auto s=readln.chomp.to!(char[]);
  int x, y; rd(x, y);

  auto n=s.length;

  int[] dxs, dys;
  for(int i=0, t=1; i<n; i++, t^=1){
    int d=0;
    while(i<n && s[i]=='F') i++, d++;
    if(d==0) continue;
    if(t&1) dxs~=d;
    else dys~=d;
  }

  // wr(dxs); wr(dys);

  auto xlen=dxs.length, ylen=dys.length;
  auto xrec=new bool[][](xlen+1, 8000*3);
  auto yrec=new bool[][](ylen+1, 8000*3);
  auto ofse=8000*3/2;
  xrec[0][ofse]=yrec[0][ofse]=true;
  foreach(i; 0..xlen)for(auto j=0; j<=22000; j++){
    if(xrec[i][j]){
      xrec[i+1][j+dxs[i]]=true;
      if((i>0) || (s[0]=='T')) xrec[i+1][j-dxs[i]]=true;
    }
  }
  foreach(i; 0..ylen)for(auto j=0; j<=22000; j++){
    if(yrec[i][j]){
      yrec[i+1][j+dys[i]]=true;
      yrec[i+1][j-dys[i]]=true;
    }
  }

  if(xrec[xlen][x+ofse] && yrec[ylen][y+ofse]) writeln("Yes");
  else writeln("No");
}

void rd(T...)(ref T x){
  import std.stdio, std.string, std.conv;
  auto l=readln.split;
  assert(l.length==x.length);
  foreach(i, ref e; x){
    e=l[i].to!(typeof(e));
  }
}
void wr(T...)(T x){
  import std.stdio;
  foreach(e; x) stderr.write(e, " ");
  stderr.writeln();
}
