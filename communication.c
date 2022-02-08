#include "communication.h"
#include "util_comm.h"

#include <stdio.h>


/* Task 1 - The Beginning */

void send_byte_message(void)
{
    /* TODO
     * Send the encoding of the characters: R, I, C, K
     */
    send_squanch(18);
    send_squanch(9);
    send_squanch(3);
    send_squanch(11);
}


void recv_byte_message(void)
{
    /* TODO
     * Receive 5 encoded characters, decode them and print
     * them to the standard output (as characters)
     *
     * ATTENTION!: Use fprintf(stdout, ...)
     */
    char litere_alfabet[26];
    litere_alfabet[1]='A';
    litere_alfabet[2]='B';
    litere_alfabet[3]='C';
    litere_alfabet[4]='D';
    litere_alfabet[5]='E';
    litere_alfabet[6]='F';
    litere_alfabet[7]='G';
    litere_alfabet[8]='H';
    litere_alfabet[9]='I';
    litere_alfabet[10]='J';
    litere_alfabet[11]='K';
    litere_alfabet[12]='L';
    litere_alfabet[13]='M';
    litere_alfabet[14]='N';
    litere_alfabet[15]='O';
    litere_alfabet[16]='P';
    litere_alfabet[17]='Q';
    litere_alfabet[18]='R';
    litere_alfabet[19]='S';
    litere_alfabet[20]='T';
    litere_alfabet[21]='U';
    litere_alfabet[22]='V';
    litere_alfabet[23]='W';
    litere_alfabet[24]='X';
    litere_alfabet[25]='Y';
    litere_alfabet[26]='Z';
    for(int i=1;i<=5;i++)
    {
        fprintf(stdout,"%c",litere_alfabet[recv_squanch()]);
    }
}
void comm_byte(void)
{
    /* TODO
     * Receive 10 encoded characters and send each character (the character is
     * still encoded) 2 times
    */
   
    for(int i=1;i<=10;i++)
    {
        int var=recv_squanch();
        send_squanch(var);
        send_squanch(var);
    }
}


/* Task 2 - Waiting for the Message */

void send_message(void)
{
    /* TODO
     * Send the message: HELLOTHERE
     * - send the encoded length
     * - send each character encoded
     */
    uint8_t mask1=(1<<3);
    uint8_t mask2=(1<<5);
    uint8_t codificare_lungime=mask1 | mask2;
    send_squanch(codificare_lungime);
    
    send_squanch(8);
    send_squanch(5);
    send_squanch(12);
    send_squanch(12);
    send_squanch(15);
    send_squanch(20);
    send_squanch(8);
    send_squanch(5);
    send_squanch(18);
    send_squanch(5);

} 


