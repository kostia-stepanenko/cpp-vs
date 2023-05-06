# Main algorithm explained

We will emulate restaurane work using two main classes: Restaurant and Order.

## Order 
Order class wil have two main attributes: 'startTime' and 'duration'.
Order class will calculate expected time of order using function 'getExpectedEndTime'.

## Restaurant
Restaurant class will store all order using `queue<Order>` as main data structure.
We will add new orders to queue using `addOrder` function.
The main logic related to restaurant work will be implemented inside `execute` function.

We will also implement `convertTime` function to convert time ranges outside of 24 hours range.

## Input/Output
We will read values for 'N', 'T' and orders from console input (cin).
All emulated events will be printed to standard output (cout).


