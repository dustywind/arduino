
#define OUT_SEGMENT_A    11
#define OUT_SEGMENT_B    10
#define OUT_SEGMENT_C    7
#define OUT_SEGMENT_D    8
#define OUT_SEGMENT_E    9
#define OUT_SEGMENT_F    12
#define OUT_SEGMENT_G    13
#define OUT_SEGMENT_DP   6

#define SEGMENT_A        0x80  //b1000 0000
#define SEGMENT_B        0x40  //b0100 0000
#define SEGMENT_C        0x20  //b0010 0000
#define SEGMENT_D        0x10  //b0001 0000
#define SEGMENT_E        0x08  //b0000 1000
#define SEGMENT_F        0x04  //b0000 0100
#define SEGMENT_G        0x02  //b0000 0010
#define SEGMENT_DP       0x01  //b0000 0001

#define IS_SEGMENT_A(x)     ((x & SEGMENT_A) == SEGMENT_A)
#define IS_SEGMENT_B(x)     ((x & SEGMENT_B) == SEGMENT_B)
#define IS_SEGMENT_C(x)     ((x & SEGMENT_C) == SEGMENT_C)
#define IS_SEGMENT_D(x)     ((x & SEGMENT_D) == SEGMENT_D)
#define IS_SEGMENT_E(x)     ((x & SEGMENT_E) == SEGMENT_E)
#define IS_SEGMENT_F(x)     ((x & SEGMENT_F) == SEGMENT_F)
#define IS_SEGMENT_G(x)     ((x & SEGMENT_G) == SEGMENT_G)
#define IS_SEGMENT_DP(x)    ((x & SEGMENT_DP) == SEGMENT_DP)


#define S_0  SEGMENT_A | SEGMENT_B | SEGMENT_C \
    | SEGMENT_D | SEGMENT_E | SEGMENT_F
#define S_1  SEGMENT_B | SEGMENT_C
#define S_2  SEGMENT_A | SEGMENT_B | SEGMENT_G \
    | SEGMENT_E | SEGMENT_D
#define S_3  SEGMENT_A | SEGMENT_B | SEGMENT_G \
    | SEGMENT_C | SEGMENT_D
#define S_4  SEGMENT_F | SEGMENT_G | SEGMENT_B \
    | SEGMENT_C
#define S_5  SEGMENT_A | SEGMENT_F | SEGMENT_G \
    | SEGMENT_C | SEGMENT_D
#define S_6  SEGMENT_A | SEGMENT_F | SEGMENT_E \
    | SEGMENT_D | SEGMENT_C | SEGMENT_G
#define S_7  SEGMENT_A | SEGMENT_B | SEGMENT_C
#define S_8  SEGMENT_A | SEGMENT_B | SEGMENT_C \
    | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G
#define S_9  SEGMENT_A | SEGMENT_B | SEGMENT_C \
    | SEGMENT_D | SEGMENT_F | SEGMENT_G



void setup(){
    pinMode(OUT_SEGMENT_A, OUTPUT);
    pinMode(OUT_SEGMENT_B, OUTPUT);
    pinMode(OUT_SEGMENT_C, OUTPUT);
    pinMode(OUT_SEGMENT_D, OUTPUT);
    pinMode(OUT_SEGMENT_E, OUTPUT);
    pinMode(OUT_SEGMENT_F, OUTPUT);
    pinMode(OUT_SEGMENT_G, OUTPUT);
    pinMode(OUT_SEGMENT_DP, OUTPUT);
}

void loop(){
    count();
    //test();
}

void count(){
    for(int i = 0; i < 10; ++i){
        write_number(i);
        delay(1000);
        clear_all_segments(); 
    }
}

void write_number(int num)
{
    if(num == 0){enable_segments(S_0);}
    if(num == 1){enable_segments(S_1);}
    if(num == 2){enable_segments(S_2);}
    if(num == 3){enable_segments(S_3);}
    if(num == 4){enable_segments(S_4);}
    if(num == 5){enable_segments(S_5);}
    if(num == 6){enable_segments(S_6);}
    if(num == 7){enable_segments(S_7);}
    if(num == 8){enable_segments(S_8);}
    if(num == 9){enable_segments(S_9);}
}


void enable_segments(int segment_field){
    if(IS_SEGMENT_A(segment_field)){digitalWrite(OUT_SEGMENT_A, HIGH);}
    if(IS_SEGMENT_B(segment_field)){digitalWrite(OUT_SEGMENT_B, HIGH);}
    if(IS_SEGMENT_C(segment_field)){digitalWrite(OUT_SEGMENT_C, HIGH);}
    if(IS_SEGMENT_D(segment_field)){digitalWrite(OUT_SEGMENT_D, HIGH);}
    if(IS_SEGMENT_E(segment_field)){digitalWrite(OUT_SEGMENT_E, HIGH);}
    if(IS_SEGMENT_F(segment_field)){digitalWrite(OUT_SEGMENT_F, HIGH);}
    if(IS_SEGMENT_G(segment_field)){digitalWrite(OUT_SEGMENT_G, HIGH);}
    if(IS_SEGMENT_DP(segment_field)){digitalWrite(OUT_SEGMENT_DP, HIGH);}
}

void disable_segments(int segment_field){
    if(IS_SEGMENT_A(segment_field)){digitalWrite(OUT_SEGMENT_A, LOW);}
    if(IS_SEGMENT_B(segment_field)){digitalWrite(OUT_SEGMENT_B, LOW);}
    if(IS_SEGMENT_C(segment_field)){digitalWrite(OUT_SEGMENT_C, LOW);}
    if(IS_SEGMENT_D(segment_field)){digitalWrite(OUT_SEGMENT_D, LOW);}
    if(IS_SEGMENT_E(segment_field)){digitalWrite(OUT_SEGMENT_E, LOW);}
    if(IS_SEGMENT_F(segment_field)){digitalWrite(OUT_SEGMENT_F, LOW);}
    if(IS_SEGMENT_G(segment_field)){digitalWrite(OUT_SEGMENT_G, LOW);}
    if(IS_SEGMENT_DP(segment_field)){digitalWrite(OUT_SEGMENT_DP, LOW);}
}

void clear_all_segments(){
    digitalWrite(OUT_SEGMENT_A, LOW);
    digitalWrite(OUT_SEGMENT_B, LOW);
    digitalWrite(OUT_SEGMENT_C, LOW);
    digitalWrite(OUT_SEGMENT_D, LOW);
    digitalWrite(OUT_SEGMENT_E, LOW);
    digitalWrite(OUT_SEGMENT_F, LOW);
    digitalWrite(OUT_SEGMENT_G, LOW);
    digitalWrite(OUT_SEGMENT_DP, LOW);
}

void test(){
    blink(OUT_SEGMENT_A);
    blink(OUT_SEGMENT_B);
    blink(OUT_SEGMENT_C);
    blink(OUT_SEGMENT_D);
    blink(OUT_SEGMENT_E);
    blink(OUT_SEGMENT_F);
    blink(OUT_SEGMENT_G);
    blink(OUT_SEGMENT_DP); 
}

void blink(int OUT_SEGMENT){
    digitalWrite(OUT_SEGMENT, HIGH);
    delay(1000);
    digitalWrite(OUT_SEGMENT, LOW); 
}
