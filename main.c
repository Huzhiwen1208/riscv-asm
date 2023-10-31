#include <stdio.h>
#include <assert.h>

int addi_ins(int a);
int addi_ins_2(int a);

int addi_reg(int a, int b);
int sub_reg(int a, int b);

int main()
{
    int res = 0;
    res = addi_ins(4);
    assert(res == 9);

    res = addi_ins_2(2049);
    assert(res == 1);

    res = addi_reg(4, 5);
    assert(res == 9);

    res = sub_reg(4, 5);
    assert(res == -1);

    printf("all assertion passed\n");
    return 0;
}