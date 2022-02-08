#GATES.C
 -Functia get_bit:
      ->Am initializat masca ca fiind 1 shiftat la stanga de i ori si ulterior am realizat operatia & si intre nr si masca(in cazul in care rezultatul era 0 inseamna ca bitul de pe pozitia i nu este activ iar in caz contrar acesta era activ);
 -Functia flip_bit:
      ->Am luat fiecare bit in parte si l-am verificat cu ajutorul functiei get_bit anterior definite;
      ->In cazul in care bitul era activ(avea valoarea 1) il schimbam in 0 cu ajutorul functiei clear_bit iar in cazul in care acesta era inactiv(avea valoarea 0) il schimbam in 1 cu ajutorul functiei activate_bit;
 -Functia activate_bit:
      ->Am creat o masca in care am shiftat 1 de i ori la stanga si ulterior am scris res ca fiind rezultatul(0 sau 1) operatiei nr | mask(aceasta operatie face bitul de pe pozitia i, 1);
 -Functia clear_bit:
      ->Am creat o masca in care am shiftat 1 de i ori la stanga;
      ->Am schimbat valoarea fiecarui bit din masca cu ajutorul ~ si ulterior am scris res ca fiind rezultatul operatiei nr & mask(operatie care face  bitul de pe pozitia i, 0);
 -Functia nand_gate:
      ->Am negat rezultatul operatiei & dintre doi biti;
 -Functia and_gate:
      ->Rezultatul pe care aceasta functie il intoarce este de fapt negatul rezultatului functiei nand_gate aplicate pe bitii respectivi;
 -Functia not_gate:
      ->Rezultatul acesteia este functia nand_gate aplicata pe acelasi bit(a, dupa notatiile din cod);
 -Functia or_gate:
      ->Rezultatul operatiei nand_gate aplicata pe rezultatul functiei not_gate pe primul bit si a functiei not_gate pe cel de-al doilea bit;
 -Functia xor_gate:
      ->x^y=x!y+!xy(schema logica a acestei operatii) 
      ->Schema logica a acestei operatii am introdus-o in cod cu ajutorul functiilor anterior definite(or_gate,and_gate,not_gate);
 -Functia full_adder:
      ->M-am folosit de implementarea acestei functii cu porti logice;
      ->Deoarece implementarea cu porti logice a full_adder-ului are doua rezultate(suma in sine si carry-ul/transportul) am fost nevoit sa codific rezultatul(res) ca fiind:suma*2+carry-ul;
 -Functia ripple_carry_adder:
      ->Am utilizat o structura repetitiva for pentru a parcurge toti cei 64 de biti;
      ->In interiorul acestei structuri am declarat doua variabile(bitul_a si bitul_b) in care am retinut valorile bitilor de pe pozitia i din cele doua numere(a si b) si o a treia variabila(suma2) in care am retinut rezultatul functiei full_adder(bitul_a,bitul_b,cout),unde cout este carry-ul(transportul) pentru urmatoarea operatie(de asemenea acestea este initializat ca fiind 0 pentru prima operatie de adunare);
      ->In continuare am luat pe cazuri rezultatul variabilei suma2 si l-am decodificat(dupa codificarea facuta la full_adder);


