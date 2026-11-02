# Question_№1

The method must be static because we need to use it without creating an object first. 
The constructor is private, so we cannot create a Logger object directly.

# Question_№2

They are deleted because we need only one Logger object. 
If copying was allowed, we could create more objects and this would break the Singleton pattern.

# Question_№3

The static object is created when we call getInstance() for the first time. 
It is destroyed when the program ends normally. 
The file is closed in the destructor.

# Question_№4

On the second call, the filename is ignored because the Logger object already exists. 
We need setFile() to change the log file without creating a new object.

# Question_№5

Each message has a level. The program writes a message only if its level is less than or equal to the current level.
When the level is DEBUG, all four messages are written.
When we change it to WARNING, only ERROR and WARNING messages are written. INFO and DEBUG messages are ignored.

Example from the log:

[2026-10-29 15:08:54] [ERROR] Error 1
[2026-10-29 15:08:54] [WARNING] Warning 1
[2026-10-29 15:08:54] [INFO] Info 1
[2026-10-29 15:08:54] [DEBUG] Debug 1
[2026-10-29 15:08:54] [ERROR] Error 2
[2026-10-29 15:08:54] [WARNING] Warning 2
[2026-10-29 15:08:54] [WARNING] Same instance

# Question_№6

Yes. Since C++11, the initialization of a local static variable is thread safe. 
If several threads call getInstance() at the same time, the object will still be created only once.