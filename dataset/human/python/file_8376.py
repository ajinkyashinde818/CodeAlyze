import std.stdio,std.conv,std.string,std.algorithm;
 
void main(){
    auto k=readln.chomp.split.to!(int[])[0];
    auto a=readln.chomp.split.to!(int[]);
    int[] d;
    foreach(i;1..a.length){
        d~=a[i]-a[i-1];
    }   
    d~=a[0]+(k-a[$-1]);
    (k-max(d)).writeln;
}
 
auto max(int[] arr){
    int m;
    foreach(e;arr){
        if(m<=e)
            m=e;
    }   
    return m;
}
