import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int n = sc.nextInt();
        int a[][] = new int[n][2];
        for(int i=0;i<n;i++){
        		a[i][0] = sc.nextInt();
        		a[i][1] = sc.nextInt();	
        }
        String b = "No";
        for(int i=0;i<n-2;i++){
        	if(a[i][0] == a[i][1] && a[i+1][0] == a[i+1][1]&&a[i+2][0] == a[i+2][1]){
        		b = "Yes";
        		break;
        	}
        }
        System.out.println(b);
    }
}
