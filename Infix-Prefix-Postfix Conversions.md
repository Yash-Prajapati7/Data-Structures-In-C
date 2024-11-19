### 1. **Infix to Postfix Conversion**
   - **Infix**: The standard arithmetic expression where the operator is in between operands. For example, `A + B`.
   - **Postfix** (also known as Reverse Polish Notation - RPN): Operators follow the operands. For example, `AB+`.

   #### **Steps/Rules:**
   1. Use a stack to hold operators and parentheses.
   2. Operands (variables/numbers) are directly added to the output.
   3. Push operators to the stack based on their precedence.
   4. When an operator is encountered:
      - If it has higher precedence than the operator at the top of the stack, push it onto the stack.
      - Otherwise, pop operators from the stack to the output until you find one of lower precedence or the stack is empty.
   5. If a left parenthesis `(` is encountered, push it onto the stack.
   6. If a right parenthesis `)` is encountered, pop from the stack to the output until a left parenthesis `(` is encountered (discard the `(`).
   7. Pop remaining operators from the stack to the output.

   **Example Formula:**  
   Infix: `A + B * C`  
   Postfix: `A B C * +`

### 2. **Infix to Prefix Conversion**
   - **Infix**: Operators are between operands.
   - **Prefix** (also known as Polish Notation): Operators precede their operands. For example, `+AB`.

   #### **Steps/Rules:**
   1. Reverse the infix expression (left to right to right to left).
   2. Change `(` to `)` and vice versa.
   3. Follow the same rules as converting infix to postfix.
   4. Once you get the postfix expression for the reversed infix, reverse the result to get the prefix.

   **Example Formula:**  
   Infix: `A + B * C`  
   Reverse Infix: `C * B + A`  
   Postfix of Reverse Infix: `C B * A +`  
   Reverse Postfix to get Prefix: `+ A * B C`

### 3. **Postfix to Infix Conversion**
   - **Postfix**: Operators follow their operands.
   - **Infix**: Operators are between operands.

   #### **Steps/Rules:**
   1. Use a stack to store operands.
   2. Scan the postfix expression from left to right.
   3. When an operand is encountered, push it onto the stack.
   4. When an operator is encountered:
      - Pop the top two operands from the stack.
      - Form a new infix expression by placing the operator between the operands.
      - Push the resulting expression back onto the stack.
   5. The expression at the top of the stack is the result.

   **Example Formula:**  
   Postfix: `A B C * +`  
   Infix: `A + (B * C)`

### 4. **Postfix to Prefix Conversion**
   - **Postfix**: Operators follow their operands.
   - **Prefix**: Operators precede their operands.

   #### **Steps/Rules:**
   1. Use a stack to store operands.
   2. Scan the postfix expression from left to right.
   3. When an operand is encountered, push it onto the stack.
   4. When an operator is encountered:
      - Pop the top two operands from the stack.
      - Form a new prefix expression by placing the operator before the operands.
      - Push the resulting expression back onto the stack.
   5. The expression at the top of the stack is the result.

   **Example Formula:**  
   Postfix: `A B C * +`  
   Prefix: `+ A * B C`

### 5. **Prefix to Infix Conversion**
   - **Prefix**: Operators precede their operands.
   - **Infix**: Operators are between operands.

   #### **Steps/Rules:**
   1. Use a stack to store operands.
   2. Scan the prefix expression from right to left.
   3. When an operand is encountered, push it onto the stack.
   4. When an operator is encountered:
      - Pop the top two operands from the stack.
      - Form a new infix expression by placing the operator between the operands.
      - Push the resulting expression back onto the stack.
   5. The expression at the top of the stack is the result.

   **Example Formula:**  
   Prefix: `+ A * B C`  
   Infix: `A + (B * C)`

### 6. **Prefix to Postfix Conversion**
   - **Prefix**: Operators precede their operands.
   - **Postfix**: Operators follow their operands.

   #### **Steps/Rules:**
   1. Use a stack to store operands.
   2. Scan the prefix expression from right to left.
   3. When an operand is encountered, push it onto the stack.
   4. When an operator is encountered:
      - Pop the top two operands from the stack.
      - Form a new postfix expression by placing the operands before the operator.
      - Push the resulting expression back onto the stack.
   5. The expression at the top of the stack is the result.

   **Example Formula:**  
   Prefix: `+ A * B C`  
   Postfix: `A B C * +`

### **Precedence & Associativity Rules:**
   - **Operator Precedence** (from highest to lowest):
     1. Parentheses: `()`
     2. Exponents: `^`
     3. Multiplication/Division/Modulus: `*`, `/`, `%`
     4. Addition/Subtraction: `+`, `-`
   - **Associativity**:
     - Left to Right for `+`, `-`, `*`, `/`
     - Right to Left for `^`
