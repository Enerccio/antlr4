#include "Allocation.h"

#ifdef ANTLR4CPP_CUSTOM_ALLOCATION

namespace antlr4 {

thread_local ANTLR4Allocator *threadAllocator = nullptr;
ANTLR4Allocator *staticAllocator = nullptr;
thread_local ANTLR4Deallocator *threadDeallocator = nullptr;
ANTLR4Deallocator *staticDeallocator = nullptr;

void *antlr4Allocate(size_t size) {
    if (threadAllocator)
        return threadAllocator->allocate(size);
    if (staticAllocator)
        return staticAllocator->allocate(size);
    throw std::bad_alloc();
}

void antlr4Deallocate(void *ptr) {
    if (ptr) {
        if (threadDeallocator)
            threadDeallocator->deallocate(ptr);
        if (staticDeallocator)
            staticDeallocator->deallocate(ptr);
    }
}

void setGlobalAllocator(ANTLR4Allocator *allocator, ANTLR4Deallocator *deallocator) {
    staticAllocator = allocator;
    staticDeallocator = deallocator;
}

void setThreadLocalAllocator(ANTLR4Allocator *allocator, ANTLR4Deallocator *deallocator) {
    threadAllocator = allocator;
    threadDeallocator = deallocator;
}

}

#endif
