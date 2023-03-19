#include <vector>
#include <climits>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <iostream>
#include "Polynomial.hpp"

Polynomial::Polynomial(){
  this->capacity=0;
  this->degCoeff=(double *) malloc(sizeof(double) * (this->capacity+1));
  for(int i = 0; i<=capacity; i++){
    degCoeff[i] = 0;
  }
}

Polynomial::Polynomial(int capacity){
  this->capacity=capacity;
  this->degCoeff=(double *) malloc(sizeof(double) * (this->capacity+1));
  for(int i = 0; i<=capacity; i++){
    degCoeff[i] = 0;
  }
}

Polynomial::Polynomial(Polynomial const &p){
  double *newdeg=(double *) malloc(sizeof(double) * (p.capacity+1));
  for(int i=0;i<=p.capacity;i++)
      newdeg[i]=p.degCoeff[i];
  this->degCoeff=newdeg;
  this->capacity=p.capacity;
}

Polynomial::Polynomial(double* arr, size_t size){
  double *newdeg=(double *) malloc(sizeof(double) * ((size_t) size));
  for(int i = 0; i<size; ++i){
      newdeg[i]=(double) arr[i];
  }
  this->degCoeff=newdeg;
  this->capacity=size-1;
}

Polynomial::Polynomial(float* arr, size_t size){
  double *newdeg=(double *) malloc(sizeof(double) * ((size_t) size));
  for(int i = 0; i<size; ++i){
      newdeg[i]=(double) arr[i];
  }
  this->degCoeff=newdeg;
  this->capacity=size-1;
}

Polynomial::Polynomial(std::initializer_list<double> list){
  int size = static_cast<int>(list.size());
  double *newdeg=(double *) malloc(sizeof(double) * (size));
  int count = 0;
  for (auto element : list){
      newdeg[count] = element;
      ++count;
  }
  this->degCoeff = newdeg;
  this->capacity = size-1;
}

Polynomial::~Polynomial(void) {
  free(degCoeff); 
}

//////////////////////////////////////////////////////////////////

void Polynomial::print() const{    
  for(int i=0;i<=this->capacity;i++){
      if(degCoeff[i]!=0)
          std::cout<<degCoeff[i]<<"*"<<"x"<<"^"<<i<<" ";
  }
  std::cout<<std::endl;
}

void Polynomial::setCoefficient(int deg, double coef){
    if(deg>this->capacity){
        int newcapacity=deg;
        double *newdeg=(double *) malloc(sizeof(double) * (newcapacity+1));
        //Copy the contents from original to new
        for(int i=0; i<=this->capacity; ++i)
            newdeg[i]=this->degCoeff[i];
        for(int i=this->capacity+1; i<=newcapacity; ++i){
            newdeg[i]=0;
        }
        this->degCoeff=newdeg;
        this->capacity=newcapacity;
        this->degCoeff[deg]=coef;
    }
    else{
        degCoeff[deg]=coef;
    }
}

long double Polynomial::countX(double x) const{
  long double result = 0;
  for(int i=0;i<=this->capacity;i++)
      result+=(this->degCoeff[i])*(std::pow(x, i));
  return result;
}

double& Polynomial::at(int index){
  if(index>this->capacity){
    throw std::out_of_range("this coeff isnt set. ");
  }else{
    return this->degCoeff[index];
  }
}

//////////////////////////////////////////////////////////////////

double& Polynomial::operator[](int index){
  if(index>this->capacity){
    double none_val = 0;
    return none_val;
  }else{
    return this->degCoeff[index];
  }
}

Polynomial Polynomial::operator+(Polynomial const &P2){
  int newcap=std::max(this->capacity,P2.capacity);
  Polynomial P3(newcap);
  for(int i=0;i<=newcap;i++){
    if(i<=capacity && i<=P2.capacity)
      P3.degCoeff[i]=this->degCoeff[i]+P2.degCoeff[i];
    else if(i<=capacity)
      P3.degCoeff[i]=this->degCoeff[i];
    else 
      P3.degCoeff[i]=P2.degCoeff[i];
  }
  return P3;
}

Polynomial Polynomial::operator+=(Polynomial const &P2){
  int newcap=std::max(this->capacity,P2.capacity);
  double *newdeg=(double *) malloc(sizeof(double) * (newcap+1));
  for(int i=0; i<=this->capacity; ++i){
    newdeg[i]=this->degCoeff[i];
  }
  for(int i=this->capacity+1; i<=newcap; ++i){
    newdeg[i]=0;
  }
  this->degCoeff = newdeg;
  this->capacity = newcap;
  for(int i=0;i<=newcap;i++){
    if(i<=capacity && i<=P2.capacity)
      this->degCoeff[i]=this->degCoeff[i]+P2.degCoeff[i];
    else if(i<=capacity)
      this->degCoeff[i]=this->degCoeff[i];
    else 
      this->degCoeff[i]=P2.degCoeff[i];
  }
  return *this;
}

