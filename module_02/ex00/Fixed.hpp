#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int              value;                 // entero crudo: x * 2^fractionalBits
    static const int fractionalBits = 8;    // nº de bits fraccionales (común y constante)

public:
    // OCF
    Fixed();                    // value = 0
    Fixed(const Fixed& other);  // copia
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // Acceso al valor crudo
    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
