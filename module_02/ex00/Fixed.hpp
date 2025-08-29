#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>

class Fixed {
private:
    int              value;            // fixed-point raw value
    static const int fractionalBits;   // number of fractional bits (always 8)

public:
    Fixed(); //to be able to create the eight empty Fixeds of PhoneBook
    Fixed(const int& val,
            const std::string& fbits,
            const std::string& nick,
            const std::string& phone,
            const std::string& secret);
	Fixed(const Fixed& other);            // OCF, to create and copy
    Fixed& operator=(const Fixed& other); // OCF, to copy to one that already exits
    ~Fixed(); //it will be called by its own

    bool isEmpty() const; //including const after indicates that the method does not modify the object

    void setFirstName(const std::string& v); // & is used to pass a reference in order to safe mem
	//the assignation will be made inside the function
    void setLastName(const std::string& v);
    void setNickname(const std::string& v);
    void setPhoneNumber(const std::string& v); //with const you can not modify the reference that is passed
    void setDarkestSecret(const std::string& v);
 
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickname() const;
    const std::string& getPhoneNumber() const;
    const std::string& getDarkestSecret() const;
};

#endif