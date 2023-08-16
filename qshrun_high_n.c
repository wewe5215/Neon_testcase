#include "print_output.h"
void f1();
void f2();
void f3();

static const struct {
    uint8_t r[8];
    int16_t a[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r8[8];
  } test_vec_s16[] = {
    { { UINT8_C( 95), UINT8_C(253), UINT8_C( 67), UINT8_C(133), UINT8_C( 54), UINT8_C( 72), UINT8_C(114), UINT8_C( 35) },
      { -INT16_C( 14432), -INT16_C( 19665), -INT16_C( 30781),  INT16_C( 18179),  INT16_C( 27771), -INT16_C( 27992),  INT16_C(  2100), -INT16_C( 17107) } },
    { { UINT8_C( 25), UINT8_C(158), UINT8_C(167), UINT8_C( 23), UINT8_C(172), UINT8_C(121), UINT8_C( 95), UINT8_C( 93) },
      { -INT16_C(  3689), -INT16_C( 30687),  INT16_C( 22687), -INT16_C(  6197), -INT16_C( 29396), -INT16_C( 26494), -INT16_C( 16107), -INT16_C(  2699) } },
    { { UINT8_C(148), UINT8_C(196), UINT8_C(179), UINT8_C(211), UINT8_C(240), UINT8_C(218), UINT8_C( 30), UINT8_C(170) },
      {  INT16_C( 15635), -INT16_C(  1095), -INT16_C(  1962),  INT16_C( 14556),  INT16_C( 11807), -INT16_C( 15971),  INT16_C( 23850), -INT16_C(  2541) } },
    { { UINT8_C(123), UINT8_C(220), UINT8_C( 36), UINT8_C(251), UINT8_C( 77), UINT8_C( 27), UINT8_C( 26), UINT8_C(144) },
      {  INT16_C( 21844),  INT16_C( 17546),  INT16_C( 27403), -INT16_C( 25675),  INT16_C(  6059), -INT16_C( 23213), -INT16_C( 23065), -INT16_C( 28097) } },
    { { UINT8_C( 34), UINT8_C( 31), UINT8_C(211), UINT8_C(175), UINT8_C(179), UINT8_C(154), UINT8_C( 28), UINT8_C(244) },
      { -INT16_C( 26137),  INT16_C( 11014), -INT16_C(  4956),  INT16_C(  9180),  INT16_C(  6506),  INT16_C( 20965), -INT16_C( 17461),  INT16_C( 13864) } },
    { { UINT8_C(  9), UINT8_C( 34), UINT8_C( 61), UINT8_C( 19), UINT8_C( 34), UINT8_C(199), UINT8_C( 79), UINT8_C(194) },
      {  INT16_C( 27866),  INT16_C(  1218), -INT16_C( 15835),  INT16_C( 30500),  INT16_C(  7000), -INT16_C(  8219), -INT16_C( 29804), -INT16_C(  1421) } },
    { { UINT8_C(127), UINT8_C(225), UINT8_C(155), UINT8_C(170), UINT8_C(218), UINT8_C(135), UINT8_C( 65), UINT8_C( 86) },
      { -INT16_C( 15452),  INT16_C(  6438),  INT16_C( 19267),  INT16_C(  1448), -INT16_C(  4577), -INT16_C( 29814),  INT16_C( 20455),  INT16_C( 21485) } },
    { { UINT8_C(142), UINT8_C(224), UINT8_C( 69), UINT8_C(210), UINT8_C(  5), UINT8_C(101), UINT8_C( 57), UINT8_C(160) },
      { -INT16_C( 12992), -INT16_C( 21658),  INT16_C(  7994), -INT16_C( 11004),  INT16_C(   280), -INT16_C( 31192),  INT16_C( 24751), -INT16_C(   739) } }
  };

  static const struct {
    uint16_t r[4];
    int32_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec_s32[] = {
    { { UINT16_C(43253), UINT16_C( 2478), UINT16_C(56140), UINT16_C(55778) },
      {  INT32_C(  1920157294), -INT32_C(   300805757), -INT32_C(  1029848471),  INT32_C(  1330264363) } },
    { { UINT16_C(48618), UINT16_C(20034), UINT16_C( 3487), UINT16_C(13846) },
      {  INT32_C(   709606426),  INT32_C(   573534466), -INT32_C(  2139013035),  INT32_C(   172058979) } },
    { { UINT16_C(56539), UINT16_C(53494), UINT16_C(52001), UINT16_C(60251) },
      { -INT32_C(  1395005089), -INT32_C(  1259486511),  INT32_C(  1667064208),  INT32_C(  1407510396) } },
    { { UINT16_C( 2400), UINT16_C(47684), UINT16_C(39669), UINT16_C(29260) },
      { -INT32_C(  1790908253),  INT32_C(   529719724),  INT32_C(  1177729092),  INT32_C(  1884025397) } },
    { { UINT16_C(55092), UINT16_C(55544), UINT16_C(13155), UINT16_C(58383) },
      {  INT32_C(  2085871297), -INT32_C(     2538829),  INT32_C(   321247499),  INT32_C(  1962635112) } },
    { { UINT16_C(56511), UINT16_C(23797), UINT16_C(43417), UINT16_C(58760) },
      {  INT32_C(  1116234305), -INT32_C(   421741053),  INT32_C(  1845866756), -INT32_C(   326467475) } },
    { { UINT16_C(16295), UINT16_C(63460), UINT16_C(11245), UINT16_C(21481) },
      { -INT32_C(   475613415), -INT32_C(  1895292838), -INT32_C(   686867993),  INT32_C(  1169276858) } },
    { { UINT16_C(57959), UINT16_C( 8300), UINT16_C( 3192), UINT16_C(56539) },
      { -INT32_C(   133056155), -INT32_C(  1013030213), -INT32_C(  1289251948),  INT32_C(  2040091664) } }
  };

  static const struct {
    uint32_t r[2];
    int64_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec_s64[] = {
    { { UINT32_C( 795181781), UINT32_C( 374509411) },
      { -INT64_C( 2304910774862613985),  INT64_C( 3739339150601777303) } },
    { { UINT32_C(2855523888), UINT32_C(3167853887) },
      { -INT64_C( 3028955754168039738),  INT64_C( 8993818754820291243) } },
    { { UINT32_C(3928328711), UINT32_C(1084843591) },
      {  INT64_C(  751050003863976573), -INT64_C( 5734028920069986541) } },
    { { UINT32_C(4170359331), UINT32_C(2978252638) },
      {  INT64_C( 8765204361208570366),  INT64_C( 3506917292750602861) } },
    { { UINT32_C(1142264635), UINT32_C(3426108716) },
      { -INT64_C(  309203940017744254),  INT64_C( 3092393508432591191) } },
    { { UINT32_C(2500932121), UINT32_C(2695885993) },
      { -INT64_C( 8599875020522110601),  INT64_C( 7001220534826729206) } },
    { { UINT32_C(1584280972), UINT32_C( 445878272) },
      { -INT64_C(  874395579245280872), -INT64_C( 3961988940309159867) } },
    { { UINT32_C(1295314990), UINT32_C(1907764625) },
      {  INT64_C( 6437380961556713154),  INT64_C( 8229107360312644037) } }
  };

int main(){
    f1();
    f2();
    f3();
    
    return 0;
}

void f1(){
    printf("qshrun_high_s16:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_s16) / sizeof(test_vec_s16[0])) ; i++) {
        int16x8_t a = vld1q_s16(test_vec_s16[i].a);
        uint8x8_t  r = vld1_u8(test_vec_s16[i].r);
        print_uint8x16(vqshrun_high_n_s16(r, a, 1));
        print_uint8x16(vqshrun_high_n_s16(r, a, 3));
        print_uint8x16(vqshrun_high_n_s16(r, a, 5));
        print_uint8x16(vqshrun_high_n_s16(r, a, 6));
        print_uint8x16(vqshrun_high_n_s16(r, a, 8));
    }
    
}

void f2(){
    printf("qshrun_high_s32:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_s32) / sizeof(test_vec_s32[0])) ; i++) {
        int32x4_t a = vld1q_s32(test_vec_s32[i].a);
        uint16x4_t r = vld1_u16(test_vec_s32[i].r);
        print_uint16x8(vqshrun_high_n_s32(r, a, 3));
        print_uint16x8(vqshrun_high_n_s32(r, a, 6));
        print_uint16x8(vqshrun_high_n_s32(r, a, 10));
        print_uint16x8(vqshrun_high_n_s32(r, a, 13));
        print_uint16x8(vqshrun_high_n_s32(r, a, 16));

        
    }
    
}

void f3(){
    printf("qshrn_high_s64:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_s64) / sizeof(test_vec_s64[0])) ; i++) {
        int64x2_t a = vld1q_s64(test_vec_s64[i].a);
        uint32x2_t  r = vld1_u32(test_vec_s64[i].r);
        print_uint32x4(vqshrun_high_n_s64(r, a, 6));
        print_uint32x4(vqshrun_high_n_s64(r, a, 13));
        print_uint32x4(vqshrun_high_n_s64(r, a, 19));
        print_uint32x4(vqshrun_high_n_s64(r, a, 26));
        print_uint32x4(vqshrun_high_n_s64(r, a, 32));
    }
    
}
