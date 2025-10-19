#ifndef FIXED_HPP
#define FIXED_HPP

#include <iosfwd> // std::ostream (forward)

class Fixed {
private:
    int              value;                // entero crudo = real * 2^fractionalBits
    static const int fractionalBits;       // definido en el .cpp (siempre 8)

public:
    // OCF
    Fixed();                    // 0.0           -> "Default constructor called"
    Fixed(const Fixed& other);  // copia         -> "Copy constructor called"
    Fixed& operator=(const Fixed& other); //     -> "Copy assignment operator called"
    ~Fixed();                   //               -> "Destructor called"

    // ex01
    Fixed(const int n);         // value = n << 8   -> "Int constructor called"
    Fixed(const float f);       // value = roundf(f * 256) -> "Float constructor called"

    // Acceso crudo
    int   getRawBits() const;
    void  setRawBits(int raw);

    // Conversiones
    float toFloat() const;      // value / 256.0f
    int   toInt()   const;      // value >> 8

    // --- ex02: Operadores ---

    // Comparación
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // Aritmética
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const; // Si rhs == 0, puede crashear (permitido)

    // ++ / -- (ϵ = 1/(1<<fractionalBits) ⇒ incrementar/decrementar 1 en crudo)
    Fixed& operator++();    // pre-incremento
    Fixed  operator++(int); // post-incremento
    Fixed& operator--();    // pre-decremento
    Fixed  operator--(int); // post-decremento

    // min / max
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& x);

#endif
