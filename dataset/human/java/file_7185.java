import java.util.*;
public class Main { 
	final static int maxn=(int)2e5+10;
	static int vis[]=new int [maxn];
	static int a[]=new int [maxn];
	static int b[]=new int [maxn];
	static int f[][]=new int [maxn][3];
 public static void main(String args[])
 {
	 Scanner input=new Scanner(System.in);
     int k,n;
     k=input.nextInt();n=input.nextInt();
     for(int i=1;i<=n;i++)
    	 a[i]=input.nextInt();
     Arrays.sort(a,1,n+1);
     long dis=a[n]-a[1];int alldis=a[n]-a[1];
     int left=a[1];int right=k-a[n];
     for(int i=1;i<=n-1;i++)
     {
    	 int subdis=a[i+1]-a[i];
    	 if(subdis>(left+right))
    		 dis=Math.min(dis, alldis-subdis+(left+right));
     }
     System.out.println(dis);
}
}
