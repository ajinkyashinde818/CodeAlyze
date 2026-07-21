import java.util.Scanner;

class Main{
    public static void main(String args[])
    {
        Scanner s= new Scanner(System.in);
       
        int n = s.nextInt();
        int a[][] = new int [n][2];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                a[i][j]=s.nextInt();


            }
        }
        if(Triplate(a,n))
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }
        

    }
    public static boolean Triplate(int [][] arr,int n)
    {
        for(int i=0;i<n-2;i++)
        {

            if(arr[i][0]==arr[i][1] && arr[i+1][0]==arr[i+1][1] && arr[i+2][0]==arr[i+2][1] )
            {
                return true;
            }
        }
        return false;
    }
}
