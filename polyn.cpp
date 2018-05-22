//polyn.cpp
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using namespace std;



class polyn {
// a polynomial stored as an integer array
// ex. [1,4,6,7] would be equivalent to 1 + 4x + 6(x^2) + 7(x^3) 
	int * coefs;
	int dg;
public:
	// ctors ----------------------------
	polyn();                               // default ctor
	polyn(int degree);                     // creates a polyn of degree == input integer
	polyn(int degree, int * new_coefs);    // creates a polyn of degree == input integer
                                           // with coefficients of the 
	polyn(const polyn& original);          // copy ctor
	// ----------------------------------

	// math operations ------------------
	polyn& operator+(const polyn& other);  // adds two polynomials
	polyn& operator-(const polyn& other);  // subtracts two polynomials
	polyn& operator*(const polyn& other);  // multiplies two polynomials
	polyn& operator*(int scalar);          // scalar multiplicaiton of polynomial
	polyn& operator/(const polyn& other);  // division of polynomials
	polyn& operator=(const polyn& other);  // assignment operator
	// ----------------------------------
	
	// comparison operators -------------
	bool operator<(const polyn& other) const;    
	bool operator>(const polyn& other) const;     
	bool operator==(const polyn& other) const;    
	bool operator<=(const polyn& other) const;    
	bool operator>=(const polyn& other) const;
	// ----------------------------------


	int operator[](int exp) const;         // retrieve coeff of x^exp
	int degree(void) const;                // returns number of terms
	int term(int pos) const;               // returns coeff at (int)
	void set_term(int c, int pos);         // set coefficient at position    
	void print(ostream& out)const;         // output polynomial to ostream object
	friend std::ostream& operator<< (std::ostream& out, const polyn&  me); 
};


polyn::polyn() {
// default ctor
// PRE : 
// POST: An empty polyn object created
	this->coefs = 0;
	this->dg = 0;
}

polyn::polyn(int degree) {
// PRE : an existing integer >=0
// POST: a polyn object will be created that can hold 
//       polynomials of degree == input parameter
	this->coefs = (int*)malloc(sizeof(int) * degree);
	this->dg = degree;
}

polyn::polyn(int degree, int * new_coefs) {
// PRE :
// POST:
	this->coefs = (int*)malloc(sizeof(int) * degree);
	this->dg = degree;
	for(short i=1;i<=degree;i++) {
		this->set_term(new_coefs[degree-i],i-1);
	}
}


polyn::polyn(const polyn& original) {
// [description]
// PRE :
// POST:
	this->dg = original.degree();
	this->coefs = (int*) malloc(sizeof(int) * original.degree());
	for(short i=0;i<this->dg;i++){
		this->coefs[i] = original.term(i);
	}
}


int polyn::degree () const{
// PRE :
// POST:
	return this->dg;
}



int polyn::term (int pos) const {
// PRE :
// POST:
	if (pos < dg) {
		return coefs[pos];
	} else {
		return 0;
	}
}


void polyn::set_term(int c, int pos) {
// sets coefficient of term (x^pos) to c
// PRE :
// POST:
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


polyn& polyn::operator+(const polyn& other) {
// polynomial addition
// PRE :
// POST:
	int x = (this->degree()>other.degree())?this->degree():other.degree();
	polyn* R = new polyn();
	for(short i=0;i<x;i++){
		R->set_term(this->term(i) + other.term(i),i);
	}
	return *R;
}


polyn& polyn::operator-(const polyn& other) {
// polynomial subtraction
// PRE :
// POST:
	int x = (this->degree()>other.degree())?this->degree():other.degree();
	polyn* R = new polyn();
	for(short i=0;i<x;i++){
		R->set_term(this->term(i) - other.term(i),i);
	}
	return *R;
}


polyn& polyn::operator*(const polyn& other) {
// polynomial multiplication
// PRE :
// POST:
	polyn* R = new polyn(this->degree() + other.degree());
	for(short i=0;i<this->degree();i++){
		for(short j=0;j<other.degree();j++){
			R->set_term((this->term(i)*other.term(j)) + R->term(i+j),i+j);
		}
	}
	return *R;
}



polyn& polyn::operator*(int scalar) {
// scalar multuplication of polynomial
// PRE :
// POST:
	polyn* R = new polyn(*this);
	for (short i=0;i<this->degree();i++) {
		R->set_term(scalar*this->term(i),i);
	}
	return *R;
}

void polyn::print(ostream& out) const {
// to print polynomial to ostream object
// PRE :
// POST: 
// NOTE: does not flush buffer
	for (short i=dg;i>=0;--i) {
		out << this->term(i) << "(x^" << i << ")";
	}
}

std::ostream& operator<< (std::ostream& out, const polyn&  me) {
	me.print(out);
}

polyn& polyn::operator/(const polyn& other) {

}  

polyn& polyn::operator=(const polyn& other){
// [description]
// PRE :
// POST:
}  

bool polyn::operator<(const polyn& other) const{
// [description]
// PRE :
// POST:
}  
    
bool polyn::operator>(const polyn& other) const{
// [description]
// PRE :
// POST:
}  
     
bool polyn::operator==(const polyn& other) const{
// [description]
// PRE :
// POST:
}  
    
bool polyn::operator<=(const polyn& other) const{
// [description]
// PRE :
// POST:
}  
    
bool polyn::operator>=(const polyn& other) const{
// [description]
// PRE :
// POST:
}  

int polyn::operator[](int exp) const{
	return this->term(exp);
}


int main () {
	return 0;
}
