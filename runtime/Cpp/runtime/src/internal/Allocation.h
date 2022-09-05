#pragma once

#ifdef ANTLR4CPP_CUSTOM_ALLOCATION

#include <cstddef>
#include <new>

#define ANTLR4CPP_ALLOCATION_DECLARATION_STRUCT             \
public:                                                     \
    void *operator new(size_t size);                        \
    void operator delete(void *p);                          \
    void *operator new[](size_t size);                      \
    void operator delete[](void *p);                        \

#define ANTLR4CPP_ALLOCATION_DECLARATION                    \
    ANTLR4CPP_ALLOCATION_DECLARATION_STRUCT                 \
    private:                                                \

#define ANTLR4CPP_ALLOCATION_IMPLEMENTATION(Type)           \
    void *Type::operator new(size_t size) {                 \
        return antlr4::antlr4Allocate(size);                \
    }                                                       \
                                                            \
    void Type::operator delete(void *p) {                   \
        antlr4::antlr4Deallocate(p);                        \
    }                                                       \
                                                            \
    void *Type::operator new[](size_t size) {               \
        return antlr4::antlr4Allocate(size);                \
    }                                                       \
                                                            \
    void Type::operator delete[](void *p) {                 \
        antlr4::antlr4Deallocate(p);                        \
    }

namespace antlr4 {

class ANTLR4Allocator {
public:
    virtual void *allocate(size_t size) = 0;
};

class ANTLR4Deallocator {
public:
    virtual void deallocate(void *ptr) = 0;
};

extern thread_local ANTLR4Allocator *threadAllocator;
extern ANTLR4Allocator *staticAllocator;
extern thread_local ANTLR4Deallocator *threadDeallocator;
extern ANTLR4Deallocator *staticDeallocator;

void *antlr4Allocate(size_t size);
void antlr4Deallocate(void *ptr);

void setGlobalAllocator(ANTLR4Allocator *allocator, ANTLR4Deallocator *deallocator);
void setThreadLocalAllocator(ANTLR4Allocator *allocator, ANTLR4Deallocator *deallocator);

}
#endif