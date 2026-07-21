import java.util.*;
public class Main  {
    public static void main(String[] args) {
        Scanner sc =new Scanner (System.in);
        int n=sc.nextInt();
        int []arr1=new int[n];
        int []arr2=new int[n];
        for(int i=0;i<n;i++)
        {
            arr1[i]=sc.nextInt();
            arr2[i]=sc.nextInt();
        }
        int res[]=new int [n];
        for(int i=0;i<n;i++)
        {
            if(arr1[i]==arr2[i])
            {
                res[i]=1;
            }
        }
        boolean flag=false;
        for(int i=0;i+2<n;i++)
        {
            if(res[i]==res[i+1]&&res[i+1]==res[i+2]&&res[i+2]==1)
            {
                flag=true;
            }
        }
        if(flag==true)
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }
        // String s=sc.nextLine();
        // int length=s.length();
        // char c=s.charAt(length-1);
        // if(Character.isLowerCase(c))
        // {
        //     if(c=='s')
        //     {
        //         System.out.println(s+"es");
        //     }
        //     else{
        //         System.out.println(s+"s");
        //     }
        // }
        sc.close();
    }
}
