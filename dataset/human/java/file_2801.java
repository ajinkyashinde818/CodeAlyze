import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a1=sc.next();
		String a2=sc.next();
		int a1m=a1.length();
		int a2m=a2.length();
		int[] a1su=new int[a1m];
		int[] a2su=new int[a2m];

		for(int i=0; i<a1m; i++) {
			a1su[i]=a1.charAt(i)*1;
		}

		for(int i=0; i<a2m; i++) {
			a2su[i]=a2.charAt(i)*1;
		}
		int tmp1=0;
		int tmp2=0;
		for(int i=0; i<a1m; i++) {
			for(int j=i; j<a1m; j++) {
				if(a1su[i]>a1su[j]) {
					tmp1=a1su[i];
					tmp2=a1su[j];
					a1su[i]=tmp2;
					a1su[j]=tmp1;
				}
			}
		}

		for(int i=0; i<a2m; i++) {
			for(int j=i; j<a2m; j++) {
				if(a2su[i]<a2su[j]) {
					tmp1=a2su[i];
					tmp2=a2su[j];
					a2su[i]=tmp2;
					a2su[j]=tmp1;
				}
			}
		}

		/*for(int i=0; i<a2m; i++) {
			System.out.println(a2su[i]);
		}*/

		boolean ts=false;
		boolean pd=false;
		for(int i=0; i<Math.min(a1m, a2m); i++) {
			if(a1su[i]<a2su[i]) {
				ts=true;
				System.out.println("Yes");
				System.exit(0);
			}
			else if(a1su[i]==a2su[i]){
				pd=true;
			}

			if(pd==true && a1su[i]>a2su[i]) {
				System.out.println("No");
				System.exit(0);
			}
		}
		if(ts==false && pd==true) {
			if(a1m==a2m) {
				System.out.println("No");
				System.exit(0);
			}
			else if(a1m<a2m){
				System.out.println("Yes");
				System.exit(0);
			}

			else if(a1m>a2m){
				System.out.println("No");
				System.exit(0);
			}
		}
		/*int sa=0;

		for(int i=0; i<Math.min(a1m, a2m); i++) {
			if(a1su[i]<a2su[i]) {
				sa=1;
				System.out.println("Yes");
				System.exit(0);
			}
			else if(a1su[i]>a2su[i]) {
				sa=-1;
				System.out.println("No");
				System.exit(0);
			}
		}
		if(sa==0) {
			if(a1m>a2m) {
				System.out.println("No");
			}
			else {
				System.out.println("Yes");
			}
		}*/
	}
}
