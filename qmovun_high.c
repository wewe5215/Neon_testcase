#include "print_output.h"
void f1();
void f2();
void f3();


static const struct {
    uint8_t r[8];
    int16_t a[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r6[8];
    int8_t r8[8];
  } test_vec_s16[] = {
    { { UINT8_C(100), UINT8_C(  2), UINT8_C(214), UINT8_C( 55), UINT8_C(206), UINT8_C(127), UINT8_C(243), UINT8_C( 82) },
      {  INT16_C( 31180),  INT16_C(  4904), -INT16_C( 23210), -INT16_C( 31062),  INT16_C( 18127),  INT16_C( 19203), -INT16_C( 19507),  INT16_C(  2049) } },
    { { UINT8_C( 13), UINT8_C(178), UINT8_C(149), UINT8_C(123), UINT8_C( 25), UINT8_C( 43), UINT8_C(160), UINT8_C(150) },
      { -INT16_C(   373),  INT16_C( 19843),  INT16_C( 14700),  INT16_C( 14048), -INT16_C( 27595),  INT16_C( 24108),  INT16_C( 18682), -INT16_C(  9358) } },
    { { UINT8_C(214), UINT8_C(101), UINT8_C( 47), UINT8_C(247), UINT8_C(  2), UINT8_C(218), UINT8_C(217), UINT8_C(141) },
      { -INT16_C( 18107), -INT16_C( 23848),  INT16_C( 12007), -INT16_C( 29402),  INT16_C( 23906), -INT16_C( 27759),  INT16_C(  1723), -INT16_C( 15097) } },
    { { UINT8_C( 34), UINT8_C(240), UINT8_C(108), UINT8_C(127), UINT8_C(119), UINT8_C(175), UINT8_C( 24), UINT8_C(136) },
      { -INT16_C( 19005),  INT16_C( 22136),  INT16_C(  6083),  INT16_C( 26110),  INT16_C( 12538), -INT16_C(  3743), -INT16_C( 31236), -INT16_C( 27459) } },
    { { UINT8_C(147), UINT8_C(121), UINT8_C(159), UINT8_C(174), UINT8_C(245), UINT8_C( 93), UINT8_C( 92), UINT8_C( 69) },
      {  INT16_C(  2030), -INT16_C( 27093), -INT16_C(  7542), -INT16_C( 10567),  INT16_C( 21075),  INT16_C( 29048), -INT16_C(  2297), -INT16_C( 19155) } },
    { { UINT8_C(239), UINT8_C(165), UINT8_C( 54), UINT8_C(249), UINT8_C(  4), UINT8_C( 80), UINT8_C( 85), UINT8_C(114) },
      { -INT16_C(  4594),  INT16_C(   785),  INT16_C( 31532),  INT16_C( 20269),  INT16_C( 26843),  INT16_C( 20084), -INT16_C(  9445),  INT16_C( 19790) } },
    { { UINT8_C(176), UINT8_C(117), UINT8_C( 14), UINT8_C( 97), UINT8_C( 56), UINT8_C( 94), UINT8_C(236), UINT8_C(121) },
      { -INT16_C(  1836), -INT16_C( 28789), -INT16_C( 30130),  INT16_C(  3077),  INT16_C(  3869),  INT16_C(  6861),  INT16_C( 14905), -INT16_C( 27965) } },
    { { UINT8_C(218), UINT8_C(242), UINT8_C(160), UINT8_C( 13), UINT8_C(233), UINT8_C( 31), UINT8_C(  6), UINT8_C( 50) },
      {  INT16_C( 27396),  INT16_C( 13977), -INT16_C( 11367), -INT16_C( 14164),  INT16_C(  5266),  INT16_C( 28347),  INT16_C(  9976),  INT16_C( 28141) } }
  };

static const struct {
    uint16_t r[4];
    int32_t a[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec_s32[] = {
    { { UINT16_C(24173), UINT16_C( 1790), UINT16_C(59817), UINT16_C(40185) },
      {  INT32_C(   315426397),  INT32_C(   313020990), -INT32_C(   516323581),  INT32_C(   383835578) } },
    { { UINT16_C(40856), UINT16_C(58442), UINT16_C( 8738), UINT16_C(50706) },
      { -INT32_C(   859308004), -INT32_C(  1645995095), -INT32_C(  1620787163),  INT32_C(  1240322457) } },
    { { UINT16_C( 7546), UINT16_C( 4876), UINT16_C(21989), UINT16_C(33056) },
      {  INT32_C(  1927394602),  INT32_C(  2067438100), -INT32_C(   955239222),  INT32_C(   812090873) } },
    { { UINT16_C(10510), UINT16_C( 7822), UINT16_C(16732), UINT16_C(33763) },
      {  INT32_C(   711685855),  INT32_C(   306560907),  INT32_C(  1967889584),  INT32_C(   651093366) } },
    { { UINT16_C(51879), UINT16_C( 3381), UINT16_C(52951), UINT16_C( 7385) },
      {  INT32_C(  1236824286),  INT32_C(  1195715452),  INT32_C(   271172829),  INT32_C(    59350704) } },
    { { UINT16_C(30978), UINT16_C(51831), UINT16_C(42357), UINT16_C(39607) },
      { -INT32_C(   657549701),  INT32_C(   580742124),  INT32_C(  1259347986),  INT32_C(  2044629291) } },
    { { UINT16_C( 7137), UINT16_C(10449), UINT16_C(51806), UINT16_C( 2467) },
      {  INT32_C(  1987054263), -INT32_C(   298197002), -INT32_C(   328537922), -INT32_C(  1144754372) } },
    { { UINT16_C(21680), UINT16_C(60161), UINT16_C(33419), UINT16_C(58597) },
      {  INT32_C(   803563181), -INT32_C(  1763325937),  INT32_C(  1281447796), -INT32_C(  2083319358) } }
  };

  static const struct {
    uint32_t r[2];
    int64_t a[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec_s64[] = {
    { { UINT32_C(4199219867), UINT32_C(3836371475) },
      { -INT64_C( 4802332149045464818),  INT64_C( 2331206664291245534) } },
    { { UINT32_C(2442160951), UINT32_C(  52447671) },
      { -INT64_C( 2336489752529235959),  INT64_C( 2983083481389323944) } },
    { { UINT32_C( 764770690), UINT32_C(1776788780) },
      {  INT64_C( 8119490888202979754), -INT64_C(  267232440644855601) } },
    { { UINT32_C(1889540326), UINT32_C(3317255256) },
      { -INT64_C( 4511220744055689568),  INT64_C( 2658337626527523947) } },
    { { UINT32_C(1180595864), UINT32_C(1639827066) },
      {  INT64_C( 3235160315356656370),  INT64_C( 5890567606295502283) } },
    { { UINT32_C( 246861919), UINT32_C(3671771392) },
      { -INT64_C( 3918581840997232639),  INT64_C( 8773030827631133310) } },
    { { UINT32_C(2012745132), UINT32_C(1578518910) },
      { -INT64_C( 5604221820049784580),  INT64_C( 5909247683266841507) } },
    { { UINT32_C(2039102105), UINT32_C(3535693308) },
      { -INT64_C( 8226143372118433647),  INT64_C( 4042681866641683100) } }
  };

  

  int main(){
    f1();
    f2();
    f3();
    
    return 0;
}

void f1(){

    for (size_t i = 0 ; i < (sizeof(test_vec_s16) / sizeof(test_vec_s16[0])) ; i++) {
        int16x8_t a = vld1q_s16(test_vec_s16[i].a);
        // printf("test:\n");
        // for (int i = 0; i < 8; i++)
        // {
        //     printf("%hd, ", a[i]);
        // }
        // printf("\ntest end\n");
        uint8x8_t  r = vld1_u8(test_vec_s16[i].r);
        uint8x16_t rst = vqmovun_high_s16(r, a);
        printf("{ ");
        for(int j = 0;j < 16;j ++){
            test_codegen_u8(rst[j]);
            if(j != 15)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f2(){

    for (size_t i = 0 ; i < (sizeof(test_vec_s32) / sizeof(test_vec_s32[0])) ; i++) {
        int32x4_t a = vld1q_s32(test_vec_s32[i].a);
        uint16x4_t r = vld1_u16(test_vec_s32[i].r);
        uint16x8_t rst = vqmovun_high_s32(r, a);

        printf("{ ");
        for(int j = 0;j < 8;j ++){
            test_codegen_u16(rst[j]);
            if(j != 7)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f3(){

    for (size_t i = 0 ; i < (sizeof(test_vec_s64) / sizeof(test_vec_s64[0])) ; i++) {
        int64x2_t a = vld1q_s64(test_vec_s64[i].a);
        uint32x2_t  r = vld1_u32(test_vec_s64[i].r);
        uint32x4_t rst = vqmovun_high_s64(r, a);

        printf("{ ");
        for(int j = 0;j < 4;j ++){
            test_codegen_u32(rst[j]);
            if(j != 3)printf(", ");
        }
        printf(" }\n");
    }
    
}
