import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // 整数の入力
        int N = sc.nextInt();
        // スペース区切りの整数の入力
        
        
        int[] a = new int[N];
        int[] b = new int[N];
        
        int z;
        z=0;

        for(int i=0;i<N;i++) {
        	a[i]=sc.nextInt();
        	b[i]=sc.nextInt();
        }
        
        for(int j=0;j<N-2;j++) {
        	if(a[j]==b[j] && a[j+1]==b[j+1] && a[j+2]==b[j+2]) {
        		z=z+1;
        	} else {
        		z=z+0;
        	}
        	
        }        
        
        if(z==0) {
        	System.out.println("No");
        } else {
        	System.out.println("Yes");
        }
        
        
    }
}
