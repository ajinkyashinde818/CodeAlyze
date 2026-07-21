import java.io.*;
import java.util.StringTokenizer;
 
class Main{
 
static final PrintWriter out=new PrintWriter(System.out);
static boolean[] hasParent;
 
static class Node{
int id;
int p;
int rank;
int height;
int s;
int deg;
int l;
int r;
String type;
Node(int id){
this.id=id; this.p=-1; this.rank=-1; this.height=-1; this.s=-1; this.l=-1; this.r=-1; this.deg=0; this.type="internal node";
}
}
 
public static void main(String[] args) throws IOException{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int num=Integer.parseInt(br.readLine());
Node[] ns=new Node[num];
hasParent=new boolean[num];
StringTokenizer st;
StringBuilder sb;
for(int i=0;i<num;i++){
ns[i]=new Node(i);
}
for(int i=0;i<num;i++){
st=new StringTokenizer(br.readLine());
int id=Integer.parseInt(st.nextToken());
Node n=ns[id];
int l=Integer.parseInt(st.nextToken());
n.l=l;
int r=Integer.parseInt(st.nextToken());
n.r=r;
if(l==-1&&r==-1){
n.type="leaf";
n.height=0;
}
else if(l==-1){
ns[r].p=id;
n.deg=1;
hasParent[r]=true;
}
else if(r==-1){
ns[l].p=id;
n.deg=1;
hasParent[l]=true;
}
else{
ns[l].p=id;
ns[l].s=r;
hasParent[l]=true;
ns[r].p=id;
ns[r].s=l;
n.deg=2;
hasParent[r]=true;
}
}
for(int i=0;i<num;i++){
Node an=ns[i];
if(an.rank<0) an.rank=setRank(i,ns);
if(an.height<0) an.height=setHeight(i,ns);
sb=new StringBuilder();
sb.append("node ");
sb.append(i);
sb.append(": parent = ");
sb.append(an.p);
sb.append(", sibling = ");
sb.append(an.s);
sb.append(", degree = ");
sb.append(an.deg);
sb.append(", depth = ");
sb.append(an.rank);
sb.append(", height = ");
sb.append(an.height);
sb.append(", ");
sb.append(an.type);
sb.append(System.getProperty("line.separator"));
out.print(sb);
}
out.flush();
}
 
private static int setRank(int now,Node[] ns){
if(ns[now].rank>=0) return ns[now].rank;
if(!hasParent[now]){
ns[now].type="root";
return ns[now].rank=0;
}
return ns[now].rank=setRank(ns[now].p,ns)+1;
}

private static int setHeight(int now,Node[] ns){
if(now<0) return Integer.MIN_VALUE/2;
if(ns[now].height>=0) return ns[now].height;
return ns[now].height=Math.max(setHeight(ns[now].l,ns),setHeight(ns[now].r,ns))+1;
}
}
