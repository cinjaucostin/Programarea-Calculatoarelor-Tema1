#include "gates.h"
#include <stdio.h>
#include <assert.h>

/* Task 1 - Bit by Bit */

uint8_t get_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint8_t res = -1;

    /* TODO
     *
     * "res" should be 1 if the bit is active, else 0
     */
    uint64_t mask=(1ULL<<i);
    if((nr&mask) == 0)
       res=0;
    else 
       res=1;
    return res;
}


uint64_t flip_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = -1;

    /* TODO
     *
     * Return the "nr" with the ith bit flipped
     */
    if(get_bit(nr,i) == 1)
       res=clear_bit(nr,i);
    else 
       res=activate_bit(nr,i);
    return res;
}
uint64_t activate_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = 0xFF;

    /* TODO
     *
     * Return the "nr" with the ith bit "1"
     */
    uint64_t mask = (1ULL<<i);
    res = nr | mask;
    return res;
}


uint64_t clear_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = -1;

    /* TODO
     *
     * Return the "nr" with the ith bit "0"
     */
    uint64_t mask =~ (1ULL<<i);
    res = nr & mask;
    return res;
}

/* Task 2 - One Gate to Rule Them All */

uint8_t nand_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    return !(a & b);
}


uint8_t and_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the nand gate to implement the and gate */
    res=!nand_gate(a,b);
    return res;
}


uint8_t not_gate(uint8_t a)
{
    assert (a == 0 || a == 1);

    uint8_t res = -1;

    /* TODO - Use the nand gate to implement the not gate */
    res=nand_gate(a,a);
    return res;
}


uint8_t or_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the previously defined gates to implement the or gate */
    res=nand_gate(not_gate(a),not_gate(b));
    return res;
}


uint8_t xor_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the previously defined gates to implement the xor gate */

    res=or_gate(and_gate(not_gate(a),b),and_gate(a,not_gate(b)));
    return res;
}


/* Task 3 - Just Carry the Bit */

uint8_t full_adder(uint8_t a, uint8_t b, uint8_t c)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);
    assert (c == 0 || c == 1);

    uint8_t res = -1;

    /* TODO - implement the full_adder using the previous gates
     * Since the full_adder needs to provide 2 results, you should
     * encode the sum bit and the carry bit in one byte - you can encode
     * it in whatever way you like
     */
    uint8_t s=xor_gate(c,xor_gate(a,b));
    uint8_t cout=or_gate(and_gate(c,xor_gate(a,b)),and_gate(a,b));
    res=s*2+cout;
    return res;
}


uint64_t ripple_carry_adder(uint64_t a, uint64_t b)
{
    uint64_t res = -1;

    /* TODO
     * Use the full_adder to implement the ripple carry adder
     * If there is ANY overflow while adding "a" and "b" then the
     * result should be 0
     */
    uint8_t suma1=0;
    uint8_t cout=0;
    for(int i=0;i<64;i++)
    {
        uint8_t bitul_a=get_bit(a,i);
        uint8_t bitul_b=get_bit(b,i);
        uint8_t suma2=full_adder(bitul_a,bitul_b,cout);
        if(suma2==0)
        {
            suma1=0;
            cout=0;
        }
        else if(suma2==1)
        {
            suma1=0;
            cout=1;
        }
        else if(suma2==2)
        {
            suma1=1;
            cout=0;
        }
        else
        {
            suma1=1;
            cout=1;
        }
        if(suma1==0)
           res=clear_bit(res,i);
        else 
           res=activate_bit(res,i);
    }
    if(cout==1)
     res=0;
    return res;
}