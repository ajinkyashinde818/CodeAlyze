import java.util.Scanner;


public class Main {

	Scanner sc;
	
	class Circle{
		public double r;
		public Vector c;
		
		public Circle(double x, double y, double r){
			this.c=new Vector(x, y);
			this.r=r;
		}
	}
	
	class Line{
		public Vector p1, p2;
		
		public Line(double x1, double y1, double x2, double y2){
			this.p1=new Vector(x1,y1);
			this.p2=new Vector(x2,y2);
		}
		
		public Vector v(){
			return p2.subtract(p1);
		}
	}
	
	class Vector{
		public double x, y;
		
		public Vector(double x, double y){
			this.x=x;
			this.y=y;
		}
		
		public double norm(){
			return Math.hypot(x, y);
		}
		
		public double sqrNorm(){
			return x*x+y*y;
		}
		
		public double ip(Vector v){
			return x*v.x+y*v.y;
		}
		
		public Vector add(Vector v){
			return new Vector(x+v.x, y+v.y);
		}
		
		public Vector subtract(Vector v){
			return new Vector(x-v.x, y-v.y);
		}
		
		public Vector multiply(double a){
			return new Vector(x*a, y*a);
		}
		
		public String toString(){
			return String.format("(%f,%f)", x, y);
		}
	}
	
	boolean cross(Circle circle, Line line){
		Vector v1=line.p1.subtract(circle.c), v2=line.p2.subtract(circle.c);
		Vector x=line.p1.subtract(line.v().multiply(line.v().ip(v1)/line.v().sqrNorm()));
		
		if((v1.norm()<circle.r&&v2.norm()<circle.r)||x.subtract(circle.c).norm()>circle.r) return false;
		else if(x.subtract(line.p1).ip(x.subtract(line.p2))<=0) return true;
		else if(v1.norm()<circle.r||v2.norm()<circle.r) return true;
		else return false;
	}
	
	int ni(){
		return sc.nextInt();
	}
	
	void io(){
		sc=new Scanner(System.in);
		
		int n;
		while((n=ni())!=0){
			Circle[] circle=new Circle[n];
			for(int i=0;i<n;++i){
				circle[i]=new Circle(ni(),ni(),ni());
			}
			
			int m=ni();
			for(int i=0;i<m;++i){
				Line line=new Line(ni(), ni(), ni(), ni());
				
				boolean safe=false;
				for(int j=0;j<n;++j){
					safe|=cross(circle[j],line);
				}
				System.out.println(safe?"Safe":"Danger");
			}
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main().io();
	}
}
