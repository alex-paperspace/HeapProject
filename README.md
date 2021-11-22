# Heap Benchmarker

This is a framework for developers to develop, run and compare heap allocation strategies of their own, or ones already provided in the code.

## Benchmarks provided:

### Baseline:

- Standard new/delete -> O(n) context switches

### BaselineArray:

- Allocates all of the necessary memory using new[] and delete[]. Fastest for single type, but doesn't give the user any abstraction for when an object is allocated/deallocated and doesn't allow for multiple types.

### Improved_OneT:

- Allocates all of the necessary memory upon instantiation using FixedPool tool. Basically new[] with minimal overhead for alloc/dealloc functionality and self-cleanup.

### Improved_MultiT:

- Allocates all of the necessary memory upon instantiation using FixedPool tool and the size of the largest template type. This allows us to allocate and deallocate different data types in the same memory pool.

## Tools provided:

#### Data Types

- Point: A data type containing two doubles.

#### Heap Strategies

- FixedPool: Variadically templated memory pool implementation using a singly linked list for allocation/deallocation.
  - Construct by specifying *item count* of your type(s). Allocates (*item count \* sizeof(largest template type)*) and manages this memory by a singly linked list of unions, that are used as pointers when they are in the list, and as one of the template type(s) when a user constructs a type in pointer returned by *allocate()*.
  - Destructs by always holding the pointer returned by memory allocation in _head and freeing it at the end of the object's lifetime.
  - *allocate()*: Returns pointer to an available chunk of memory. Returns nullptr if depleted.
  - *deallocate(T\*& ptr)*: Pass in a reference to a T pointer to return the chunk of memory it points to back to the PoolList obj. Additionally sets ptr to nullptr.

    ```
    //Typical Usage 1:
    T* ptr;
    {
      pool::FixedPool<T> mempool(*arbitrary item count*);
      ptr = new (mempool.allocate()) T();

      //No unmanaged memory allocation; Do not delete ptr.
    }
    //mempool cleaned, no memory allocated, but ptr still points to invalidated address
    
    //Typical Usage 2:
    {
      pool::FixedPooL<T> mempool(*arbitrary item counut*);
      ptr = new (mempool.allocate()) T();
      mempool.deallocate(ptr);
      //Memory chunk returned to mempool. Next call of allocate() will use this same address to construct an object T.
    }
    //mempool cleaned, no memory allocated, but ptr now points to nullptr instead
    
    //More Example Usages:
    int* ptr1;
    double* ptr2;
    {
      pool::FixedPool<int, double> mempool(*arbitrary item count*);
      ptr1 = new (mempool.allocate()) int(5);
      ptr2 = new (mempool.allocate()) double(6.8);
    }
    ```
    
  - Typically, if you want to use several data types, these data types should be similarly sized as large differences will result in more fragmentation depending on how much of each type is constructed in memory.
- Pool_OneT: It's the same as FixedPool except for it not being variadic and only accepting one templated type. 
  - For a reason unconfirmed yet, FixedPool with one type offers noticably worse performance than using non-variadic FixedPool with one type. This is expected to be because of the overhead involved with std::variant inside Node (data-dependent and compiler-dependent performance with FixedPool).
    
## In progress

- [ ] The ability to create SharedBenchmark with runtime specified Benchmark type and data type and push to BenchmarkManager. (Tricky with templates, maybe enum mapping, but more dev responsibility)
- [ ] Fragmentation analyzer of benchmarks. For example, a report of the Improved benchmark would (hopefully) report a fragmentation percentage of 0, since memory is only allocated based on (*item count \* sizeof(item)*).
- [x] Variable size data types (compile time and possibly runtime), this is when fragmentation can potentially start to occur.
- [ ] Type checking when a client constructs their object in address returned by *allocate()*
- [ ] Benchmark-dependent operator overloading, so the user does not have to use placement new.
- [ ] Edge case not considered yet: Handling some T pointer passed into deallocate(T*& ptr) that was not originally in the PoolList.

## Some example runs

Allocating 50,000,000 **Point** objects

<img src="https://user-images.githubusercontent.com/91897211/142930298-78dc53e6-40fc-4fda-b69f-3a080b16c77d.png" width="400">

The key things to note:
- Improved_MultiT suffers minimal performance loss over BaselineArray whilst offering:
  - A memory managed solution
  - Allocation/deallocation abstraction
  - The ability to use many types 
