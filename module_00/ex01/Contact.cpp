#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string& first,
                 const std::string& last,
                 const std::string& nick,
                 const std::string& phone,
                 const std::string& secret)
: firstName(first),
  lastName(last),
  nickname(nick),
  phoneNumber(phone),
  darkestSecret(secret) {}

  //() is used when the object does not previously exist, 
  //= is used when the object exists
  Contact::Contact(const Contact& other)
: firstName(other.firstName),
  lastName(other.lastName),
  nickname(other.nickname),
  phoneNumber(other.phoneNumber),
  darkestSecret(other.darkestSecret) {}
Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        firstName     = other.firstName;
        lastName      = other.lastName;
        nickname      = other.nickname;
        phoneNumber   = other.phoneNumber;
        darkestSecret = other.darkestSecret;
    }
    return *this; //this is a pointer to the object
}


Contact::~Contact() {}

bool Contact::isEmpty() const {
    return firstName.empty() || lastName.empty()
        || nickname.empty() || phoneNumber.empty()
        || darkestSecret.empty();
}
//strange the way the assignation is made, because you pass a reference
//but you don't need to do any desreferation
void Contact::setFirstName(const std::string& v)   { firstName = v; }
void Contact::setLastName(const std::string& v)    { lastName = v; }
void Contact::setNickname(const std::string& v)    { nickname = v; }
void Contact::setPhoneNumber(const std::string& v) { phoneNumber = v; }
void Contact::setDarkestSecret(const std::string& v) { darkestSecret = v; }

const std::string& Contact::getFirstName()   const { return firstName; }
const std::string& Contact::getLastName()    const { return lastName; }
const std::string& Contact::getNickname()    const { return nickname; }
const std::string& Contact::getPhoneNumber() const { return phoneNumber; }
const std::string& Contact::getDarkestSecret() const { return darkestSecret; }
