import java.util.*;

class Armstrong{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if(isArmstrong(n)){
			System.out.println("Number is Armstrong");
		}
		else{
			System.out.println("Number is not Armstrong");
		}
	}

	private static boolean isArmstrong(int a){
		int dig=0, sum=0, num=a;
		while(a!=0){
			dig += 1;
			a = (int)a/10;
		}
		a=num;
		while(a!=0){
			sum += Math.pow((a%10),dig);
			a = (int)a/10;
		}

		if(num==sum){
			return true;
		}
		else{
			return false;
		}
	}
}