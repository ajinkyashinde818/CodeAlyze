import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
              Scanner scn =  new Scanner(System.in);
              String s = scn.next();
             
              scn.nextLine();
              int q = scn.nextInt();
                 StringBuilder sb1 = new StringBuilder();
                 StringBuilder sb2=new StringBuilder();
                 
              boolean f = false;
              while(q-->0){
            	  int t= scn.nextInt();
            	 if(t==1){
            		 if(f){
            			 f=false;
            		 }else{
            			 f=true;
            		 }
            	 }else{
            		 int n =scn.nextInt();
            		 char ch = scn.next().charAt(0);
            		 if(f==true){
            			 if(n==1){
            				 sb2.append(ch);
            			 }else{
            				 sb1.append(ch);
            			 }
            		 }else{
            			 if(n==1){
            				 sb1.append(ch);
            			 }else{
            				 sb2.append(ch);
            			 }
            		 }
            	 }
              }
              if(f==true){
            	  for(int i=sb2.length()-1;i>=0;i--){
            		  System.out.print(sb2.charAt(i));
            	  }
            	  for(int i=s.length()-1;i>=0;i--){
            		  System.out.print(s.charAt(i));
            	  }
            	  for(int i=0;i<sb1.length();i++){
            		  System.out.print(sb1.charAt(i));
            	  }
              }else{
            	  for(int i=sb1.length()-1;i>=0;i--){
            		  System.out.print(sb1.charAt(i));
            	  }
            	  for(int i=0;i<s.length();i++){
            		  System.out.print(s.charAt(i));
            	  }
            	  for(int i=0;i<sb2.length();i++){
            		  System.out.print(sb2.charAt(i));
            	  }
            	  
              }
         
	}

}
