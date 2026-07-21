import java.util.Scanner;
import java.util.ArrayList;
public class Main{
	public static void main(String args[]){
    
    	Scanner sc=new Scanner(System.in);
    	int n = sc.nextInt();
      	long k=sc.nextLong();
      	int arr[]=new int[n+1];
      	boolean visited[]=new boolean[n+1];
      	for(int i=1;i<=n;i++) arr[i]=sc.nextInt();
      	visited[1]=true;
      	int root=-1;
      	int stepsToRoot=0;
      	int cycleSize=0;
      	for(int i=1;i<=n;){
        	int index=arr[i];
          stepsToRoot++;
          	if(visited[index]){
            	root=index;
              	break;
            }
            visited[i]=true;
            i=arr[i];
        }
      	ArrayList<Integer> cycle=new ArrayList<>();
      	for(int i=root;;){
        	cycle.add(i);
          	cycleSize++;
          	i=arr[i];
          	if(i == root) break;
        }
      	stepsToRoot-=cycleSize;
      	if(k == stepsToRoot) System.out.println(root);
      	else if(k < stepsToRoot){
        	int ans=arr[1];
          for(int i=2;i<=k;i++){
          	ans=arr[ans];
          }
        	System.out.println(ans);
        }
    	else{
        	k-=stepsToRoot;
          	k=k%cycleSize;
          	int ans=cycle.get((int)k);
          System.out.println(ans);        
        }
    }
}
