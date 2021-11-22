# Heap Benchmarker

This is a framework for developers to develop, run and compare heap allocation strategies of their own, or ones already provided in the code.

## Benchmarks provided:

### Baseline:

- Standard new/delete -> O(n) context switches

### BaselineArray:

- Allocates all of the necessary memory using new[] and delete[]. Much faster than Baseline, but doesn't give the user any abstraction for when an object is allocated/deallocated.

### Improved:

- Allocates all of the necessary memory upon instantiation using PoolList tool. Basically new[] with minimal overhead for alloc/dealloc functionality and self-cleanup.
## Tools provided:

#### Data Types

- Point: A data type containing two doubles.

#### Heap Strategies

- PoolList: Templated memory pool implementation using a singly linked list for allocation/deallocation.
  - Construct by specifying *item count* of your type. Allocates (*item count \* sizeof(item)*) and manages this memory by a singly linked list of unions, that are used as pointers when they are in the list, and as the type when a user constructs this type in pointer returned by *allocate()*.
  - Destructs by always holding the pointer returned by memory allocation in _head and freeing it at the end of the object's lifetime.
  - *allocate()*: Returns pointer to an available chunk of memory based on T. Returns nullptr if depleted.
  - *deallocate(T\*& ptr)*: Pass in a reference to a T pointer to return the chunk of memory it points to back to the PoolList obj. Additionally sets ptr to nullptr.

    ```
    //Typical Usage 1:
    T* ptr;
    {
      pool::PoolList<T> mempool(*arbitrary item count*);
      ptr = new (mempool.allocate()) T();

      //No unmanaged memory allocation; Do not delete ptr.
    }
    //mempool cleaned, no memory allocated, but ptr still points to invalidated address
    
    //Typical Usage 2:
    {
      pool::PoolList<T> mempool(*arbitrary item counut*);
      ptr = new (mempool.allocate()) T();
      mempool.deallocate(ptr);
      //Memory chunk returned to mempool. Next call of allocate() will use this same address to construct an object T.
    }
    //mempool cleaned, no memory allocated, but ptr now points to nullptr instead
    ```
    
## In progress

- The ability to create SharedBenchmark with runtime specified Benchmark type and data type and push to BenchmarkManager. (Tricky with templates, maybe enum mapping, but more dev responsibility)
- Fragmentation analyzer of benchmarks. For example, a report of the Improved benchmark would (hopefully) report a fragmentation percentage of 0, since memory is only allocated based on (*item count \* sizeof(item)*).
- Type checking when a client constructs their object in address returned by *allocate()*
- Benchmark-dependent operator overloading, so the user does not have to use placement new.
- Edge case not considered yet: Handling some T pointer passed into deallocate(T*& ptr) that was not originally in the PoolList.

## Some example runs

Allocating 50,000,000 **Point** objects

*Baseline vs. Improved*

<img src="https://user-images.githubusercontent.com/91897211/142797963-9e2b93cf-c40a-46b4-a196-985d7cc25674.png" width="400">

