#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <stdexcept>
#include "../modules/doctest.h"
#include "Polynomial.hpp"

TEST_CASE("testing constructors. ") {

  SUBCASE("testing default constructor. ") {
    Polynomial p1 = Polynomial();
    CHECK((p1.getCapacity() == 0 && sizeof(p1.getDegCoeff()) == 8) == true);
  }

  SUBCASE("testing capacity constructor. ") {
    const int len = 3;
    Polynomial p1 = Polynomial(len);
    CHECK((p1.getCapacity() == len && sizeof(p1.getDegCoeff()) == 8) == true);
  }

  SUBCASE("testing copy constructor. ") {
    const int len = 3;
    Polynomial p1 = Polynomial(len);
    Polynomial p2 = Polynomial(p1);
    CHECK((p2.getCapacity() == len && sizeof(p2.getDegCoeff()) == 8) == true);
  }

  SUBCASE("testing from double* c array constructor. ") {
    const size_t len = 3;
    double t_arr[len] = {1.122, 3.144, 2.178};
    Polynomial p1 = Polynomial(t_arr, 3);
    CHECK((p1.getCapacity() == len-1) == true);
    for(int i = 0; i < len; ++i){
      CHECK((p1.getDegCoeff()[i] == t_arr[i]) == true);
    }
  }

  SUBCASE("testing from float* c array constructor. ") {
    const size_t len = 3;
    float t_arr[len] = {1.12232, 3.16544, 2.1748};
    Polynomial p1 = Polynomial(t_arr, 3);
    CHECK((p1.getCapacity() == len-1) == true);
    for(int i = 0; i < len; ++i){
      CHECK((p1.getDegCoeff()[i] == (double) t_arr[i]) == true);
    }
  }

  SUBCASE("testing from double initializer list constructor. ") {
    const size_t len = 3;
    double t_arr[len] = {1.122, 3.144, 2.178};
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    CHECK((p1.getCapacity() == len-1) == true);
    for(int i = 0; i < len; ++i){
      CHECK((p1.getDegCoeff()[i] == t_arr[i]) == true);
    }
  }

}

TEST_CASE("testing countX method. ") {
  const size_t len = 3;
  double t_arr[len] = {1.122, 3.144, -2.178};
  Polynomial p1 = Polynomial({1.122, 3.144, -2.178});
  long double result = 0;
  for(int i=0;i<len;i++)
      result+=(t_arr[i])*(std::pow(3, i));
  CHECK((p1.countX(3) == result) == true);
}

TEST_CASE("testing setCoefficient method. ") {
  
  SUBCASE("testing setCoefficient with existing index. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    p1.setCoefficient(1, 17.289);
    CHECK((p1.getDegCoeff()[1] == 17.289) == true);
  }

  SUBCASE("testing setCoefficient with nonexisting index. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    p1.setCoefficient(4, 17.289);
    CHECK((p1.getDegCoeff()[4] == 17.289 && p1.getDegCoeff()[3] == 0) == true);
  }
  
}

TEST_CASE("testing at method. ") {
  
  SUBCASE("testing at method with existing index. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    CHECK((p1.at(1) == 3.144) == true);
  }

  SUBCASE("testing at method with nonexisting index. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    CHECK_THROWS_AS(p1.at(4), std::exception);
  }
  
}

TEST_CASE("testing [] operator overload. ") {
  
  SUBCASE("testing [] operator overload with existing index. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    CHECK((p1[1] == 3.144) == true);
  }

  SUBCASE("testing [] operator overload with nonexisting index. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    CHECK((p1[4] == 0) == true);
  }
  
}

TEST_CASE("testing std::string() conversion overload. ") {
  Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
  std::string c1 = (std::string) p1;
  std::cout << c1 << std::endl;
  CHECK((true) == true);
}

TEST_CASE("testing comparison operators overload. ") {
  
  SUBCASE("testing != operator overload. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    Polynomial p2 = Polynomial({4.829, 5.982, 6.751});
    CHECK((p1 != p2) == true);
  }

  SUBCASE("testing == operator overload. ") {
    const size_t len = 3;
    float t_arr[len] = {1.12232, 3.16544, 2.1748};
    Polynomial p1 = Polynomial(t_arr, 3);
    Polynomial p2 = Polynomial(t_arr, 3);
    CHECK((p1 == p2) == true);
  }
  

  SUBCASE("testing > operator overload. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    Polynomial p2 = Polynomial({4.829, 5.982, 6.751});
    CHECK((p2 > p1) == true);
  }

  SUBCASE("testing >= operator overload with > vals. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    Polynomial p2 = Polynomial({4.829, 5.982, 6.751});
    CHECK((p2 >= p1) == true);
  }

  SUBCASE("testing >= operator overload with == vals. ") {
    const size_t len = 3;
    float t_arr[len] = {1.12232, 3.16544, 2.1748};
    Polynomial p1 = Polynomial(t_arr, 3);
    Polynomial p2 = Polynomial(t_arr, 3);
    CHECK((p2 >= p1) == true);
  }
  

  SUBCASE("testing < operator overload. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    Polynomial p2 = Polynomial({4.829, 5.982, 6.751});
    CHECK((p2 > p1) == true);
  }

  SUBCASE("testing <= operator overload with < vals. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    Polynomial p2 = Polynomial({4.829, 5.982, 6.751});
    CHECK((p1 <= p2) == true);
  }

  SUBCASE("testing <= operator overload with == vals. ") {
    const size_t len = 3;
    float t_arr[len] = {1.12232, 3.16544, 2.1748};
    Polynomial p1 = Polynomial(t_arr, 3);
    Polynomial p2 = Polynomial(t_arr, 3);
    CHECK((p1 <= p2) == true);
  }

}

