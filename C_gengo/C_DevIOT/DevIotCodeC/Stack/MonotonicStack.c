/*
Monotonic Stack is a stack which has sort ascending or descending
*/

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/* Init status of stack */
typedef enum
{
    STACK_OK        =   0U,
    STACK_EMPTY     =   1U,
    STACK_OVERFLOW  =   2U,
} StackStatus_t;

/* Init variable show stack asc or desc */
typedef enum
{
    STACK_MONO_ASC,
    STACK_MONO_DESC,
} eMonoStackType;

/* Create a monotonic stack */
typedef struct
{
    uint32_t        *pData; //Pointer point to Data Array in Heap
    uint32_t        Top;
    uint32_t        MAX;
    eMonoStackType  eType;
} MonoStackType;

/* Init a mono stack empty*/
MonoStackType sMonoStack = { 0U };

void MonoStack_Init(uint32_t maxItem, eMonoStackType eStackType)
{
    /* Allocate Memory for Stack Data */
    sMonoStack.pData = (uint32_t*)malloc(maxItem * sizeof(uint32_t));
    sMonoStack.Top = 0U;
    sMonoStack.MAX = maxItem;
    sMonoStack.eType = eStackType;
}

StackStatus_t MonoStack_Push(uint32_t inputData)
{
    StackStatus_t eStatus = STACK_OVERFLOW;
    uint32_t Idx = 0U;

    /* Search the position for new element */
    for( Idx = 0U; Idx < sMonoStack.Top; Idx++ )
    {
        if( (sMonoStack.pData[Idx] <= inputData && STACK_MONO_DESC == sMonoStack.eType) \
         || (sMonoStack.pData[Idx] >= inputData && STACK_MONO_ASC == sMonoStack.eType) \
        )
        {
            /* Searching is PAUSE and push new element to stack */
            sMonoStack.pData[Idx] = inputData;
            sMonoStack.Top = Idx+1;
            break;
        }
    }

    /* Case Stack is Full and New Element is not mapping */
    if( Idx == sMonoStack.MAX )
    {
        eStatus = STACK_OVERFLOW;
    }
    /* First Element is added 
       or Case No Element is poped from stack, push new to last */
    else if( Idx == sMonoStack.Top )
    {
        sMonoStack.pData[sMonoStack.Top++] = inputData;
        eStatus = STACK_OK;
    }
    else    /* Normal Case */
    {
        eStatus = STACK_OK;
    }

    return eStatus;
}

void printStack(void)
{
    int i;
    printf("Stack Data: ");
    for(i = 0U; i < sMonoStack.Top; i++)
    {
        printf("%d ", sMonoStack.pData[i]);
    }
    printf("\n");
}

uint8_t buildings[] = {18, 14, 13, 16, 12};

void main()
{
    uint32_t Idx;
    uint32_t numofBuilding = sizeof(buildings)/sizeof(buildings[0]);
    
    MonoStack_Init(numofBuilding, STACK_MONO_DESC);

    for( Idx = 0U; Idx < numofBuilding; Idx++ )
    {
        MonoStack_Push(buildings[Idx]);
    }

    printStack();   // expect = [18, 16, 12]
}
