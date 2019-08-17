import java.util.*;

class Sample{

	 public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y = sc.nextInt();
		int z = sc.nextInt();

		int grt = Sample.greatest(x,y,z);
		System.out.println(grt);
	}

	private static int greatest(int a, int b, int c){
		if(a>b){
			if(a>c){
				return a;
			}
			else{
				return c;
			}
		}

		else if(b>c){
			return b;
		}

		else{
			return c;
		}
	}
}