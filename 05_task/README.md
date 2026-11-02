# Question_№1

Some operators are better as member functions, for example the assignment operator "=" because it changes the current object.
Operators like "==", "!=", "<" and "+" can be free functions because they work with two objects.
The output operator "<<" is also better as a free function because its left operand is an output stream.

# Question_№2

The output operator is usually a free function because the left operand is "std::ostream".
We can't add a new member function to "std::ostream", so we define "operator<<" outside our class.
This allows us to write something like "std::cout << a".

# Question_№3

"friend" allows a function outside the class to access its private fields.
I used "friend" for all five operators because they need to access the private field "value".
For example, "operator==" compares "a.value" and "b.value".
Without "friend", these functions could not access "value" directly.

# Question_№4

When auto c = a + b; is executed, one new "TrackedString" object is created.
The "+" operator joins the values of a and b and returns a new object with the value "helloworld".
The copy constructor is not called. We can see this in the log:

[2026-11-02 18:08:43] [INFO] [string ctor] id=1 this=0x16f963228 value="hello" alive=1
[2026-11-02 18:08:43] [INFO] [cstr ctor] id=1 this=0x16f963228
[2026-11-02 18:08:43] [INFO] [string ctor] id=2 this=0x16f963208 value="world" alive=2
[2026-11-02 18:08:43] [INFO] [cstr ctor] id=2 this=0x16f963208
[2026-11-02 18:08:43] [INFO] [operator <<]
[2026-11-02 18:08:43] [INFO] [operator <<]
[2026-11-02 18:08:43] [INFO] [operator ==]
[2026-11-02 18:08:43] [INFO] [operator !=]
[2026-11-02 18:08:43] [INFO] [operator <]
[2026-11-02 18:08:43] [INFO] [operator +]
[2026-11-02 18:08:43] [INFO] [string ctor] id=3 this=0x16f9631e8 value="helloworld" alive=3
[2026-11-02 18:08:43] [INFO] [operator <<]
[2026-11-02 18:08:43] [INFO] [dtor] id=3 this=0x16f9631e8 alive=2
[2026-11-02 18:08:43] [INFO] [dtor] id=2 this=0x16f963208 alive=1
[2026-11-02 18:08:43] [INFO] [dtor] id=1 this=0x16f963228 alive=0

RVO means Return Value Optimization. It allows the compiler to create the result directly without making an extra copy. 