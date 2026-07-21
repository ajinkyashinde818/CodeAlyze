import java.util.*;
import java.io.*;
public class Main{
	
	static final int NONUM=-1;
	public static void main(String[] args)throws IOException{
		final Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		NODE[] n = new NODE[a];
	
		for(int i=0;i<n.length;i++){
			int id=sc.nextInt();
			n[id]=new NODE();
			n[id].id = id;
			n[id].l = sc.nextInt();
			n[id].r = sc.nextInt();
			n[id].p = -1;
			n[id].s = -1;
			n[id].d = 0;
			n[id].t = "leaf";
			if(n[id].l != -1){
				n[id].d++;
				n[id].t = "internal node";
			}
			if(n[id].r != -1){
				n[id].d++;
				n[id].t = "internal node";
			}
		}
	     for(int i=0; i<a; i++){
	    	 if(n[i].l != -1){
	                n[n[i].l].p = n[i].id;
	            }
	            if(n[i].r != -1){
	                n[n[i].r].p = n[i].id;
	            }
	            if(n[i].l != -1 && n[i].r != -1){
	                n[n[i].l].s = n[i].r;
	                n[n[i].r].s = n[i].l;
	            }
	     }
		
	        for(int i=0; i<a; i++){
	            if(n[i].p == -1){
	                n[i].t = "root";
	                if(n[i].l != -1){
	                    getdepth(n, n[i].l, 1);
	                }
	                if(n[i].r != -1){
	                    getdepth(n, n[i].r, 1);
	                }
	            }
	            if(n[i].d == 0){
	                if(n[i].p != -1){
	                    getheight(n, n[i].p, 1);
	                }
	            }
	        }
		
		for(int i=0;i<a;i++){
			System.out.println("node "+n[i].id+": parent = "+n[i].p+", sibling = "+n[i].s+", degree = "+n[i].d+", depth = "+n[i].dep+", height = "+n[i].h+ ", "+n[i].t);
		}
	}
	
	static void getdepth(NODE[] n,int i,int d){
	     n[i].dep = d;
	        d++;
	        if(n[i].l != -1){
	            getdepth(n, n[i].l, d);
	        }
	        if(n[i].r != -1){
	            getdepth(n, n[i].r, d);
	        }
	        
	}	
	
	static void getheight(NODE[] n,int i, int h){
        if(h < n[i].h) h = n[i].h;
        else           n[i].h = h;
        h++;
        if(n[i].p != -1){
            getheight(n, n[i].p, h);
        }
	}
}
	
class NODE{
	int id;
	int r;
	int l;
	int p;
	int d;
	int dep;
	int h;
	int s;
	String t; 
}