Polynomial Polynomial::operator-(Polynomial const &P2){
  int newcap=std::max(this->capacity,P2.capacity);
  Polynomial P3(newcap);
  for(int i=0;i<=newcap;i++){
    if(i<=capacity && i<=P2.capacity)
      P3.degCoeff[i]=this->degCoeff[i]-P2.degCoeff[i];
    else if(i<=capacity)
      P3.degCoeff[i]=this->degCoeff[i];
    else 
      P3.degCoeff[i]=P2.degCoeff[i];
  }
  return P3;
}

Polynomial Polynomial::operator-=(Polynomial const &P2){
  int newcap=std::max(this->capacity,P2.capacity);
  double *newdeg=(double *) malloc(sizeof(double) * (newcap+1));
  for(int i=0; i<=this->capacity; ++i){
    newdeg[i]=this->degCoeff[i];
  }
  for(int i=this->capacity+1; i<=newcap; ++i){
    newdeg[i]=0;
  }
  this->degCoeff = newdeg;
  this->capacity = newcap;
  for(int i=0;i<=newcap;i++){
    if(i<=capacity && i<=P2.capacity)
      this->degCoeff[i]=this->degCoeff[i]-P2.degCoeff[i];
    else if(i<=capacity)
      this->degCoeff[i]=this->degCoeff[i];
    else 
      this->degCoeff[i]=P2.degCoeff[i];
  }
  return *this;
}

Polynomial Polynomial::operator*(Polynomial const &P2){    
  int newcap=this->capacity+P2.capacity;
  Polynomial P3(newcap);
  for(int i=0;i<=this->capacity;i++){
    for(int j=0;j<=P2.capacity;j++){
      P3.degCoeff[i+j]+=this->degCoeff[i]*P2.degCoeff[j];
    }
  }
  return P3;
}

Polynomial Polynomial::operator*=(Polynomial const &P2){
  int newcap=this->capacity+P2.capacity;
  double *newdeg=(double *) malloc(sizeof(double) * (newcap+1));
  for(int i=0; i<=newcap; ++i){
    newdeg[i]=0;
  }
  for(int i=0;i<=this->capacity;i++){
    for(int j=0;j<=P2.capacity;j++){
      newdeg[i+j]+=this->degCoeff[i]*P2.degCoeff[j];
    }
  }
  this->degCoeff = newdeg;
  this->capacity = newcap;
  return *this;
}

Polynomial Polynomial::operator/(Polynomial const &P2){
  
  bool inAlgoritm = true;
  Polynomial temp; 
  Polynomial ob_1; 
  Polynomial ob_2; 
  Polynomial ob_4;
  
  temp.capacity = this->capacity - P2.capacity;
  double *newdeg=(double *) malloc(sizeof(double) * (temp.capacity+1));
  for(int i=0; i<=temp.capacity; ++i){
    newdeg[i]=0;
  }
  temp.degCoeff = newdeg;
  
  ob_1.capacity = this->capacity;
  ob_1.degCoeff = (double *) malloc(sizeof(double) * (this->capacity+1));
  for(int i = 0; i<= ob_1.capacity; ++i){
    ob_1.degCoeff[i] = this->degCoeff[i];
  }
  
  ob_2.capacity = P2.capacity;
  ob_2.degCoeff = (double *) malloc(sizeof(double) * (P2.capacity+1));
  for(int i = 0; i<= ob_2.capacity; ++i){
    ob_2.degCoeff[i] = P2.degCoeff[i];
  }
  
  ob_4.capacity = ob_1.capacity;
  ob_4.degCoeff = (double *) malloc(sizeof(double) * (P2.capacity+1));

  double mnojnik;
  int k = 0;
  int i, j;

  while(inAlgoritm){
    
    for(int i = P2.capacity; i >= 0; --i){
      ob_4.degCoeff[i] = P2.degCoeff[i];
    }

    if(ob_2.capacity < ob_1.capacity){
      for(i = ob_1.capacity, j = ob_2.capacity; i>=0; --i, --j){
        if(j < 0){
          ob_4.degCoeff[i] = 0;
        } else {
          ob_4.degCoeff[i] = ob_2.degCoeff[j];
        }
      }
    }

    mnojnik = ob_1.degCoeff[ob_1.capacity] / ob_4.degCoeff[ob_1.capacity];

    temp.degCoeff[temp.capacity - k] = mnojnik;
    k++;

    for(int i = 0; i <= ob_1.capacity; i++){
      ob_4.degCoeff[i] *= mnojnik;
    }

    for(int i = 0; i <= ob_1.capacity; i++){
      ob_1.degCoeff[i] -= ob_4.degCoeff[i];
    }

    ob_1.capacity--;
    if (ob_2.capacity > ob_1.capacity){
      inAlgoritm = false;
    }
    
  }
  
  return temp;
  
}

