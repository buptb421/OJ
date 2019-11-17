#include <new>
#include <iostream>

using namespace std;

#define elemType int

// Position indicators, code(+0) 0, 1
#define POS_BACK 0
#define POS_FRONT 1

// Step direction indicators, code(+2) 2, 3
#define STEP_BACKWARD 0
#define STEP_FOWARD 1

// In/out operation indicators, code(+5) 4, 5, 6
#define OP_POINT -1
#define OP_PUSH 0
#define OP_POP 1

// Code offset
#define CODE_POS 0
#define CODE_STEP 2
#define CODE_OP 5
#define CODE_LEN 7
char codelist[8][16] = {
    "back",
    "front",
    "backward",
    "foeard",
    "point",
    "push",
    "pop",
    "length"};

#define DEBUG_INFO(info)                                     \
    do                                                       \
    {                                                        \
        if (!(mute || muteall))                              \
        {                                                    \
            for (int index = 0; index < indent * 2; index++) \
            {                                                \
                cout << ' ';                                 \
            }                                                \
            cout << '[' << info << ']' << endl;              \
        }                                                    \
    } while (0)
/*
#define DEBUG_INFO(info) do{}while(0)
*/

int indent = 0;
bool mute = false;
bool muteall = false;// Change it to true to mute all debug information, this is the manual switch.

typedef struct DEQUEUE
{
    int MemSize;
    elemType *list;
    int head[2];
} dequeue;

void setBoth(dequeue &d, int val)
{
    DEBUG_INFO("Set both to " << val);
    d.head[POS_FRONT] = d.head[POS_BACK] = val;
}
void clearEvery(dequeue &d)
{
    DEBUG_INFO("Clear dequeue.");
    indent++;
    setBoth(d, d.MemSize);
    indent--;
}
bool constructDequeue(dequeue &d, int size)
{
    DEBUG_INFO("Construct dequeue.");
    indent++;
    d.MemSize = 0;
    d.list = nullptr;
    if (size > 0)
    {
        DEBUG_INFO("Size: " << size << ", allocate memory.");
        d.list = new elemType[size];
        if (d.list)
        {
            DEBUG_INFO("Allocate done.");
            d.MemSize = size;
        }
        else
        {
            DEBUG_INFO("Memory overflow.");
            //cout <<  << endl;
        }
    }
    else
    {
        DEBUG_INFO("Size can't be 0, construction abort.");
        //cout <<  << endl;
    }
    clearEvery(d);
    indent--;
    return d.MemSize != 0;
}
void destroyDequeue(dequeue &d)
{
    DEBUG_INFO("Destroy dequeue.");
    indent++;
    d.MemSize = 0;
    clearEvery(d);
    if (d.list)
    {
        DEBUG_INFO("Release memory.");
        delete[] d.list;
        d.list = nullptr;
    }
    else
    {
        DEBUG_INFO("Already released.");
    }
    indent--;
}

int next(dequeue d, int now)
{
    DEBUG_INFO("Get next element of " << now);
    indent++;
    now++;
    if (now < d.MemSize)
    {
        DEBUG_INFO("next: +1 = " << now);
    }
    else
    {
        now = 0;
        DEBUG_INFO("next: first " << now);
    }
    indent--;
    return now;
}
int prev(dequeue d, int now)
{
    DEBUG_INFO("Get prev element of " << now);
    indent++;
    if (now <= 0)
    {
        now = d.MemSize - 1;
        DEBUG_INFO("prev: final " << now);
    }
    else
    {
        now--;
        DEBUG_INFO("prev: -1 = " << now);
    }
    indent--;
    return now;
}
int step(dequeue d, int stp_ind, int now)
{
    DEBUG_INFO("Step " << codelist[CODE_STEP + stp_ind] << '.');
    indent++;
    if (stp_ind == STEP_FOWARD)
    {
        now = next(d, now);
    }
    else
    {
        now = prev(d, now);
    }
    indent--;
    return now;
}

