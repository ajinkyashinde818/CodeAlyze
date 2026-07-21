import java.util.*;
import java.io.*;




 
public class Main 
{
	
	public static void main(String[] args) throws IOException 
	{ 
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		long k=s.nextLong();
		
		int ar[]=new int[n];
		for(int i=0;i<n;i++) {
			int u=s.nextInt();
			u--;
			ar[i]=u;
		}
		if(k<n) {
			int count=0;
			int next=0;
			while(count<k) {
				int val=ar[next];
				count++;
				next=val;
			}
			System.out.println(next+1);
		}else {
			// if the size is greater than k that means there is always cycle
			//so our task is to find the no of nodes in cycle so that we can mod with because we don't want to traverse again and again
			//but it is possible that some node are not included in cycle so we have to subtract those to k
			int pos=0;
			int next=0;
			int noofnode=-1;
			HashMap<Integer,Integer>hm=new HashMap<>();
			hm.put(next, pos);
			while(true ) {
				pos++;
				int val=ar[next];
				if(hm.containsKey(val)) { //if visit again that means cycle is exit
					noofnode=hm.get(val);
					break;
				}
				hm.put(val, pos);
				next=val;
			}
				k-=noofnode;
				int nodeincycle=hm.size()-noofnode;
				k%=nodeincycle;
				if(k==0)    //no of node in cycle
					k=nodeincycle;
				next=ar[next]; // start from the starting point of cycle
				int count=0;
				while(count<k) {
					int val=ar[next];
					count++;
					next=val;
				}
				System.out.println(next+1);
			
			
			
		}
	}

	
}
