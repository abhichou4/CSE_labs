import java.util.*;

class Switch{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int p = sc.nextInt();
		int q = sc.nextInt();
		int r = sc.nextInt();
		Switch.roots(p,q,r);
	}

	private static void roots(int a, int b, int c){

		int s;
		Scanner sc = new Scanner(System.in);
		double d = b*b - 4*a*c;
		if(d>0.0){
			s=1;
		}
		else if(d==0.0){
			s=2;
		}
		else{
			s=3;
		}

		switch(s){

			case 1:
			double root1 = (-b + Math.pow(d,0.5)) / 2*a;
			double root2 = (-b - Math.pow(d,0.5)) / 2*a;
			System.out.println(root1 + root2);
			break;

			case 2:
			int root = -b / 2*a;
			System.out.println(root);
			break;

			default:
			System.out.println("No roots");
		}

	}
}