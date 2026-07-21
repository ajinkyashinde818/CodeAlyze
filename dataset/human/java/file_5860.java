import java.io.*;
class Main{
  public static void main(String[] args){
    
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );
    
    try{
      
      String str2 = "abc";
      String str3 = "acb";
      String str4 = "bac";
      String str5 = "bca";
      String str6 = "cba";
      String str7 = "cab";
      
    String str1 = br.readLine();
    
      if(str1.equals(str2) || str1.equals(str3) || str1.equals(str4) || 
         str1.equals(str5) || str1.equals(str6) || str1.equals(str7) ){
        System.out.println("Yes");
      }else{
        System.out.println("No");
      }
      
    }catch(Exception e) {
    }
  }
}
