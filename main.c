#include <stdio.h>
#include <assert.h>

int addi_ins(int a);
int addi_ins_2(int a);

int addi_reg(int a, int b);
int sub_reg(int a, int b);

int slti_ins(int a);
int sltiu_ins(int a);

int slt_reg(int a, int b);
int sltu_reg(int a, int b);

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

    res = slti_ins(4); // 4 < 5? 
    assert(res == 1);

    res = slti_ins(6); // 6 < 5?
    assert(res == 0);

    res = sltiu_ins(2048); // 2048 < unsigned(-100)=0xffffff7c?
    assert(res == 1);

    res = slt_reg(4, 5); // 4 < 5?
    assert(res == 1);

    res = slt_reg(-100, -99);
    assert(res == 1);

    res = sltu_reg(-100, -99); // unsigned(-100) 7c < unsigned(-99) 7d?
    assert(res == 1);

    printf("all assertion passed\n");
    return 0;
}