bool exist(dequeue d)
{
    DEBUG_INFO("Decide existance.");
    indent++;
    bool b = d.list != nullptr && d.MemSize != 0;
    if (b)
    {
        DEBUG_INFO("Exists.");
    }
    else
    {
        DEBUG_INFO("Not exist.");
    }
    indent--;
    return b;
}

bool empty(dequeue d)
{
    DEBUG_INFO("Decide empty.");
    indent++;
    bool b = d.head[POS_FRONT] == d.MemSize || d.head[POS_BACK] == d.MemSize;
    if (b)
    {
        DEBUG_INFO("Empty.");
    }
    else
    {
        DEBUG_INFO("Not empty.");
    }
    indent--;
    return b;
}
bool full(dequeue d)
{
    DEBUG_INFO("Decide full.");
    indent++;
    int ne = next(d, d.head[POS_FRONT]);
    DEBUG_INFO("Back: " << d.head[POS_BACK] << ", next of front: " << ne << '.');
    bool b = d.head[POS_BACK] == ne;
    if (b)
    {
        DEBUG_INFO("Full.");
    }
    else
    {
        DEBUG_INFO("Not full.");
    }
    indent--;
    return b;
}

int length(dequeue d)
{
    DEBUG_INFO("Get Length.");
    indent++;
    int len;
    if (!empty(d))
    {
        len = (d.MemSize - d.head[POS_BACK] + d.head[POS_FRONT]) % d.MemSize + 1;
    }
    else
    {
        len = 0;
    }
    DEBUG_INFO("Length is " << len);
    indent--;
    return len;
}

bool extreamCond(dequeue d, int op_ind)
{
    DEBUG_INFO("Test exrteam conditions for " << codelist[CODE_OP + op_ind] << '.');
    indent++;
    bool b;
    if (op_ind == 0)
    {
        b = full(d);
    }
    else
    {
        b = empty(d);
    }
    indent--;
    return b;
}
bool DqOp(dequeue &d, int op_ind, int pos_ind, elemType *&pdata)
{
    DEBUG_INFO("Do " << codelist[CODE_OP + op_ind] << " at " << codelist[CODE_POS + pos_ind]);
    indent++;
    if (exist(d) && !extreamCond(d, op_ind))
    {
        int stp_ind = (op_ind + pos_ind) % 2;
        if (op_ind != -1)
        {
            d.head[pos_ind] = step(d, stp_ind, d.head[pos_ind]); // try
            if (extreamCond(d, 1 - op_ind))                      // if extream after try, fix.
            {
                setBoth(d, (d.MemSize + (1 - op_ind) * (pos_ind - 1)) % (d.MemSize + op_ind));
            }
        }
        if (op_ind == 0)
        {
            DEBUG_INFO("Push value " << *pdata << " to " << codelist[CODE_POS + pos_ind] << ", Pos: " << d.head[pos_ind]);
            d.list[d.head[pos_ind]] = *pdata;
        }
        else
        {
            DEBUG_INFO("Get pointer to " << codelist[CODE_POS + pos_ind] << ", Pos: " << d.head[pos_ind] << ", value: " << *pdata);
            pdata = d.list + d.head[pos_ind];
        }
    }
    else
    {
        DEBUG_INFO("Can't excute operation " << codelist[CODE_OP + op_ind] << '.');
        //cout <<  << endl;
        if (op_ind != 0)
        {
            pdata = nullptr;
        }
    }
}

