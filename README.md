## Icethinker

The repository's name was derived from the programming  
language used, C++. If you spell the language's name  
in English, it would be "see plus plus", taking note  
of this, the author, Miguel, put some humour in it.  
In order to see more , you need eyes and by a homonym,  
the "ice" with the "thinker" denotes "the thinker's C++".  

#### In the Box

Source codes written for the problems from the book.  
It may contain unnecessary comments or nothing at all  
and other instructions not mainly from the book.  

So how memory allocation work ?

For me , what great about C++ is the use of pointers,
it's a compound data type that holds the address of a value.
So when we declare a pointer (an address to a value) , that
value is in a type (it may be void or other primitive types)
then on the right hand operand is "new" keyword. Where
instructing the computer to allocate a "new memory" / or 
"new space" in the field in this address which the pointer
holds. So everytime we need to get the value of any type
in the space(memory) , we need the pointer and the means
to get the value and that is by the use of dereferencing.

*variable -- go to the address it points then its value
&*variable -- go to the address it points then then return it.
&**variable -- go to the address it points then its value
which is an address then return it.

Crosslinking:
Where two pointers holds/points to the same address of a value. It can
occurs in some cases including the Deep Copy which involves two pointer
and a variable while Shallow Copy involve structure's and classes'data
member and it's somewhat a larger scale of deep copy.