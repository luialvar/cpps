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

    int   getRawBits() const;
    void  setRawBits(int raw);

    float toFloat() const;      // value / 256.0f
    int   toInt()   const;      // value >> 8
};

std::ostream& operator<<(std::ostream& os, const Fixed& x);

#endif
