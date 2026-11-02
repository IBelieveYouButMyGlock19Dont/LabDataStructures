# Question_№1

In WrapperA, two TrackedString objects are created. First, the default constructor is called. Then a temporary object is created.
In WrapperB, only one object is created because we use an initializer list.
We can see this difference in the logs.

# Question_№2

In WrapperA, str is created first using the default constructor. Then "TrackedString(s)" creates a temporary object.
The assignment operator is called because we assign the value of this temporary object to str.
In WrapperB, str is initialized directly, so we do not need an extra object or assignment.

# Question_№3

The temporary object is created to give a value to str in WrapperA.
It is destroyed right after the assignment is finished.
We can see this in the log:

[2026-10-30 16:48:46] [INFO] [default ctor] id=1 this=0x16f657228 alive=1
[2026-10-30 16:48:46] [INFO] [string ctor] id=2 this=0x16f657100 value="hello" alive=2
[2026-10-30 16:48:46] [INFO] [copy assign] id=1 this=0x16f657228 from id=2
[2026-10-30 16:48:46] [INFO] [dtor] id=2 this=0x16f657100 alive=1
[2026-10-30 16:48:46] [INFO] [dtor] id=1 this=0x16f657228 alive=0

# Question_№4

No.Fields are initialized in the order they are declared in the class, not in the order written in the initializer list.
For example, if a is declared before b, then a will be initialized first, even if b comes first in the initializer list.

# Question_№5

Class-type fields are initialized using their default constructor.
Primitive fields, like int or double, are not automatically initialized to zero in this case. They can have undefined values if we do not initialize them.
It means that initializer lists are useful. They allow us to initialize fields directly.