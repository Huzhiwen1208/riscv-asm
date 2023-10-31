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

int slli_ins(int a); // return a << 1
int srli_ins(int a); // return a >> 1
int srai_ins(int a); // return a >> 1

int sll_ins(int a, int b); // return a << b
int srl_ins(int a, int b); // return a >> b
int sra_ins(int a, int b); // return a >> b

int jal_ins();
int jalr_ins(void* (*func)());

void test_jalr_ins() {
    printf("test_jalr_ins\n");
}

int beq_ins(int a, int b);

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

    res = slli_ins(0x12345678);
    assert(res == 0x2468acf0);

    res = srli_ins(0x12345678);
    assert(res == 0x091a2b3c);

    res = srai_ins(0xf0000000);
    assert(res == 0xf8000000);

    res = sll_ins(0x12345678, 4);
    assert(res == 0x23456780);

    res = srl_ins(0x12345678, 4);
    assert(res == 0x01234567);

    res = sra_ins(0xf0000000, 4);
    assert(res == 0xff000000);

    int option_address = jal_ins();
    printf("jal_ins: %x\n", option_address);

    option_address = jalr_ins(&test_jalr_ins);
    printf("jalr_ins: %x\n", option_address);

    res = beq_ins(4, 5);
    assert(res == 1);

    res = beq_ins(4, 4);
    assert(res == 0);

    printf("all assertion passed\n");
    return 0;
}