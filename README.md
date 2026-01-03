# Designing-an-ATM-System-LLD
📌 Problem Statement

Design an ATM system that allows users to:

Insert a card

Authenticate using a PIN

Check account balance

Withdraw cash

Deposit cash

Exit safely (card ejection)

Confirmation:
“Am I understanding the problem correctly?”

❓ Clarifying Questions & Assumptions
Question	Assumption
Single ATM or multiple ATMs?	Single ATM
Multiple accounts per card?	One account per card
Cash denominations?	Fixed denominations
Concurrent users?	One user at a time
Persistent storage?	In-memory
Bank server / network?	Simulated locally
📋 Requirements
🔹 Functional Requirements

Card insertion

PIN authentication

Balance inquiry

Cash withdrawal

Cash deposit

Card ejection / exit

🔹 Non-Functional Requirements

Secure PIN validation

Accurate balance updates

Prevent invalid withdrawals

Maintain system consistency

🧠 Assumptions

One ATM machine

One active user session

No real bank server

In-memory data storage

No encryption (simulation only)

🧱 Core Design Components
🧩 Entities
ATM

Controls user flow

Maintains ATM state

Card

Links to a single account

Account

Stores balance and PIN

Handles balance operations

CashDispenser

Dispenses and accepts cash

Transaction

Logs each user action

🔢 Enums
enum class TransactionType {
    WITHDRAW,
    DEPOSIT,
    BALANCE
};

enum class ATMState {
    IDLE,
    CARD_INSERTED,
    AUTHENTICATED
};

🗄️ Data / Storage Design
Account

accountNumber

balance

pin

ATM

totalCash

currentState

Transaction

transactionId

type

amount

🧩 Class Responsibility Breakdown
ATM

Controls workflow

Handles state transitions

Account

Stores balance & PIN

Updates balance

Card

Connects ATM to account

CashDispenser

Manages physical cash

Transaction

Records all operations

✔️ Clear separation of concerns

🔌 API / Method Design
bool authenticate(int pin);
double checkBalance();
bool withdraw(double amount);
void deposit(double amount);
void ejectCard();

🧠 Design Patterns Used (Bonus)

State Pattern
→ Handles ATM states (IDLE, CARD_INSERTED, AUTHENTICATED)

Strategy Pattern (Future Scope)
→ Different authentication methods (PIN, OTP, Biometrics)

Mention lightly in interviews.

🔄 Flow Explanation (Most Important)
💵 Withdrawal Flow

User inserts card

ATM validates card

User enters PIN

Authentication succeeds

User selects Withdraw

Balance is checked

Cash is dispensed

Balance is updated

Card is ejected

🟢 This proves system correctness

📊 Data Structure Choices
Purpose	Data Structure	Reason
Accounts	unordered_map	O(1) lookup
Transactions	vector	Ordered logging
ATM State	enum class	Type safety
💻 Language & Tech Stack

Language: C++

Features Used:

enum class

unordered_map

STL containers

No raw pointer misuse

✨ Naming & Readability

authenticate()

withdrawCash()

checkBalance()

✔️ Professional, readable, interview-friendly
