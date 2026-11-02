# Question_№1

The default constructor creates an object with an empty string.
The std::string constructor creates an object using a string variable.
The const char* constructor creates an object using text.
The copy constructor creates a new object using another object. It copies its value but gives the new object a different id.

# Question_№2

The copy constructor is called when we create a new object from another object.

For example:

TrackedString d=c;
TrackedString e(c);

In both cases, a new object is created. We need the copy constructor to copy the value and give each object its own id.

# Question_№3

The copy constructor creates a new object, but the copy assignment operator changes an object that already exists.
For example, TrackedString d=c; calls the copy constructor because d is a new object.
But a = b; calls the assignment operator because both objects already exist.
The assignment operator changes only the value. The id stays the same.

# Question_№4

The objects are destroyed in the opposite order of their creation.
Objects a,b,c,d was created.
When the block ends, they are destroyed in this order: d,c,b,a
It happens because C++ destroys local objects in reverse order.

Example from the log:

[2026-10-30 15:56:22] [INFO] [default ctor] id=1 this=0x16b20b228 alive=1
[2026-10-30 15:56:22] [INFO] [cstr ctor] id=2 this=0x16b20b208 value="hello" alive=2
[2026-10-30 15:56:22] [INFO] [string ctor] id=3 this=0x16b20b1d0 value="world" alive=3
[2026-10-30 15:56:22] [INFO] [copy ctor] id=4 this=0x16b20b1b0 from id=3 alive=4
[2026-10-30 15:56:22] [INFO] [copy assign] id=1 this=0x16b20b228 from id=2
[2026-10-30 15:56:22] [INFO] [dtor] id=4 this=0x16b20b1b0 alive=3
[2026-10-30 15:56:22] [INFO] [dtor] id=3 this=0x16b20b1d0 alive=2
[2026-10-30 15:56:22] [INFO] [dtor] id=2 this=0x16b20b208 alive=1
[2026-10-30 15:56:22] [INFO] [dtor] id=1 this=0x16b20b228 alive=0
[2026-10-30 15:56:22] [INFO] totalCreated = 4
[2026-10-30 15:56:22] [INFO] aliveCount = 0

# Question_№5

"totalCreated" shows how many objects were created during the program.
"aliveCount" shows how many objects are still alive.
After the block, "totalCreated" = 4 and "aliveCount" = 0.
"totalCreated" stays 4 because four objects were created.
"aliveCount" becomes 0 because all objects were destroyed. This means there are no TrackedString objects left alive.