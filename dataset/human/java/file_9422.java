import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[][]=new int[n][2];
        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<=1;j++)
        		arr[i][j]=sc.nextInt();
        }
        int ct=0,bl=0;
        for(int i=0;i<n;i++)
        {
        	if(ct==3)
        	{
        		bl=1;
        		break;
        	}
        	else if(arr[i][0]==arr[i][1])
        		ct=ct+1;
        	else
        		ct=0;
        }
        if(bl==1 || ct==3)
        	System.out.println("Yes");
        else
        	System.out.println("No");
	}

}
