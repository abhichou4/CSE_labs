import java.util.*;

class factorial{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int r = sc.nextInt();
		System.out.println(combination(n,r));
	}

	private static int fact(int a){
		if(a==0){
			return 1;
		}
		else{
			return a*fact(a-1);
		}
	}

	private static int combination(int n, int r){
		return fact(n)/(fact(r)*fact(n-r));
	}
}