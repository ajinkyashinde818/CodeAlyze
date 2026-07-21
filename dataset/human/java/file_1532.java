import java.util.Scanner;

class Main{
	public static void main(String[] ag) {
		Scanner sc=new Scanner(System.in);
		int moto=sc.nextInt();
		int bbn=sc.nextInt();

		char[][] mtgz=new char[moto][moto];
		char[][] bbgz=new char[bbn][bbn];

		String a="";
		for(int i=0; i<moto; i++) {
			a=sc.next();
			for(int j=0; j<moto; j++){
				mtgz[i][j]=a.charAt(j);
			}
		}

		for(int i=0; i<bbn; i++) {
			a=sc.next();
			for(int j=0; j<bbn; j++){
				bbgz[i][j]=a.charAt(j);
			}
		}
		boolean it=true;
		for(int i=0; i<moto-bbn+1; i++) {
			for(int j=0; j<moto-bbn+1; j++) {
				it=true;

				for(int k=0; k<bbn; k++) {
					for(int l=0; l<bbn; l++) {
						if(mtgz[i+k][j+l]!=bbgz[k][l]) {
							it=false;
							break;
						}
					}
					if(it==false) {
						break;
					}
					else {
						//
					}
				}

				if(it==true) {
					System.out.println("Yes");
					System.exit(0);
				}
			}
		}

		System.out.println("No");
		System.exit(0);
	}
}
