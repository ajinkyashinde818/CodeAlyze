import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();

		String image[] = new String[n];
		for(int i = 0; i < n; i++){
			image[i] = sc.next();
		}

		String template[] = new String[m];
		for(int i = 0; i < m; i++){
			template[i] = sc.next();
		}

//		int count = 0;
		for(int i = 0; i < n - m + 1 ; i++){
			for(int j = 0; j < n - m + 1; j++){
//				System.out.println("i = "+i+" j = "+j);
				boolean same = true;
				for(int k = 0; k < m; k++){
//					System.out.println(template[k] + " " +image[i + k].substring(j, j + m));
					if(!template[k].equals(image[i + k].substring(j, j + m))){
						same = false;
						break;
					}
				}

				if(same){
//					count++;
					System.out.println("Yes");
					return;
				}
			}
		}

		System.out.println("No");

//		System.out.println(count);
    }
}
