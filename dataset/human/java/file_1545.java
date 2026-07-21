import java.util.*;
public class Main{
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);

   int N = sc.nextInt();   
   int M = sc.nextInt();
   char[][] img = new char[N][N];
   char[][] tmp = new char[M][M];
   boolean aru = false;
   boolean dame = false;
 
   for(int i=0;i<N;i++)
   {
     img[i] = sc.next().toCharArray();
   }
   for(int i=0;i<M;i++)
   {
     tmp[i] = sc.next().toCharArray();
   }
   
   for(int i=0;i<N-(M-1);i++)
   {
     for(int k=0;k<N-(M-1);k++)
     {
       if(img[i][k]==tmp[0][0])
       {
         aru=true;
         for(int j=0;j<M;j++)
         {
           for(int l=0;l<M;l++)
           {
             if(img[i+j][k+l]!=tmp[j][l])
             {
               dame=true;
               aru=false;
               break;
             }
           }
           if(dame)
           {
             dame = false;
             break;
           }
         }
         
       }
       if(aru)
     {
       break;
     }
     }
     if(aru)
     {
       break;
     }
   }
   String ans="No";
   if(aru) ans = "Yes";
   System.out.println(ans);
 }
}
