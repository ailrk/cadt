#ifndef _CADT
#define _CADT
#include <stdbool.h>
#include <stddef.h>

typedef struct CADT_Dict CADT_Dict;
typedef struct CADT_Vec CADT_Vec;
typedef struct CADT_Deque CADT_Deque;
typedef struct CADT_Set CADT_Set;
typedef struct CADT_Heap CADT_Heap;

/* dict.c */
typedef enum CADTDictMode {
  OVERWRITE,
  IGNORE,
} CADTDictMode;
CADT_Dict *CADT_Dict_new(const size_t keysz, const size_t valsz);
void CADT_Dict_put(CADT_Dict *, const void *key, void *val, CADTDictMode);
void *CADT_Dict_get(CADT_Dict *, const void *key);
size_t CADT_Dict_update(CADT_Dict *, CADT_Dict *, CADTDictMode);
bool CADT_Dict_remove(CADT_Dict *, const void *const key);
void CADT_Dict_free(CADT_Dict *);

/* vector.c */
CADT_Vec *CADT_Vec_new(const size_t size, const size_t memsz);
CADT_Vec *CADT_Vec_init(const size_t size, const size_t memsz, ...);
void CADT_Vec_insert(CADT_Vec *, const size_t idx, void *val,
                     const size_t memsz);
void *const CADT_Vec_get(CADT_Vec *, const size_t idx, const size_t memsz);
void *const CADT_Vec_pop(CADT_Vec *, const size_t memsz);
void CADT_Vec_push(CADT_Vec *, void *val, const size_t memsz);
CADT_Vec *CADT_Vec_concat(CADT_Vec *, CADT_Vec *);
bool CADT_Vec_contains(CADT_Vec *, const void *const val);
void CADT_Vec_reserve(CADT_Vec *, const size_t size);
void CADT_Vec_clear(CADT_Vec *);
void *const CADT_Vec_begin(CADT_Vec *const);
void *const CADT_Vec_end(CADT_Vec *const);
void CADT_Vec_free(CADT_Vec *);

/* deque.c */
CADT_Deque *CADT_Deque_new(const size_t memsz);
CADT_Deque *CADT_Deque_init(const size_t count, const size_t memsz, ...);
void CADT_Deque_push(CADT_Deque *, void *const val);
void CADT_Deque_pushl(CADT_Deque *, void *const val);
void *CADT_Deque_pop(CADT_Deque *);
void *CADT_Deque_popl(CADT_Deque *);
bool CADT_Deque_remove(CADT_Deque *, const void *const val);
void CADT_Deque_rotate(CADT_Deque *, const size_t n);
void CADT_Deque_free(CADT_Deque *);

/* heap.c */
typedef enum CADTHeapType { MAX, MIN } CADTHeapType;

CADT_Heap *CADT_Heap_new(const size_t capacity, const size_t memsz,
                         const CADTHeapType,
                         int (*cmp)(const void *, const void *));
bool CADT_Heap_insert(CADT_Heap *, const void *val);
void CADT_Heap_bottomup(CADT_Heap *, const size_t index);
void CADT_Heap_topdown(CADT_Heap *, const size_t parent_index);
void *CADT_Heap_popmin(CADT_Heap *);

#endif /* ifndef _CADT */
