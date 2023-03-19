#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

class Polynomial {
  protected:
    double *degCoeff;
    int capacity;
  public:
    Polynomial(); //done.
    Polynomial(int capacity); //done.
    Polynomial(Polynomial const &p); //done.
    Polynomial(double* arr, size_t size); //done.
    Polynomial(float* arr, size_t size); //done.
    Polynomial(std::initializer_list<double> list); //done.
    ~Polynomial(void); //done.
    inline int getCapacity() const { return capacity; } //done.
    inline double* getDegCoeff() const { return degCoeff; } //done.
    long double countX(double x) const; //done.
    void setCoefficient(int deg, double coef); //done.
    double& at(int);
    double& operator[](int); //done.
    operator std::string();
    bool operator==(Polynomial const &P2); //done.
    bool operator!=(Polynomial const &P2); //done.
    bool operator>(Polynomial const &P2); //done.
    bool operator>=(Polynomial const &P2); //done.
    bool operator<(Polynomial const &P2); //done.
    bool operator<=(Polynomial const &P2); //done.
    Polynomial operator+(Polynomial const &P2); //done.
    Polynomial operator+=(Polynomial const &P2); //done.
    Polynomial operator-(Polynomial const &P2); //done.
    Polynomial operator-=(Polynomial const &P2); //done.
    Polynomial operator*(Polynomial const &P2); //done.
    Polynomial operator*=(Polynomial const &P2); //done.
    Polynomial operator/(Polynomial const &P2); //done.
    Polynomial operator%(Polynomial const &P2); //done.
    Polynomial operator++(void); //done.
    Polynomial operator--(void); //done.
    Polynomial operator-(void); //done.
    void operator=(Polynomial const &p); //done.

    //void operator=(Polynomial const &p);
    void print() const;
};

#endif