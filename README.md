# GCC Bank – C++ Command-Line Banking System

**Gauteng City College | Faculty of Information Technology**
Introduction to Programming – Practical Assignment

## About the Project

GCC Bank is a C++ command-line banking system. A customer logs in with an account number and PIN, then uses a menu to perform basic banking operations. The menu stays available until the customer chooses **Exit**.

The program supports:

- Deposits
- Withdrawals
- Cash transfers between accounts
- Balance enquiries

The program stores three sample customers in arrays. Each customer has a name, account number, PIN and opening balance. This is sample data for demonstrating the assignment. It is not connected to a real bank or banking database.

## Getting Started

The only source file is `main.cpp`. Compile and run it with any C++ compiler

## Menu

```
========== GCC BANK ==========
1. Deposit
2. Withdraw
3. Send Cash
4. Check Balance
5. Exit
==============================
```

## Sample User Accounts

These demonstration accounts are created in the source code so the program can be tested.

| Name | Account Number | Sample PIN | Opening Balance |
|---|---|---|---|
| Thabo Mokoena | 1001 | 1234 | R5 000.00 |
| Lerato Dlamini | 1002 | 2345 | R3 500.00 |
| Sipho Nkosi | 1003 | 3456 | R2 500.00 |

## How the Program Meets the Assignment Requirements

| Requirement | How the program meets it |
|---|---|
| Menu and loop | A `do-while` loop repeatedly displays the menu until option 5 is selected. |
| Deposit | Accepts an amount greater than R0.00 and adds it to the logged-in user's balance. |
| Withdraw | Accepts only a positive amount that does not exceed the available balance. |
| Send Cash | Checks that the recipient account exists, rejects transfers to the same account, and checks available funds. |
| Check Balance | Displays the logged-in customer's name, account number and current balance. |
| At least 3 users | Three sample customers are stored in parallel arrays. |
| At least 5 functions | The program uses multiple functions, including `displayMenu()`, `deposit()`, `withdraw()`, `sendCash()`, `checkBalance()` and `findAccount()`. |
| Validation | Invalid menu choices, non-numeric entries, invalid amounts and unknown recipient accounts produce clear messages. |

## Code Overview

**Functions**

- `displayMenu()` returns the user's menu choice.
- `findAccount()` searches for an account and returns its array position, or -1 if it cannot be found.
- `deposit()` and `withdraw()` receive the current balance and return the updated balance.
- `sendCash()` receives the sender's position and the account and balance arrays.
- `checkBalance()` displays account details.

**Decision making:** A `switch` statement handles the five menu options. `if` statements check whether an account exists, whether a PIN is correct, whether a transfer is being made to the same account, and whether an amount is valid.

**Loops:** A `do-while` loop keeps the banking menu running until the user selects option 5. `for` loops search through the three account records in `findAccount()`. `while` loops re-prompt the user when an amount or numeric input is invalid.

## Variables and Data Types

| Variable | Data type | Purpose |
|---|---|---|
| `names[]` | string array | Stores the names of the three customers. |
| `accountNumbers[]` | int array | Stores each customer's account number. |
| `pins[]` | int array | Stores each customer's sample PIN. |
| `balances[]` | double array | Stores each customer's current account balance. |
| `numberOfUsers` | const int | Stores the number of customer records. |
| `userIndex` / `recipientIndex` | int | Stores the position of a customer in the arrays. |
| `choice` | int | Stores the selected menu option. |
| `amount` | double | Stores a deposit, withdrawal or transfer amount. |

`double` is used for balances and transaction amounts because money can include cents. Whole-number values such as account numbers, PINs and menu choices use `int`. Customer names use `string`.

## Testing

The test session logged in as Thabo Mokoena (account 1001), deposited R500.00, withdrew R200.00, transferred R300.00 to account 1002, checked the balance and exited.

| Test | Action / input | Expected result | Observed result |
|---|---|---|---|
| 1 | Login: account 1001, PIN 1234 | Login successful for Thabo Mokoena. | Passed |
| 2 | Deposit R500.00 | Balance increases from R5 000.00 to R5 500.00. | Passed |
| 3 | Withdraw R200.00 | Balance decreases to R5 300.00. | Passed |
| 4 | Send R300.00 to account 1002 | Sender balance becomes R5 000.00 and recipient balance increases by R300.00. | Passed |
| 5 | Check balance | Displays Thabo's current balance of R5 000.00. | Passed |
| 6 | Choose option 5 | Displays goodbye message and ends the program. | Passed |
| 7 | Enter unknown recipient account | Transfer is rejected with an account-not-found message. | Code check |
| 8 | Attempt withdrawal greater than balance | System requests a smaller amount and prevents an overdraft. | Code check |

The main transaction flow was executed in the compiled program. Tests 7 and 8 are code checks and should also be tried during the lecturer's demonstration.

