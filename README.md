# Designing-an-ATM-System-LLD
1️⃣ Restate the Problem

Design an ATM system that allows users to:

Insert a card

Authenticate using PIN

Check balance

Withdraw cash

Deposit cash

Exit safely

👉 “Am I understanding the problem correctly?”

2️⃣ Clarifying Questions

Ask quickly:

Single ATM or multiple ATMs?
→ Assume single ATM

Multiple accounts per card?
→ One account per card

Cash types?
→ Fixed denominations

Concurrent users?
→ One user at a time

Persistent storage?
→ In-memory

Network / bank server?
→ Simulated locally

3️⃣ Requirements
🔹 Functional Requirements

Card insertion

PIN authentication

Balance inquiry

Cash withdrawal

Cash deposit

Exit / eject card

🔹 Non-Functional Requirements

Secure PIN validation

Accurate balance updates

Prevent invalid withdrawals

Maintain consistency

4️⃣ Assumptions

One ATM machine

One user at a time

No real bank server

In-memory data

No encryption (just simulation)

5️⃣ Core Entities
Entities

ATM

Card

Account

Transaction

CashDispenser

Enums

TransactionType (WITHDRAW, DEPOSIT, BALANCE)

ATMState (IDLE, CARD_INSERTED, AUTHENTICATED)

6️⃣ Storage / Data Design
Account
- accountNumber
- balance
- pin

ATM
- totalCash
- currentState

Transactions
- transactionId
- type
- amount

7️⃣ Class Responsibility Breakdown
ATM

Controls flow

Maintains state

Account

Stores balance & PIN

Balance operations

Card

Links to account

CashDispenser

Dispenses & accepts cash

Transaction

Logs actions

✔️ Clear separation of concerns

8️⃣ API / Method Design
bool authenticate(int pin);
double checkBalance();
bool withdraw(double amount);
void deposit(double amount);
void ejectCard();

9️⃣ Design Patterns (Bonus)

State Pattern → ATM states

Strategy (future) → different authentication methods

Mention lightly.

🔟 Flow Explanation (MOST IMPORTANT)
Withdrawal Flow

User inserts card

ATM validates card

User enters PIN

Authentication succeeds

User selects withdraw

Balance checked

Cash dispensed

Balance updated

Card ejected

🟢 This proves correctness.

1️⃣1️⃣ Data Structure Choices
Purpose	Structure	Reason
Accounts	unordered_map	O(1) lookup
Transactions	vector	Ordered log
ATM State	enum class	Safe states
1️⃣2️⃣ Language (C++)

enum class

unordered_map

Clean STL

No raw pointers misuse

1️⃣3️⃣ Naming & Readability

authenticate()

withdrawCash()

checkBalance()

Professional and readable.
