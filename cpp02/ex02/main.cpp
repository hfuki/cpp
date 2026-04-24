#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    // 1. 基本的なコンストラクタとインクリメントのテスト (PDFの例)
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "--- PDF Test ---" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    // 2. 算術演算子のテスト
    std::cout << "\n--- Arithmetic Operators ---" << std::endl;
    Fixed c(10);
    Fixed d(2.5f);
    std::cout << "c: " << c << ", d: " << d << std::endl;
    std::cout << "c + d = " << (c + d) << std::endl; // 12.5
    std::cout << "c - d = " << (c - d) << std::endl; // 7.5
    std::cout << "c * d = " << (c * d) << std::endl; // 25
    std::cout << "c / d = " << (c / d) << std::endl; // 4

    // 3. 比較演算子のテスト
    std::cout << "\n--- Comparison Operators ---" << std::endl;
    std::cout << "c > d  : " << (c > d) << std::endl;  // 1 (true)
    std::cout << "c < d  : " << (c < d) << std::endl;  // 0 (false)
    std::cout << "c >= d : " << (c >= d) << std::endl; // 1
    std::cout << "c <= d : " << (c <= d) << std::endl; // 0
    std::cout << "c == d : " << (c == d) << std::endl; // 0
    std::cout << "c != d : " << (c != d) << std::endl; // 1

    // 4. デクリメントのテスト
    std::cout << "\n--- Decrement Operators ---" << std::endl;
    Fixed e(1);
    std::cout << "e   : " << e << std::endl;    // 1
    std::cout << "--e : " << --e << std::endl;  // 0.996094 (1 - 1/256)
    std::cout << "e-- : " << e-- << std::endl;  // 0.996094
    std::cout << "e   : " << e << std::endl;    // 0.992188

    // 5. Min / Max 関数のテスト (const / 非const 両方)
    std::cout << "\n--- Min / Max Functions ---" << std::endl;
    Fixed f(42);
    Fixed g(24);
    const Fixed h(100);
    const Fixed i(200);

    std::cout << "min(f, g)       : " << Fixed::min(f, g) << std::endl; // 24
    std::cout << "max(f, g)       : " << Fixed::max(f, g) << std::endl; // 42
    std::cout << "min(const h, i) : " << Fixed::min(h, i) << std::endl; // 100
    std::cout << "max(const h, i) : " << Fixed::max(h, i) << std::endl; // 200

    return 0;
}
