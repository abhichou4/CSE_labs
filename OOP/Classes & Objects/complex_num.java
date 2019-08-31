import java.util.*;

class Complex{

	int real, imag;

	void init(int a, int b){
		real = a;
		imag = b;
	}

	void display(){
		System.out.println(real + "+i"+ imag);
	}

	Complex add(Complex c2){
		Complex r = new Complex();
		r.real = real + c2.real;
		r.imag = imag + c2.imag;
		return r;
	}

	Complex subtract(Complex c2){
		Complex r = new Complex();
		r.real = Math.abs(real - c2.real);
		r.imag = Math.abs(imag - c2.imag);
		return r;
	}
	
}

class complex_test{

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
		int real, imag;
		Complex c1 = new Complex();
		Complex c2 = new Complex();

		System.out.println("Enter real and imaginary parts for c1");
		real = sc.nextInt();
		imag = sc.nextInt();
		c1.init(real,imag);

		System.out.println("Enter real and imaginary parts for c2");
		real = sc.nextInt();
		imag = sc.nextInt();
		c2.init(real,imag);

		c1.display();
		c2.display();

		Complex res = new Complex();
		res = c1.add(c2);
		res.display();
		res = c1.subtract(c2);
		res.display();
	}
}