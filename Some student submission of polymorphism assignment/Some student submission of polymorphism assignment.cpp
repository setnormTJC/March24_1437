#include <iostream>
#include <string>

using namespace std;

class PaymentMethod {
public:

    virtual void processPayment() = 0;

    virtual ~PaymentMethod() = default;
};

class CreditCard : public PaymentMethod {
private:
    string cardHolder;
    string cardNumber;
    string expirationDate;
public:
    CreditCard(const string& holder, const string& number, const string& exp)
        : cardHolder(holder), cardNumber(number), expirationDate(exp) {
    }

    void processPayment() override {
        cout << "Processing credit card payment for " << cardHolder << endl;
    }
};

class PayPal : public PaymentMethod {
private:
    string email;
    string password;
public:
    PayPal(const string& emailAddr, const string& pwd)
        : email(emailAddr), password(pwd) {
    }

    void processPayment() override {
        cout << "Processing PayPal payment for " << email << endl;
    }
};

void processAllPayments(PaymentMethod* payments[], int size) {
    for (int i = 0; i < size; ++i) {
        if (payments[i]) {
            payments[i]->processPayment();
        }
    }
}

int main() {
    PaymentMethod* payments[2];
    CreditCard myCard("Joe Blow", "1234567890123456", "12/25");
    payments[0] = &myCard;
    payments[1] = new PayPal("joe@example.com", "securePassword");
    processAllPayments(payments, 2);
    delete payments[1];
    return 0;
}
