import java.util.*;

class Prime{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=1; i<n; i++){
			if(isPrime(i)==true){
				System.out.println(i);
			}
		}
	}

	private static boolean isPrime(int a){
		int flag = 1;
		for(int i=2; i<a; i++){
			if(a%i==0){
				flag =0;
			}
		}
		return(flag==0 ? false:true);
	}
}