Polynomial Polynomial::operator%(Polynomial const &P2){
  bool inAlgoritm = true;

  Polynomial ob_1;
  Polynomial ob_2;
  Polynomial ob_4;

  ob_1.capacity = this->capacity;
  ob_1.degCoeff = (double *) malloc(sizeof(double) * (this->capacity+1));
  for(int i = 0; i<= ob_1.capacity; ++i){
    ob_1.degCoeff[i] = this->degCoeff[i];
  }
  
  ob_2.capacity = P2.capacity;
  ob_2.degCoeff = (double *) malloc(sizeof(double) * (P2.capacity+1));
  for(int i = 0; i<= ob_2.capacity; ++i){
    ob_2.degCoeff[i] = P2.degCoeff[i];
  }
  
  ob_4.capacity = ob_1.capacity;
  ob_4.degCoeff = (double *) malloc(sizeof(double) * (P2.capacity+1));

  double mnojnik;
  int i, j;

  while(inAlgoritm){
    
    for(int i = P2.capacity; i >= 0; --i){
      ob_4.degCoeff[i] = P2.degCoeff[i];
    }

    if(ob_2.capacity < ob_1.capacity){
      for(i = ob_1.capacity, j = ob_2.capacity; i>=0; --i, --j){
        if(j < 0){
          ob_4.degCoeff[i] = 0;
        } else {
          ob_4.degCoeff[i] = ob_2.degCoeff[j];
        }
      }
    }

    mnojnik = ob_1.degCoeff[ob_1.capacity] / ob_4.degCoeff[ob_1.capacity];

    for(int i = 0; i <= ob_1.capacity; i++){
      ob_4.degCoeff[i] *= mnojnik;
    }

    for(int i = 0; i <= ob_1.capacity; i++){
      ob_1.degCoeff[i] -= ob_4.degCoeff[i];
    }

    ob_1.capacity--;
    if (ob_2.capacity > ob_1.capacity){
      inAlgoritm = false;
    }
    
  }

  return ob_1;
  
}

Polynomial Polynomial::operator++(void){
  if(this->capacity>=0){
    this->degCoeff[0]++;
  }

  return *this;
}

Polynomial Polynomial::operator--(void){
  if(this->capacity>=0){
    this->degCoeff[0]--;
  }

  return *this;
}

Polynomial Polynomial::operator-(void){
  if(this->capacity>=0){
    for(int i = 0; i <=this->capacity; ++i){
      this->degCoeff[i] *= -1;
    }
  }

  return *this;
}

void Polynomial::operator=(Polynomial const &p){
  double *newdeg=new double[p.capacity+1];
  for(int i=0;i<p.capacity;i++){
    newdeg[i]=p.degCoeff[i];
  }
  this->degCoeff=newdeg;
  this->capacity=p.capacity;
}

bool Polynomial::operator==(Polynomial const &P2){
  if(P2.capacity == this->capacity){
    for(int i = 0; i <= this->capacity; ++i){
      //std::cout << std::setprecision(7) << "  |-> comparing " << P2.degCoeff[i] << " & " << this->degCoeff[i] << std::endl;
      if((P2.degCoeff[i] == this->degCoeff[i]) == false){
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

bool Polynomial::operator!=(Polynomial const &P2){
  if(P2.capacity == this->capacity){
    for(int i = 0; i <= this->capacity; ++i){
      //std::cout << std::setprecision(7) << "  |-> comparing " << P2.degCoeff[i] << " & " << this->degCoeff[i] << std::endl;
      if((P2.degCoeff[i] == this->degCoeff[i]) == false){
        return true;
      }
    }
    return false;
  } else {
    return true;
  }
}

bool Polynomial::operator>(Polynomial const &P2){
  if(P2.capacity < this->capacity){
    return true;
  }else if (P2.capacity == this->capacity){
    
    for(int i = 0; i <= this->capacity; ++i){
      if(P2.degCoeff[i] >= this->degCoeff[i]){
        return false;
      } 
    }
    return true;
  }else {
    return false;
  }
}

bool Polynomial::operator>=(Polynomial const &P2){
  if(P2.capacity < this->capacity){
    return true;
  }else if (P2.capacity == this->capacity){
    
    for(int i = 0; i <= this->capacity; ++i){
      if(P2.degCoeff[i] > this->degCoeff[i]){
        return false;
      } 
    }
    return true;
  }else {
    return false;
  }
}

bool Polynomial::operator<(Polynomial const &P2){
  if(P2.capacity > this->capacity){
    return true;
  }else if (P2.capacity == this->capacity){
    
    for(int i = 0; i <= this->capacity; ++i){
      if(P2.degCoeff[i] <= this->degCoeff[i]){
        return false;
      } 
    }
    return true;
  }else {
    return false;
  }
}

bool Polynomial::operator<=(Polynomial const &P2){
  if(P2.capacity > this->capacity){
    return true;
  }else if (P2.capacity == this->capacity){
    
    for(int i = 0; i <= this->capacity; ++i){
      if(P2.degCoeff[i] < this->degCoeff[i]){
        return false;
      } 
    }
    return true;
  }else {
    return false;
  }
}

Polynomial::operator std::string() {
	std::stringstream output;
  for(int i=0;i<=this->capacity;i++){
      if(degCoeff[i]!=0)
          output<<degCoeff[i]<<"*"<<"x"<<"^"<<i<<" ";
  }
	return output.str();
}
