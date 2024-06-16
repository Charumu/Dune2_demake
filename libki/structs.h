#ifndef STRUCTS
#define STRUCTS
typedef struct {
  short gen; // 100
  short hp;  // 100
} PPLANT;
typedef struct {
  short hp;  // 100
} CYARD;
typedef struct {
  void *el;
  unsigned char typ[2];
} GRID;
typedef struct {
  char hp;
  char status;
  unsigned int poz[2];
  char movTo[2];
} JEDNOSTKA;
extern JEDNOSTKA p0;
extern PPLANT p1;
extern GRID p2;
#endif
