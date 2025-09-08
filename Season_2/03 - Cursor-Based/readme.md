``` c

#define MAX 5
typedef struct {
    char FName[24];
    char LName[16];
    char MI;
}NameType;

typedef struct{
    NameType data;
    int link;
}NodeType;

typedef struct{
    NodeType Nodes[MAX];
    int Avail;
}VirtualHeap;

```

with padding
NameType = 44 bytes
NodeType = 48 bytes
VirtualHeap = 244 bytes
without padding

NameType = 41 bytes
NodeType = 45 bytes
VirtualHeap = 229 bytes