void displayAll(dequeue d)
{
    bool mute_init = mute;
    mute = true;
    for(int i = 0; i < 20; i++) cout << '='; cout << endl;
    // info
    cout << "Mem size: " << d.MemSize 
        << ", back: " << d.head[POS_BACK] 
        << ", front: " << d.head[POS_FRONT] 
        << ", length: " << length(d) << endl;
    // list mem
    cout << '(';
    for(int i = 0; i < d.MemSize; i++)
    {
        if(i == d.head[POS_BACK])
        {
            cout << '[';
        }
        cout << d.list[i];
        if(i == d.head[POS_FRONT])
        {
            cout << ']';
        }
        cout << ", ";
    }
    if(d.MemSize == d.head[POS_BACK])
    {
        cout << '[';
    }
    cout << 'X';
    if(d.MemSize == d.head[POS_FRONT])
    {
        cout << ']';
    }
    cout << ')' << endl;
    // list virtual, back -> front
    
    cout << '(';
    if(!empty(d))
    {
        int n = d.head[POS_BACK];
        while(n != d.head[POS_FRONT])
        {    
            cout << d.list[n] << ", ";
            n = next(d, n);
        }
        cout << d.list[n];
    }
    cout << ')' << endl;
    
    for(int i = 0; i < 20; i++) cout << '='; cout << endl;
    mute = mute_init;
}
/*
elemType *phead(dequeue &d, int pos_ind)
{
    elemType *p;
    DqOp(d, OP_POINT, pos_ind, p);
    return p;
}
void push(dequeue &d, int pos_ind, elemType data)
{
    elemType *p = &data;
    DqOp(d, OP_PUSH, pos_ind, p);
}
void pop(dequeue &d, int pos_ind, elemType &data)
{
    elemType *p = &data;
    DqOp(d, OP_POP, pos_ind, p);
}

// Operation interface. All the same to STL except front/back return pointers instead of reference.
elemType *front(dequeue &d) { return phead(d, POS_FRONT); }
elemType *back(dequeue &d) { return phead(d, POS_BACK); }
void push_front(dequeue &d, elemType data) { push(d, POS_FRONT, data); }
void push_back(dequeue &d, elemType data) { push(d, POS_BACK, data); }
void pop_front(dequeue &d, elemType &data) { pop(d, POS_FRONT, data); }
void pop_back(dequeue &d, elemType &data) { pop(d, POS_BACK, data); }
*/
int getNum(char *str)
{
    int num = 0;
    while (*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
        {
            num = num * 10 + *str - '0';
        }
        str++;
    }
    return num;
}

int main()
{
    char line[16];
    dequeue d;

    if (constructDequeue(d, 10))
    {
        int op_ind;
        int pos_ind;
        int break_handle = 0;
        int getSecondCode = 0;
        int n = 0;
        int *pn = &n;
        while (break_handle == 0)
        {
            //display
            cout << "-----------------------------" << endl;
            cin.getline(line, 16);
            getSecondCode = 0;
            switch (line[0])
            {
            case 'p':
                op_ind = OP_POINT;
                getSecondCode = 1;
                break;
            case 'u':
                op_ind = OP_PUSH;
                getSecondCode = 1;
                break;
            case 'o':
                op_ind = OP_POP;
                getSecondCode = 1;
                break;
            case 'l':
                length(d);
                break;
            case 'a':
                displayAll(d);
                break;
            case 'h':
                cout << "The optional codes are:" << endl
                    << "pb: get pointer to back element" << endl
                    << "pf: get pointer to front element" << endl
                    << "ub [NUM]: push number to back" << endl
                    << "uf [NUM]: push number to front" << endl
                    << "ob: pop from back and return into pointer" << endl
                    << "of: pop from front and return into pointer" << endl
                    << "l: get length" << endl
                    << "a: display all information" << endl
                    << "c: clear dequeue" << endl
                    << "e: exit" << endl;
                break;
            case 'c':
                clearEvery(d);
                break;
            case 'e':
                break_handle = 1;
                break;
            default:
                cout << "Wrong code, should be: pb, pf, ub, uf, ob, of, l, a, c, e." << endl;
                break;
            }
            if (getSecondCode == 1)
            {
                switch (line[1])
                {
                case 'b':
                    pos_ind = POS_BACK;
                    getSecondCode = 2;
                    break;
                case 'f':
                    pos_ind = POS_FRONT;
                    getSecondCode = 2;
                    break;
                default:
                    cout << "Wrong code, should be: pb, pf, ub, uf, ob, of, l, a, c, e." << endl;
                    break;
                }
                if (getSecondCode == 2)
                {
                    if(op_ind == OP_PUSH)
                    {
                        n = getNum(line);
                    }
                    DqOp(d, op_ind, pos_ind, pn);
                    // use pn here.
                    pn = &n;
                }
            }
        }
    }

    return 0;
}
