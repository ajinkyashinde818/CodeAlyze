import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main{ 
   static class Fast{
     public BufferedReader br;
     public StringTokenizer st;
     
     public Fast(){
          br =new BufferedReader(new InputStreamReader(System.in));
     }
     
     String next(){
          while(st==null || !st.hasMoreTokens()){
               try{
                    st=new StringTokenizer(br.readLine());
               }
               catch(IOException e){
                    throw new RuntimeException(e);
               }
               
          }
               return st.nextToken();
          }
     int nextInt(){
          return Integer.parseInt(next());
     }
 
     long nextLong(){
          return Long.parseLong(next());
     }
 
     double nextDouble(){
          return Double.parseDouble(next());
     }

     String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
 
 }  
   
    static  Fast f=new Fast();
    static PrintWriter out = new PrintWriter(System.out);


    static void readArray(int a[]) 
      {
        
        for (int i=0;i<a.length;i++ ) a[i]=f.nextInt();
        
      }
    
    
     
  public static void main(String[] args)throws Exception{
  //StringTokenizer st;//! @ % & * () _ {} # ~ : < > ? "" | ^
         
 
        //StringBuilder res=new StringBuilder();

         int n=f.nextInt();
  
       
       // while(t-->0){
          int d1[]=new int[n];
          int d2[]=new int[n];
          for (int i=0;i<n ;i++ ) {
            d1[i]=f.nextInt();
            d2[i]=f.nextInt();
          }
          
          int count=0;
          for (int i=0;i<n ;i++ ) {
            if (count==3) {
              break;
            }

            if (d1[i]==d2[i]) {
              count++;
              continue;
            }

            count=0;

          }

          
      //  }
          if (count==3)
          out.println("Yes");
          else 
          out.println("No");

   
        

        out.close();
 
}
}