void recv_message(void)
{
    /* TODO
     * Receive a message:
     * - the first value is the encoded length
     * - length x encoded characters
     * - print each decoded character
     * 
     * ATTENTION!: Use fprintf(stdout, ...)
     */
    char litere_alfabet[26];
    litere_alfabet[1]='A';
    litere_alfabet[2]='B';
    litere_alfabet[3]='C';
    litere_alfabet[4]='D';
    litere_alfabet[5]='E';
    litere_alfabet[6]='F';
    litere_alfabet[7]='G';
    litere_alfabet[8]='H';
    litere_alfabet[9]='I';
    litere_alfabet[10]='J';
    litere_alfabet[11]='K';
    litere_alfabet[12]='L';
    litere_alfabet[13]='M';
    litere_alfabet[14]='N';
    litere_alfabet[15]='O';
    litere_alfabet[16]='P';
    litere_alfabet[17]='Q';
    litere_alfabet[18]='R';
    litere_alfabet[19]='S';
    litere_alfabet[20]='T';
    litere_alfabet[21]='U';
    litere_alfabet[22]='V';
    litere_alfabet[23]='W';
    litere_alfabet[24]='X';
    litere_alfabet[25]='Y';
    litere_alfabet[26]='Z';
    uint8_t length_encoded=recv_squanch();
    uint8_t x=0;
    int j=0;
    for(int i=2;i<=5;i++)
    {
       uint8_t mask=(1<<i);
       uint8_t verificare_bit=length_encoded & mask;
       if(verificare_bit==0)
       {
           uint8_t mask1=~(1<<j);
           x = x & mask1;
       }
       else if(verificare_bit>0)
       {
           uint8_t mask1=(1<<j);
           x = x | mask1;
       }
       j++;
    }
    fprintf(stdout,"%d",x);
    for(int i=1;i<=x;i++)
    { 
        fprintf(stdout,"%c",litere_alfabet[recv_squanch()]);
    }
} 
void comm_message(void)
{
    /* TODO
     * Receive a message from Rick and do one of the following depending on the
     * last character from the message:
     * - 'P' - send back PICKLERICK
     * - anything else - send back VINDICATORS
     * You need to send the messages as you did at the previous tasks:
     * - encode the length and send it
     * - encode each character and send them
     */
    uint8_t length_encoded,var;
    length_encoded=recv_squanch();
    uint8_t x=0;
    int j=0;
    for(int i=2;i<=5;i++)
    {
       uint8_t mask=(1<<i);
       uint8_t verificare_bit=length_encoded & mask;
       if(verificare_bit==0)
       {
           uint8_t mask1=~(1<<j);
           x = x & mask1;
       }
       else if(verificare_bit>0)
       {
           uint8_t mask1=(1<<j);
           x = x | mask1;
       }
       j++;
    }
    for(int i=1;i<=x;i++)
       var=recv_squanch();
    if(var==16)
    {
        send_squanch(10<<2);
        send_squanch(16);//P
        send_squanch(9);//I
        send_squanch(3);//C
        send_squanch(11);//K
        send_squanch(12);//L
        send_squanch(5);//E
        send_squanch(18);//R
        send_squanch(9);//I
        send_squanch(3);//C
        send_squanch(11);//K
    }
    else 
    {
        send_squanch(11<<2);
        send_squanch(22);//V
        send_squanch(9);//I
        send_squanch(14);//N
        send_squanch(4);//D
        send_squanch(9);//I
        send_squanch(3);//C
        send_squanch(1);//A
        send_squanch(20);//T
        send_squanch(15);//O
        send_squanch(18);//R
        send_squanch(19);//S
    }
}


/* Task 3 - In the Zone */


void send_squanch2(uint8_t c1, uint8_t c2)
{
    /* TODO
     * Steps:
     * - "merge" the character encoded in c1 and the character encoded in c2
     * - use send_squanch to send the newly formed byte
     */
    uint8_t both_chars_encoded=0;
    for(int i=0;i<=3;i++)
{
   
	    uint8_t mask=(1<<(3-i));
        
        uint8_t res1=-1;res1=c1&mask;
        uint8_t res2=-1;res2=c2&mask;
        if(res1==0)
           {
             uint8_t mask=~(1<<(7-2*i));
             both_chars_encoded=both_chars_encoded & mask;
           }
        else if(res1>0)
           {
             uint8_t mask=(1<<(7-2*i));
             both_chars_encoded=both_chars_encoded | mask;
           }
        if(res2==0)
           {
             uint8_t mask=~(1<<(6-2*i));
             both_chars_encoded=both_chars_encoded & mask;
           }
        else if(res2>0)
           {
             uint8_t mask=(1<<(6-2*i));
             both_chars_encoded=both_chars_encoded | mask;
           }

}
    send_squanch(both_chars_encoded);
}



uint8_t decode_squanch2(uint8_t c)
{   
    /* TODO */
    /*
     * Decode the given byte:
     * - split the two characters as in the image from ocw.cs.pub.ro
     */
    /* code */
    uint8_t res = -1;
    int j=0,k=4;
    for(int i=0 ; i<=7 ; i++)
    {   
        if(i%2==0)
         {
            uint8_t mask=(1<<i);
            uint8_t verificare1=-1; 
            verificare1=c & mask;
            if(verificare1==0)
            {
                uint8_t mask1=~(1<<j);
                res=res&mask1;
            }
            else if (verificare1>0)
            {
                uint8_t mask1=(1<<j);
                res=res|mask1;
            }
            j++;
          }
        else if(i%2!=0)
        {
             uint8_t mask=(1<<i);
             uint8_t verificare2=-1; 
             verificare2=c & mask;
             if(verificare2==0)
             {
                 uint8_t mask1=~(1<<k);
                 res=res&mask1;
             }
             else if (verificare2>0)
             {
                 uint8_t mask1=(1<<k);
                 res=res|mask1;
             } 
             k++;   
        }  
    }
    return res;
}