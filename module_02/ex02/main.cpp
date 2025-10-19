#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

static void section(const char* title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {
    std::cout << std::fixed << std::setprecision(4);

    // Datos base
    Fixed a(1.5f);
    Fixed b(2);          // 2.0
    Fixed c(-3.25f);
    Fixed d(4.0f);

    section("Valores iniciales");
    std::cout << "a = " << a << "\n"
              << "b = " << b << "\n"
              << "c = " << c << "\n"
              << "d = " << d << "\n";

    // -------------------- Aritméticos --------------------
    section("Operadores aritméticos +  -  *  /");
    Fixed sum  = a + b;
    Fixed diff = a - b;
    Fixed prod = b * d;        // 2 * 4 = 8
    Fixed quot1 = d / b;       // 4 / 2 = 2
    Fixed quot2 = a / b;       // 1.5 / 2 = 0.75
    Fixed mix   = (a + d) * (b - c) / b; // (1.5+4)*(2-(-3.25))/2

    std::cout << "a + b      = " << sum  << "\n";
    std::cout << "a - b      = " << diff << "\n";
    std::cout << "b * d      = " << prod << "\n";
    std::cout << "d / b      = " << quot1 << "\n";
    std::cout << "a / b      = " << quot2 << "\n";
    std::cout << "(a+d)*(b-c)/b = " << mix << "\n";

    // -------------------- ++ / -- --------------------
    section("Pre y post incremento/decremento");
    Fixed x(1.0f);
    std::cout << "x          = " << x << "\n";
    std::cout << "++x        = " << ++x << "   (x tras ++x = " << x << ")\n";
    std::cout << "x++        = " << x++ << "   (x tras x++ = " << x << ")\n";
    std::cout << "--x        = " << --x << "   (x tras --x = " << x << ")\n";
    std::cout << "x--        = " << x-- << "   (x tras x-- = " << x << ")\n";

    section("Encadenado con pre-incremento (devuelve referencia)");
    Fixed y(0.0f);
    std::cout << "y          = " << y << "\n";
    (++y) = Fixed(10.0f);        // posible porque pre++ devuelve Fixed&
    std::cout << "(++y)=10   -> y = " << y << "\n";
    // Nota: (y++) = 20 NO compila (post++ devuelve por valor, no referencia).

    // -------------------- min / max (no-const) --------------------
    section("min/max no-const (devuelven Fixed&)");
    Fixed p(1.0f), q(2.0f);
    Fixed& m = Fixed::min(p, q);
    Fixed& M = Fixed::max(p, q);
    std::cout << "p = " << p << ", q = " << q << "\n";
    std::cout << "min(p,q)   = " << m << "\n";
    std::cout << "max(p,q)   = " << M << "\n";

    std::cout << "Asigno min(p,q)=99.0  (modifica al mínimo real)\n";
    m = Fixed(99.0f);
    std::cout << "p = " << p << ", q = " << q << "\n";

    // -------------------- min / max (const) --------------------
    section("min/max const (devuelven const Fixed&)");
    const Fixed cp(3.5f), cq(3.5f + 0.25f); // 3.5 y 3.75
    const Fixed& cm = Fixed::min(cp, cq);
    const Fixed& cM = Fixed::max(cp, cq);
    std::cout << "cp = " << cp << ", cq = " << cq << "\n";
    std::cout << "min(cp,cq) = " << cm << "\n";
    std::cout << "max(cp,cq) = " << cM << "\n";
    // cm = Fixed(0.0f); // NO compila: cm es const Fixed&

    section("Listo");
    return 0;
}
