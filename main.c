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

int andi_ins(int a); // return a & 0xff
int ori_ins(int a); // return a | 0xff
int xori_ins(int a); // return a ^ 0xff

int and_ins(int a, int b); // return a & b
int or_ins(int a, int b); // return a | b
int xor_ins(int a, int b); // return a ^ b

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

    res = andi_ins(0x12345678);
    assert(res == 0x78);

    res = ori_ins(0x12345678);
    assert(res == 0x123456ff);

    res = xori_ins(0x12345678);
    assert(res == 0x12345687);

    res = and_ins(0x12345678, 0x87654321);
    assert(res == 0x02244220);

    res = or_ins(0x12345678, 0x87654321);
    assert(res == 0x97755779);

    res = xor_ins(0x12345678, 0x12345678);
    assert(res == 0x0);

    printf("all assertion passed\n");
    return 0;
}