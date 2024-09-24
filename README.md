# C Abstract Data Types

This is a series of abstract data types implemented using the standard C library, along with some executable tests to demonstrate their functionality. These types are designed to make use of dynamic memory allocation to store either an array or a series of nodes, with the data stored being a void*. It's important to note that whilst the ADT will be dynamically allocated along with the pointers given, the thing the memory assignment of the value at the pointer is up to the programmer.

Anyone is welcome to use these structures in any way they which, this was just something to get me used to C syntax again. In some ways these implementations are not complete, and chances are you'll have to edit them in some way for your specific use case, but hey it's a start.

## ADTS

#### ArrayList

This is a list data type that makes use of a dynamic array as the underlying collection. It can be found in the `src/array_list` directory.

#### LinkedList

This is a list data type that makes use of a series of node structures as the underlying collection. It can be found in the `src/linked_list` directory.

#### Stack

This is a LIFO data type that makes use of a series of node structures as the underlying collection. It can be found in the `src/stack` directory.

#### Queue

This is a FIFO data type that makes use of a series of node structures as the underlying collection. It can be found in the `src/queue` directory.

#### ArrayStack and ArrayQueue

These ADTs are the dynamic array collection equivalent of the ones above. It's unlikely that anyone would ever really use these, but I just thought I'd complete the set.

## Testing

In order to test the ADTs, there are additional programs inside the `test` directory. The `Makefile` uses these programs to create executables in the `bin` directory which can output the different tests performed for a given ADT and it's results. 

``` bash
$ make                 # will produce the all the executables
$ bin/ArrayListTest    # runs the ArrayList tests
$ bin/QueueTest        # and so on
```

