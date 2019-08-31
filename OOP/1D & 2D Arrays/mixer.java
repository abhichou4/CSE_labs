import java.util.*;

class Mixer{

	int[] arr;

	void accept(){
		int n;
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter number of elements in array\n");
		n = sc.nextInt();
		arr = new int[n];
		System.out.print("Enter sorted array in increasing order\n");
		arr[0]=sc.nextInt();
		for(int i=1; i<arr.length; i++){
			arr[i]=sc.nextInt();
			if(arr[i]<arr[i-1]){
				System.out.println("Enter in increasing order\n");
				break;
			}
		}
	}

	Mixer mix(Mixer a2){
		int i=0, j=0, k=0;
		Mixer m = new Mixer();
		m.arr = new int[arr.length+a2.arr.length];
		while(i<arr.length && j<a2.arr.length){
			if(arr[i]<a2.arr[j]){
				m.arr[k]=arr[i];
				i++;
			}
			else if(a2.arr[j]<arr[i]){
				m.arr[k]=a2.arr[j];
				j++;
			}
			else{
				m.arr[k]=arr[i];
				i++;j++;
			}
			k++;
		}

		if(i < arr.length){
			System.arraycopy(arr, i, m.arr, k, (arr.length-i));
		}
		if(j < a2.arr.length){
			System.arraycopy(a2.arr, j, m.arr, k, (a2.arr.length-j));
		}
		return m;
	}

	void display(){
		for(int i:arr){
			System.out.println(i);
		}
	}
}

class mixer{
	public static void main(String[] args){
		Mixer m1 = new Mixer();
		Mixer m2 = new Mixer();
		m1.accept();
		m2.accept();
		Mixer m3 = new Mixer();
		m3 = m1.mix(m2);

		m1.display();
		m2.display();
		m3.display();
	}
}