TEST_CASE("testing binary & unary operations overload. ") {

  SUBCASE("testing + operator overload. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    Polynomial p2 = Polynomial({4.829, 5.982, 6.751});
    Polynomial p3 = p1 + p2;
    CHECK((p3.getDegCoeff()[0] == p1.getDegCoeff()[0] + p2.getDegCoeff()[0] && p3.getDegCoeff()[1] == p1.getDegCoeff()[1] + p2.getDegCoeff()[1] && p3.getDegCoeff()[2] == p1.getDegCoeff()[2] + p2.getDegCoeff()[2]) == true);
  }

  SUBCASE("testing += operator overload. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    Polynomial p0 = Polynomial(p1);
    Polynomial p2 = Polynomial({4.829, 5.982, 6.751});
    p1 += p2;
    CHECK((p1.getDegCoeff()[0] == p0.getDegCoeff()[0] + p2.getDegCoeff()[0] && p1.getDegCoeff()[1] == p0.getDegCoeff()[1] + p2.getDegCoeff()[1] && p1.getDegCoeff()[2] == p0.getDegCoeff()[2] + p2.getDegCoeff()[2]) == true);
  }
  

  SUBCASE("testing - operator overload. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    Polynomial p2 = Polynomial({4.829, 0, 6.751});
    Polynomial p3 = p1 - p2;
    CHECK((p3.getDegCoeff()[0] == p1.getDegCoeff()[0] - p2.getDegCoeff()[0] && p3.getDegCoeff()[1] == p1.getDegCoeff()[1] - p2.getDegCoeff()[1] && p3.getDegCoeff()[2] == p1.getDegCoeff()[2] - p2.getDegCoeff()[2]) == true);
  }

  SUBCASE("testing -= operator overload. ") {
    Polynomial p1 = Polynomial({1.122, 3.144, 2.178});
    Polynomial p0 = Polynomial(p1);
    Polynomial p2 = Polynomial({4.829, 0, 6.751});
    p1 -= p2;
    CHECK((p1.getDegCoeff()[0] == p0.getDegCoeff()[0] - p2.getDegCoeff()[0] && p1.getDegCoeff()[1] == p0.getDegCoeff()[1] - p2.getDegCoeff()[1] && p1.getDegCoeff()[2] == p0.getDegCoeff()[2] - p2.getDegCoeff()[2]) == true);
  }


  SUBCASE("testing * operator overload. ") {
    Polynomial p1 = Polynomial({1.2, 3.1, 2.3});
    Polynomial p2 = Polynomial({4.0, 5.0, 6.0});
    Polynomial p3 = p1 * p2;
    CHECK((p3.getDegCoeff()[0] == p1.getDegCoeff()[0]*p2.getDegCoeff()[0] && p3.getCapacity() == 4) == true);
  }

  SUBCASE("testing *= operator overload. ") {
    Polynomial p1 = Polynomial({1.2, 3.1, 2.3});
    Polynomial p0 = Polynomial(p1);
    Polynomial p2 = Polynomial({4.0, 5.0, 6.0});
    p1 *= p2;
    CHECK((p1.getDegCoeff()[0] == p0.getDegCoeff()[0]*p2.getDegCoeff()[0] && p1.getCapacity() == 4) == true);
  }

  SUBCASE("testing ++ operator overload. ") {
    Polynomial p3 = Polynomial({1, 4, 2, -3, 1});
    Polynomial p2 = Polynomial(p3);
    ++p3;
    CHECK((p2.getDegCoeff()[0] - p3.getDegCoeff()[0] == -1) == true);
  }

  SUBCASE("testing -- operator overload. ") {
    Polynomial p3 = Polynomial({1, 4, 2, -3, 1});
    Polynomial p2 = Polynomial(p3);
    --p3;
    CHECK((p2.getDegCoeff()[0] - p3.getDegCoeff()[0] == 1) == true);
  }

  SUBCASE("testing - operator overload. ") {
    Polynomial p3 = Polynomial({1, 4, 2, -3, 1});
    Polynomial p1 = Polynomial(p3);
    -p3;
    for(int i = 0; i < p3.getCapacity(); ++i){
      CHECK((p3.getDegCoeff()[i] + p1.getDegCoeff()[i] == 0) == true);
    }
  }

  SUBCASE("testing = operator overload. ") {
    Polynomial p3 = Polynomial({1, 4, 2, -3, 1});
    Polynomial p1 = p3;
    for(int i = 0; i < p3.getCapacity(); ++i){
      CHECK((p3.getDegCoeff()[i] - p1.getDegCoeff()[i] == 0) == true);
    }
  }

  SUBCASE("testing / operator overload. ") {
    Polynomial p1 = Polynomial({1, 4, 2, -3, 1});
    Polynomial p2 = Polynomial({-2, 0, 1});
    Polynomial p3 = p1 / p2;
    p3.print();
    CHECK((p3.getDegCoeff()[0] == 4 && p3.getDegCoeff()[1] == -3 && p3.getDegCoeff()[2] == 1) == true);
  }

  SUBCASE("testing % operator overload. ") {
    Polynomial p1 = Polynomial({1, 4, 2, -3, 1});
    Polynomial p2 = Polynomial({-2, 0, 1});
    Polynomial p3 = p1 % p2;
    p3.print();
    CHECK((p3.getDegCoeff()[0] == 9 && p3.getDegCoeff()[1] == -2) == true);
  }
  
}
