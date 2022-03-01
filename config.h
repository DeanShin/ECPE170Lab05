#ifndef CONFIG_H
#define CONFIG_H

// Choose mathematical operation for combiner function: 
// PROD or SUM
#define PROD

// Choose datatype for vector elements:
// FLOAT, DOUBLE, INT, LONG, CHAR
#define FLOAT

// ------- Don't edit below this line! --------

#ifdef FLOAT
typedef float data_t;
#define DATA_NAME "Float"
#endif

#ifdef DOUBLE
typedef double data_t;
#define DATA_NAME "Double"
#endif

#ifdef EXTEND
typedef long double data_t;
#define DATA_NAME "Extended"
#endif

#ifdef INT
typedef int data_t;
#define DATA_NAME "Integer"
#endif

#ifdef LONG
typedef long data_t;
#define DATA_NAME "Long"
#endif

#ifdef CHAR
typedef char data_t;
#define DATA_NAME "Char"
#endif

#ifdef PROD
#define IDENT 1
#define OP  *
#define OP_NAME "Product"
#else
#ifdef SUM
#define IDENT 0
#define OP  +
#define OP_NAME "Sum"
#endif
#endif

#endif // CONFIG_H