#COMMUNICATION.C
 -Functia send_byte_message:
      ->Am utilizat functia send_squanch pentru a trimite codificarea fiecaruia dintre caracterele date;
 -Functia recv_byte_message:
      ->Am creat un vector de tip char in care am retinut pe fiecare dintre pozitii litera din alfabet corespunzatoare acestuia;
      ->Am folosit o structura repetitiva pentru a afisa pe ecran fiecare dintre literele corespunzatoare codificarilor primite cu ajutorul functiei send_squanch;
 -Functia comm_byte:
      ->Am utilizat o structura repetitiva in care am retinut in cadrul variabilei "var" ceea ce returneaza functia recv_squanch si ulterior am folosit functia send_squanch pentru a trimite semnalul corespunzator fiecareia dintre variabile;
 -Functia send_message:
      ->Am folosit operatia | intre doua masti(in prima am shiftat 1 la stanga de 3 ori iar in cea de-a doua am shiftat 1 la stanga de 5 ori) pentru a obtine codificarea lungimii mesajului pe care am si trimis-o prin intermediul functiei send_squanch;
      ->Ulterior am trimis codificarea fiecarui caracter din mesajul cerut prin intermediul functiei send_squanch;
 -Functia recv_message:
      ->Am folosit variabila length_encoded pentru a retine valoarea codificata a lungimii mesajului;
      ->Mai departe am decodificat length_encoded tinand cont de modelul dat in problema si am salvat valoarea obtinuta in variabila x;
      ->Am afisat pe ecran valoarea lungimii decodificate(x);
      ->Cu ajutorul unei structuri repetitive am afisat pe ecran fiecare caracter, tinand cont de codificarea primita prin functia recv_squanch  folosindu-ma de acelasi vector in care am retinut alfabetul(alta metoda nu am stiut);
 -Functia  comm_message:
      ->Prin intermediul variabilei length_encoded am salvat valoarea returnata de functia recv_squanch pe care ulterior am decodificat-o pentru a afla lungimea mesajului primit;
      ->In variabila var am salvat ultima valoare returnata de functia recv_squanch;
      ->Ulterior am verificat daca ultima valoare codificata a mesajului primit este 16(adica caracterul "P"):daca da atunci trimiteam codificarea lungimii mesajului "PICKLERICK" si respectiv mesajul in sine, iar in caz contrar trimiteam lungimea mesajului "VINDICATORS" si respectiv mesajul;
 -Functia send_squanch2:
      ->In variabila both_chars_encoded am salvat codificarea celor doua numere primite prin intermediul functiei(c1 si c2);
      ->Ulterior am verificat fiecare bit de pe pozitia i din numarul c1 si respectiv, c2, si am introdus valoarea bitului pe pozitiile impare(pentru c1) si pare(pentru c2) in valoarea variabilei both_chars_encoded;
      ->Am trimis valoarea lui both_chars_encoded utilizand functia send_squanch;
 -Functia decode_squanch2:
      ->In cadrul unui for am verificat bitii de pe pozitiile pare, respectiv impare, si ii introduceam in res pe primele patru pozitii(in ordine),respectiv pe ultimele 4 pozitii;
*NOTA:In momentul in care am facut problema communication.c nu am stiut ca ma pot folosi de functiile de la problema anterioara si am rescris de fiecare data cand am avut nevoie codul functiilor activate_bit,clear_bit,get_bit(adaptandu-l la cerinta pe care o aveam la respectiva functie);


#HUNT.C
 -Functia find_spell:
      ->Prin intermediul unui for am verificat toti bitii de pe pozitiile 0 <-> 63 si in cazul in care intalneam 4 biti consecutivi de 1 retineam pozitia(prin variabile poz) unde acest sir de 4 biti de 1 se termina;
      ->Ulterior prin intermediul unui alt for(de aceasta data de la pozitia poz pana la pozitia poz+15-inclusiv) verificam fiecare bit de la acele pozitii(cu ajutorul functiei get_bit) si il inseram in variabila res(incepand cu pozitia 0) cu ajutorul functiilor:activate_bit si clear_bit;
 -Functia find_key:
      ->La fel ca si la find_spell verificam toti bitii si in cazul in care intalneam un sir de 3 biti de  1 consecutivi retineam pozitia de unde acest sir incepea(prin intermediul variabilei poz);
      ->Dupa luam toti bitii incepand cu pozitia poz-15 pana la poz si ii introduceam in res incepand cu pozitia 0;
 -Functia decrypt_spell:
      ->Initial am numarat bitii de 1 din valoarea parametrului functiei(enemy);
      ->In cazul in care numarul de biti de 1 este par inseamna ca inamicul este monster si:aflam "value" pe baza ecuatiei ce ni s-a oferit, respectiv introduceam aceasta valoarea pe primii 16 biti din res si sabia specifica pentru monster pe ultimii 4 biti;
      ->In cazul in care numarul de biti de 1 este impar inseamna ca inamicul este human si:aflam "value" folosind ecuatia primita de la enunt si introducem aceasta valoare pe primii 16 biti din res si sabia specifica pentru human pe ultimii 4 biti;
 -Functia trial_of_the_grasses:
      ->Am realizat tabele de adevar pentru cele 3 operatii date si am observat ca bitul din antibodies_high are aceeasi valoare cu bitul din cocktail iar bitul din antibodies low este intotdeauna 0;
      ->In concluzie singurul lucru pe care trebuie sa il facem era sa salvam in res rezultatul operatiei prin shiftarea lui cocktail de 16 ori la stanga;
 -Functia trial_of_forrest_eyes:
 -Functia trial_of_the_dreams:
      ->Am parcurs toti cei 32 de biti ai mapei si atunci cand am intalnit prima valoare de 1 am retinut pozitia aceseia ca fiind pozitia candidatului;
      ->Intr-un for de la pozitia candidatului pana la 32 am cautat urmatoare valoare de 1;
      ->Atunci cand gaseam ce-a de-a doua valoare de 1 ii retineam pozitia intr-o variabila deoarce aceasta era de fapt pozitia portalului;
      ->In cadrul variabilei res retineam diferenta dintre pozitia portalului si pozitia candidatului(distanta dintre cele doua puncte);