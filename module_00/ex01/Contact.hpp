#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact(); //to be able to create the eight empty contacts of PhoneBook
    Contact(const std::string& first,
            const std::string& last,
            const std::string& nick,
            const std::string& phone,
            const std::string& secret);
	Contact(const Contact& other);            // OCF, to create and copy
    Contact& operator=(const Contact& other); // OCF, to copy to one that already exits
    ~Contact(); //it will be called by its own

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