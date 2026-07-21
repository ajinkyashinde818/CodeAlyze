import java.io.BufferedReader;
						import java.util.ArrayList;
						import java.util.Arrays;
						import java.util.Collections;
						import java.util.HashMap;
						import java.util.HashSet;
						import java.util.List;
						import java.util.Map;
						import java.io.IOException;
						import java.io.InputStreamReader;
					import java.math.BigInteger;
					import java.util.Scanner;
						import java.util.Set;
						import java.util.StringTokenizer;
					import java.util.Vector;
						
						
						
						
						public class Main {
							 static class FastReader 
							    { 
							        BufferedReader br; 
							        StringTokenizer st; 
							       
							  
							        public FastReader() 
							        { 
							            br = new BufferedReader(new
							                     InputStreamReader(System.in)); 
							        } 
							       
							        String next() 
							        { 
							            while (st == null || !st.hasMoreTokens()) 
							            { 
							                try
							                { 
							                    st = new StringTokenizer(br.readLine()); 
							                } 
							                catch (IOException  e) 
							                { 
							                    e.printStackTrace(); 
							                } 
							            } 
							            return st.nextToken();
							            
							        } 
							  
							        int nextInt() 
							        { 
							            return Integer.parseInt(next()); 
							        } 
							  
							        long nextLong() 
							        { 
							            return Long.parseLong(next()); 
							        } 
							  
							        double nextDouble() 
							        { 
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
						
									public Character charAt(int i) {
										// TODO Auto-generated method stub
										return null;
									} 
									public BigInteger nextBigInteger() {
										// TODO Auto-generated method stub
										return null;
									} 
							    }
						
							 static int gcd(int a , int b) {
								 if(b==0)return a;
								 return gcd(b,a%b);
							 }
						
							/**
							 * @param args
							 * @throws IOException
							 */
							 static int m =(int) (1e9+7);
							 static long mod(long x) {
								 
								 return ((x%m+m)%m);
							 }
							 static long add(long x,long y) {
								 return mod((mod(x)+mod(y)));
							 }
							 static long mul(long x,long y) {
								 return mod((mod(x)*mod(y)));
							 }
							 
							 
							 static  int[] readAr(int n) {
						        	FastReader s=new FastReader();
						        	int [] ar = new int [n];
						        	for(int i=0;i<n;i++) {
						        		ar[i]=s.nextInt();
						        	}
						        	return ar;
						        }
						       static int[] printAr(int[] ar,int n) {
						        	for(int i=0;i<n;i++) {
						        		System.out.print(ar[i]+" ");
						        	}
						           	return ar;
						        }
						     
						       
							public static void main(String[] args)throws IOException  {
								FastReader s=new FastReader();
								int t =s.nextInt();
								int c=0,flag=0;
								int[] a = new int[t];
								int[] b = new int[t];
								for(int i=0;i<t;i++) {
									a[i]=s.nextInt();
									b[i]=s.nextInt();
									
								}
								for(int i=2;i<t;i++) {
									if(a[i]==b[i] && a[i-1]==b[i-1] && a[i-2]==b[i-2]) {
//										System.out.println(a[i]+" "+b[i-1]+" "+a[i-2]);
										System.out.println("Yes");
										flag=1;
										break;
									}
								}
								
								if(flag==0) System.out.println("No");
								
							}
}
