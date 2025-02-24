Tests:
1. Negative number input should not be allowed:
Please enter the amount of cents you have. Enter EOF to quit
-1
Cent amount must be positive and less than 1 billion dollars worth. Please try again

2. Cent amounts greater than or equal to 1 billion should not be allowed
Please enter the amount of cents you have. Enter EOF to quit
1000000000000
Cent amount must be positive and less than 1 billion dollars worth. Please try again

3. Getting an input of 0 is an edge case that requires special handling, since you do
not use "zero" anywhere else in the calculations.
Please enter the amount of cents you have. Enter EOF to quit
0
Memoizing 0: zero dollars
zero dollars

4. Since input is in cents, we want to handle any input less than 100 cents separately,
since dollar amounts require extra words
1
Memoizing 1: one cent
one cent

5. Testing "teen" amounts with cents
14
Memoizing 14: fourteen cents
fourteen cents

6. Testing cent amount that is not in the teens, but is divisible by 10
30
Memoizing 30: thirty cents
thirty cents

7. Testing cent amount that is not in the teens, but is not divisible by 10
45
Memoizing 45: forty five cents
forty five cents

8. Testing an even dollar amount
100
Memoizing 100: one dollar
one dollar

9. Testing dollar amount with cents
923
Memoizing 923: nine dollars and twenty three cents
nine dollars and twenty three cents

10. Testing dollar amounts using the "teens" word bank
1119
Memoizing 1119: eleven dollars and nineteen cents
eleven dollars and nineteen cents

11. Testing dollar amounts using the "tens" word bank
5000
Memoizing 5000: fifty dollars
fifty dollars

12. Testing hundreds amount
20000
Memoizing 20000: two hundred dollars
two hundred dollars

13. Testing thousands amount
