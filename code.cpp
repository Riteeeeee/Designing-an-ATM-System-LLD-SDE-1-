#include <bits/stdc++.h>
using namespace std;

/* ---------- ENUMS ---------- */

enum class ATMState {
    IDLE,
    CARD_INSERTED,
    AUTHENTICATED
};

enum class TransactionType {
    WITHDRAW,
    DEPOSIT,
    BALANCE
};

/* ---------- ENTITIES ---------- */

class Account {
    int pin;
    double balance;

public:
    Account(int p, double b) : pin(p), balance(b) {}

    bool validatePin(int inputPin) const {
        return pin == inputPin;
    }

    double getBalance() const {
        return balance;
    }

    bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        return true;
    }

    void deposit(double amount) {
        balance += amount;
    }
};

class Card {
    int cardNumber;
    Account* account;

public:
    Card(int num, Account* acc) : cardNumber(num), account(acc) {}

    Account* getAccount() const {
        return account;
    }
};

class CashDispenser {
    double totalCash;

public:
    CashDispenser(double cash) : totalCash(cash) {}

    bool dispense(double amount) {
        if (amount > totalCash) return false;
        totalCash -= amount;
        return true;
    }

    void accept(double amount) {
        totalCash += amount;
    }
};

/* ---------- ATM ---------- */

class ATM {
    ATMState state;
    Card* currentCard;
    CashDispenser dispenser;

public:
    ATM(double initialCash)
        : state(ATMState::IDLE),
          currentCard(nullptr),
          dispenser(initialCash) {}

    void insertCard(Card* card) {
        currentCard = card;
        state = ATMState::CARD_INSERTED;
        cout << "Card inserted\n";
    }

    bool authenticate(int pin) {
        if (state != ATMState::CARD_INSERTED) return false;

        if (currentCard->getAccount()->validatePin(pin)) {
            state = ATMState::AUTHENTICATED;
            cout << "Authentication successful\n";
            return true;
        }
        cout << "Invalid PIN\n";
        return false;
    }

    void checkBalance() {
        if (state != ATMState::AUTHENTICATED) return;
        cout << "Balance: "
             << currentCard->getAccount()->getBalance() << endl;
    }

    void withdraw(double amount) {
        if (state != ATMState::AUTHENTICATED) return;

        Account* acc = currentCard->getAccount();
        if (!acc->withdraw(amount) || !dispenser.dispense(amount)) {
            cout << "Withdrawal failed\n";
            return;
        }
        cout << "Please collect your cash\n";
    }

    void deposit(double amount) {
        if (state != ATMState::AUTHENTICATED) return;
        currentCard->getAccount()->deposit(amount);
        dispenser.accept(amount);
        cout << "Deposit successful\n";
    }

    void ejectCard() {
        currentCard = nullptr;
        state = ATMState::IDLE;
        cout << "Card ejected\n";
    }
};

/* ---------- MAIN (Demo) ---------- */

int main() {
    Account acc(1234, 5000);
    Card card(1111, &acc);
    ATM atm(10000);

    atm.insertCard(&card);
    atm.authenticate(1234);
    atm.checkBalance();
    atm.withdraw(2000);
    atm.deposit(1000);
    atm.checkBalance();
    atm.ejectCard();

    return 0;
}
