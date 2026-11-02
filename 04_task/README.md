# Question №_1

When we create x, the default constructor calls the std::string constructor first. The string constructor initializes the object, and then the default constructor writes its message.
For y, the const char* constructor also calls the std::string constructor first.
We can see this in the log:

[2026-11-02 17:16:24] [INFO] [string ctor] id=1 this=0x16b57f238 value="" alive=1
[2026-11-02 17:16:24] [INFO] [default ctor] id=1 this=0x16b57f238
[2026-11-02 17:16:24] [INFO] [string ctor] id=2 this=0x16b57f218 value="test" alive=2
[2026-11-02 17:16:24] [INFO] [cstr ctor] id=2 this=0x16b57f218
[2026-11-02 17:16:24] [INFO] [dtor] id=2 this=0x16b57f218 alive=1
[2026-11-02 17:16:24] [INFO] [dtor] id=1 this=0x16b57f238 alive=0

The id and address are the same for each pair of constructor calls. This shows that only one object is created each time.

# Question №_2

Delegation calls another constructor of the same class. This constructor initializes the object.
A helper method like init() is just a regular function. It is called after the object and its fields have already been initialized.

# Question №_3

Delegation must happen before the constructor body starts because the object needs to be initialized first.
The initializer list allows us to call another constructor before running the code inside the constructor body.