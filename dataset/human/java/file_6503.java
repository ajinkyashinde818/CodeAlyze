import java.util.*; 

class Main{
public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
        int k=sc.nextInt();
        int s=sc.nextInt();
		int ans=0;
		
		for(int x=k;x>=0;x--){
          for(int y=Math.min(s-x,k);y>=0;y--){
            int z=s-x-y;
    		if(z<=k){
            ans++;
            }else{
            break;
            }
          }
    	}
    

    	System.out.println(ans);
    }
}
