import std.stdio;
import std.conv;
import std.string;
import std.array;
 
void main(){
  int n=to!int(readln.chomp);
  while(n--){
    auto s=new bool[32];
    auto input=readln.chomp;
    for(int i=0;i<8;++i){
      int a=(input[i]<='9')?input[i]-'0':input[i]-'a'+10;
      for(int j=0;j<4;++j){
        s[4*i+j]=(a&(1<<(3-j)))?true:false;
      }
    }
    //for(int i=0;i<32;++i)stderr.writef("%d",s[i]?1:0);
    //stderr.writeln();
    string ans;
    int tmp=0;
    for(int i=0;i<24;++i){
      tmp+=s[i+1]?(1<<(23-i)):0;
    }
    ans~=((s[0])?"-":"")~to!string(tmp);
    tmp=0;
    bool f=false;
    for(int i=25;i<32;++i){
      tmp+=(s[i])?(78125<<(31-i)):0;
    }
    int cnt=0;
    if(tmp==0)cnt=0;
    else{
    	if(tmp<1000000)++cnt;
    	if(tmp<100000)++cnt;
    }
    while(tmp%10==0&&tmp!=0)tmp/=10;
    ans~="."~"0".replicate(cnt)~to!string(tmp);
    writeln(ans);
  }
}
