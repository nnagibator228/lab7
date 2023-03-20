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
    /*
    * \brief getCapacity()
    * метод возвращает вместительность Polynomial класса.
    * \return capacity
    */
    inline int getCapacity() const { return capacity; } //done.
    /*
    * \brief getDegCoeff()
    * метод возвращает степень Polynomial.
    * \return degCoeff
    */
    inline double* getDegCoeff() const { return degCoeff; } //done.
    /*
    * \brief countX() 
    * метод подсчитывает значение полинома, если x - заданное число.
    * \param x - подстовляемое x
    * \return degCoeff
    */
    long double countX(double x) const; //done.
    /*
    * \breif setCoefficent(int deg, double coef)
    * метод назначает коэфиценты при x степени deg
    * \param deg - искомая степень
    * \param coef - подставляемый коэфицент
    * \return void
    */
    void setCoefficient(int deg, double coef); //done.
    /*
    * \brief at(int index)
    * \param index - индекс коэфицента.
    * \return ссылка на коэфицент.
    */
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
    /*
    * \brief print()
    * метод для отрисовки полинома в виде k_1*x^n + k_2*x^n-1 + ... + k_n-1*x^n + k_n; 
    */
    void print() const;
};

#endif