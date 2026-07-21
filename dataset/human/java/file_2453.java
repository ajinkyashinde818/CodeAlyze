import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner s=new Scanner(System.in);
		
		int a=s.nextInt();
		for(int i=0;i<a;i++){
			String b=s.next();
			String c=s.next();
			int d=0,e=0;
			int temp1=0,temp2=0;
			for(int j=0;j<b.length();j++){
				switch(b.charAt(j)){
					case 'm':
						if(temp2==0)d+=1000;
						else d+=1000*temp2;
						temp2=0;
						break;
					case 'c':
						if(temp2==0)d+=100;
						else d+=100*temp2;
						temp2=0;
						break;
					case 'x':
						if(temp2==0)d+=10;
						else d+=10*temp2;
						temp2=0;
						break;
					case 'i':
						if(temp2==0)d++;
						else d+=temp2;
						temp2=0;
						break;
					default:
						temp2=(int)b.charAt(j)-'0';
				}
			}
			for(int j=0;j<c.length();j++){
				switch(c.charAt(j)){
					case 'm':
						if(temp1==0)e+=1000;
						else e+=1000*temp1;
						temp1=0;
						break;
					case 'c':
						if(temp1==0)e+=100;
						else e+=100*temp1;
						temp1=0;
						break;
					case 'x':
						if(temp1==0)e+=10;
						else e+=10*temp1;
						temp1=0;
						break;
					case 'i':
						if(temp1==0)e++;
						else e+=temp1;
						temp1=0;
						break;
					default:
						temp1=(int)c.charAt(j)-'0';
				}
			}
			int g=d+e;
			if(g/1000>1)System.out.print((int)g/1000+"m");
			else if(g/1000==1)System.out.print("m");
			if(g%1000/100>1)System.out.print((int)g%1000/100+"c");
			else if(g%1000/100==1)System.out.print("c");
			if(g%100/10>1)System.out.print((int)g%100/10+"x");
			else if(g%100/10==1)System.out.print("x");
			if(g%10>1)System.out.print(g%10+"i");
			else if(g%10==1)System.out.print("i");
			System.out.println();
		}
	}
}
