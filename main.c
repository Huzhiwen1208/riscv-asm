#include <stdio.h>
#include <assert.h>

int addi_ins(int a);
int addi_ins_2(int a);

int main()
{
    int res = 0;
    res = addi_ins(4);
    assert(res == 9);

    res = addi_ins_2(2049);
    assert(res == 1);

    return 0;
}