# **Chapter 2 - Fundamental Concepts**

## **Binary to Decimal Conversion**

### **Binary Representation**
#### **Decimal number**
* Place is a power of 10.
* Values are selected from set {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}.
* A decimal number is simply a combination of its digits multiplied by powers of 10.
#### **Binary number**
* Place is a power of 2.
* The value is selected from the set {0, 1}.
* A binary number is simply a combination of its digits multiplied by powers of 2. 
* The powers of 2 are 1, 2, 4, 8, 16, ...
#### Example
* Decimal number
```
Convert: (4723)10

(4 * 10^3) + (7 * 10^2) + (2 * 10^1) + (3 * 10^0)
4000 + 700 + 20 + 3 = 4723
```
* Binary Base
```
Convert: (1101)2

(1 * 2^3) + ( * 2^2) + (0 * 2^1) + (1 * 2^0)
8 + 4 + 0 + 1 = 13
```

### **Binary to decimal conversion**
* An 8-bit number is called a **byte**
* A 16-bit number is called a **halfword**
* A 32-bit number is called a **word**

#### **Binary to decimal converter**
calculate a value by multipling each coefficient by its placeholder values and summing all of them together.
```
Convert: (1101)2

(1 *2^7) + (0 *2^6) + (1 *2^5) + (0 *2^4) + (0 *2^3) + (1 *2^2) + (0 *2^1) + (0 *2^0)
128 + 0 + 32 + 0 + 0 + 4 + 0 + 0 = 164
```
#### **Decimal to binary converter**
Using consecutive divisions:
1. Start by dividing the decimal number by 2
2. Iteratively divide the result (the quotient) by 2 until the answer is 0
```
Convert: 154

154/2 = 77      remainder = 0
77/2 = 38       remainder = 1
38/2 = 19       remainder = 0
19/2 = 9        remainder = 1
9/2 = 4         remainder = 1
4/2 = 2         remainder = 0
2/2 = 1         remainder = 0
1/2 = 0         remainder = 1

Binary equivalent 10011010
```

### **Hexadecimal notation**