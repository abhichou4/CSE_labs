import java.util.*;

class Complex  {
    int real;
    int imag;

    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(int real, int imag) {
        this.real = real;
        this.imag = imag;
    }

    Complex add(Complex c2){
		Complex r = new Complex();
		r.real = real + c2.real;
		r.imag = imag + c2.imag;
		return r;
	}

	Complex subtract(Complex c2) {
		Complex r = new Complex();
		r.real = Math.abs(real - c2.real);
		r.imag = Math.abs(imag - c2.imag);
		return r;
    }
    
    static void display(Complex ref) {
        System.out.print(ref.real + "i" + ref.imag);
    }
}

class complex{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter real and imaginary part of complex numbers\n");
        Complex c1 = new Complex(sc.nextInt(), sc.nextInt());
        Complex c2 = new Complex(sc.nextInt(), sc.nextInt());
        Complex res = new Complex();
        res = c1.add(c2); 
        System.out.print("("+c1.real+"+i"+c1.imag+")" + "("+c2.real+"+i"+c2.imag+")" + "=" + res.real + "+i" + res.imag);
    }
}