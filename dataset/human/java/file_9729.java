import java.util.Scanner;
public class Main{
    static tree[] wd;
	public static void main(String[] args) {
	    int x,i,j,n,root = 0,hz;
	// TODO Auto-generated method stub
     Scanner sca = new Scanner(System.in);
     n=sca.nextInt();
     wd=new tree[n];
     int[]checkmap=new int[n+1];
    for(j=0;j<n;j++){
    	x=sca.nextInt();
	if(j==0)root=x;
	wd[x]=new tree(x);
	for(i=0;i<2;i++){
	    hz=sca.nextInt();
	    if(i==0){
            wd[x].setleft(hz);
	    }else{
	    wd[x].setright(hz);
	    }
	    if(hz==-1)hz=n;
	checkmap[hz]=1;
	}
    }
    for(j=0;j<n;j++){
	if(checkmap[j]!=1)root=j;
    }
    chain(root,-1);
     for(i=0;i<n;i++){
    	 System.out.print("node "+wd[i].getnode()+": parent = "+ wd[i].getpar()+", sibling = "+sersib(i)+", degree = "+wd[i].getdeg()+", depth = "+serdepth(i,0)+", height = "+serheight(i,0)+", ");
	 if(wd[i].getpar()==-1){
    	System.out.println("root");
	 }else if(wd[i].getdeg()==0){
    	 System.out.println("leaf");
    	}else{
	   System.out.println("internal node");
    	}
     }
   
     
	}
    public static void chain(int chi,int p){
	int i;
	wd[chi].setpar(p);
	if(wd[chi].getdeg()==0)return;
	if(wd[chi].getleft()!=-1) chain(wd[chi].getleft(),chi);
	if(wd[chi].getright()!=-1)chain(wd[chi].getright(),chi);
	}
    public static int serdepth(int x,int cnt){
	    if(wd[x].getpar()==-1)return cnt;
		cnt++;
		return serdepth(wd[x].getpar(),cnt);
	}
    public static int sersib(int n){
	if(wd[n].getpar()==-1)return -1;
        if(wd[wd[n].getpar()].getright()==n){
	    return wd[wd[n].getpar()].getleft();
	}else{
		return wd[wd[n].getpar()].getright();
	}
    }
	    public static int serheight(int n,int cnt){
	int x=-1,y=-1;
	if(wd[n].getleft()==-1&&wd[n].getright()==-1) return cnt;
	if(wd[n].getleft()!=-1){
	    x=serheight(wd[n].getleft(),cnt+1);
	}
        if(wd[n].getright()!=-1){
	    y=serheight(wd[n].getright(),cnt+1);
	}
	if(x<y)return y;
        return x;
	}
    
}
class tree{
    int node,par,n,i,degree=0,sibling,depth,height;
    int left,right;
    tree(int node){
	this.node=node;
    }
    public int getnode(){
	return node;
    }
    public void setleft(int c){
	left=c;
	if(left!=-1) degree++;
    }
    public int getleft(){
	return left;
    }
    public void setright(int c){
	right=c;
	if(right!=-1) degree++;
    }
    public int getright(){
	return right;
    }
    public void setpar(int p){
	par=p;
    }
    public int getpar(){
	return par;
    }
    public int getdeg(){
	return degree;
    }
    
}
