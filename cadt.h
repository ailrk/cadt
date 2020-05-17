#ifndef _CADT
#define _CADT
#include <stdbool.h>
#include <stddef.h>

typedef struct CADT_Dict CADT_Dict;
typedef struct CADT_Vec CADT_Vec;
typedef struct CADT_List CADT_List;
typedef struct CADT_Set CADT_Set;

/* dict.c */
typedef void CADTDictKey;
typedef void CADTDictVal;
CADT_Dict *CADT_Dict_new(const int keysz, const int valsz);
CADTDictKey *CADT_Dict_put(CADT_Dict *, const CADTDictKey *key,
                           CADTDictVal *val);
CADTDictVal *CADT_Dict_get(CADT_Dict *, const CADTDictKey *key);
CADTDictVal *CADT_Dict_has(CADT_Dict *, const CADTDictKey *key);
size_t *CADT_Dict_update(CADT_Dict *, CADT_Dict *);
size_t *CADT_Dict_remove(CADT_Dict *, const CADTDictKey *const key);

/* vector.c */
CADT_Vec *CADT_Vec_new(const size_t size, const int memsz);
CADT_Vec *CADT_Vec_init(const size_t size, const int memsz, ...);
void CADT_Vec_insert(CADT_Vec *, const size_t idx, void *val,
                        const size_t memsz);
void *const CADT_Vec_get(CADT_Vec *, const size_t idx,
                            const size_t memsz);
void *const CADT_Vec_pop(CADT_Vec *, const size_t memsz);
void CADT_Vec_push(CADT_Vec *, void *val, const size_t memsz);
CADT_Vec *CADT_Vec_concat(CADT_Vec *, CADT_Vec *);
bool CADT_Vec_contains(CADT_Vec *, const void *const val);
void CADT_Vec_reserve(CADT_Vec *, const size_t size);
void CADT_Vec_clear(CADT_Vec *);
void *const CADT_Vec_begin(CADT_Vec *);
void *const CADT_Vec_end(CADT_Vec *);

/* list.c */
typedef void CADTListVal;

/* set.c */
typedef void CADTSetVal;
CADT_Set *CADT_Set_new(const int valsz);
size_t *CADT_Set_add(CADT_Set *, CADTSetVal *const val);
size_t *CADT_Set_remove(CADT_Set *, CADTSetVal *const val);
CADT_Set *CADT_Set_union(CADT_Set *, CADT_Set *);
CADT_Set *CADT_Set_intersect(CADT_Set *, CADT_Set *);
CADT_Set *CADT_Set_compliment(CADT_Set *sub, CADT_Set *s);
size_t CADT_Set_size(const CADT_Set *const);
size_t CADT_Set_issubset(const CADT_Set *const sub, const CADT_Set *const s);

#endif /* ifndef _CADT */
