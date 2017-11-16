//polyn.cpp

class polyn {
	int * coefs;
	int dg;
public:
	polyn();                   // default ctor
	polyn(int degree);         // ctor(int) creates a polyn of degree 
	                           // == input integer
	polyn(const polyn& original);       // copy ctor
	int degree(void);          // returns number of terms
	int term(int pos);             // returns coeff at (int)
	void set_term(int c, int pos);   // set coefficient at position
	operator+(const polyn& other);   // adds two polynomials
	operator-(const polyn& other);   // subtracts two polynomials
	operator*(const polyn& other);   // multiplies two polynomials
	operator*(int);            // scalar multiplicaiton of polynomial
};

polyn::polyn() {
	this->coefs = 0;
	this->dg = 0;
}

polyn::polyn(int degree) {
	this->coefs = new int[degree];
	this->dg = degree;
}

polyn::polyn(const polyn& original) {
	this->dg = original.degree();
	this->coefs = new int[original.degree];
	for(short i=0;i<this->dg;i++){
		this->coefs[i] = other.term(i);
	}
}

int polyn::degree () {
	return this->dg;
}

int polyn::term (int pos) {
	if (pos < degree) {
		return coefs[pos];
	} else {
		return 0;
	}
}

void polyn::set_term(int c, int pos) {
	if (this->dg > pos) {
		this->coefs[pos] = c;
	} else {
		int * new_coefs = new int[pos+1];
		for(short i=0;i<this->dg;i++) {
			new_coefs[i] = this->coefs[i];
		}
		this->dg = pos+1;
		free (this->coefs);
		this->coefs = new_coefs;
		this->set_term(c,pos);
	}
}


polyn polyn::operator+(const polyn& other) {
	int x = (this->degree()>other.degree)?this->degree():other.degree();
	polyn R = new polyn(x);
	for(short i=0;i<x;i++){
		r.set_term(this->term[i] + other.term[i],i);
	}
	return R;
}
	
polyn polyn::operator-(const polyn& other) {
	int x = (this->degree()>other.degree)?this->degree : other.degree();
	polyn R = polyn(x);
	for(short i=0;i<x;i++){
		R.set_term(this->term[i] - other.term[i],i);
	}
	return R;
}
	
polyn polyn::operator*(const polyn& other) {
	polyn R = polyn(this->degree() + other.degree());
	for(short i=0;i<this->degree();i++){
		for(short j=0;j<other.degree;j++){
			R.set_term((this->term[i]*other.term[j]) + R.term(i+j),i+j);
		}
	}
	return R;
}

polyn polyn::operator*(int scalar) {
	polyn R = polyn(this);
	for (short i=0;i<this->degree();i++) {
		R.set_term(scalar*this->term(i),i);
	}
	return R;
}
