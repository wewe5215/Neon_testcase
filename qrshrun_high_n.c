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
    { { UINT8_C( 99), UINT8_C(154), UINT8_C( 93), UINT8_C( 91), UINT8_C(120), UINT8_C( 91), UINT8_C( 21), UINT8_C(227) },
      {  INT16_C(  7645),  INT16_C(  2911), -INT16_C(  1231),  INT16_C( 23471),  INT16_C( 29601), -INT16_C(  8429),  INT16_C(  1389), -INT16_C( 25926) } },
    { { UINT8_C( 67), UINT8_C( 54), UINT8_C( 33), UINT8_C( 34), UINT8_C(105), UINT8_C(156), UINT8_C(105), UINT8_C(191) },
      { -INT16_C( 27991),  INT16_C( 25078), -INT16_C( 27468), -INT16_C( 28540),  INT16_C( 28543),  INT16_C( 29441), -INT16_C( 15354), -INT16_C( 26221) } },
    { { UINT8_C(102), UINT8_C(211), UINT8_C(158), UINT8_C( 20), UINT8_C(106), UINT8_C(180), UINT8_C(222), UINT8_C(191) },
      { -INT16_C(  3356),  INT16_C( 31600),  INT16_C( 31881),  INT16_C(   224),  INT16_C(  8170),  INT16_C(  2983),  INT16_C( 27113), -INT16_C(  2927) } },
    { { UINT8_C(120), UINT8_C(158), UINT8_C(119), UINT8_C( 21), UINT8_C(115), UINT8_C(195), UINT8_C(161), UINT8_C( 76) },
      {  INT16_C(   433),  INT16_C( 14250), -INT16_C( 16012),  INT16_C( 23422), -INT16_C( 30351), -INT16_C( 10200), -INT16_C( 30189),  INT16_C( 25550) } },
    { { UINT8_C( 36), UINT8_C(205), UINT8_C(212), UINT8_C(213), UINT8_C(218), UINT8_C(210), UINT8_C(175), UINT8_C( 66) },
      { -INT16_C( 31108),  INT16_C( 20763),  INT16_C( 29384), -INT16_C( 21787),  INT16_C( 20304),  INT16_C( 17173),  INT16_C(  1052),  INT16_C(   714) } },
    { { UINT8_C(172), UINT8_C(188), UINT8_C( 17), UINT8_C( 51), UINT8_C(194), UINT8_C(101), UINT8_C(171), UINT8_C(165) },
      {  INT16_C(  1765),  INT16_C( 17651), -INT16_C( 21745),  INT16_C(  5087),  INT16_C( 17981),  INT16_C( 29362), -INT16_C(  4797),  INT16_C( 18375) } },
    { { UINT8_C(103), UINT8_C(233), UINT8_C(239), UINT8_C(177), UINT8_C(244), UINT8_C(230), UINT8_C(142), UINT8_C( 81) },
      { -INT16_C(  7173),  INT16_C( 18015),  INT16_C( 24150), -INT16_C(  6853), -INT16_C( 15970), -INT16_C( 28531), -INT16_C( 12273),  INT16_C( 27280) } },
    { { UINT8_C(121), UINT8_C(175), UINT8_C( 43), UINT8_C( 26), UINT8_C(  2), UINT8_C(203), UINT8_C(178), UINT8_C(221) },
      {  INT16_C(   837), -INT16_C( 24329), -INT16_C(  1731),  INT16_C( 30357), -INT16_C(  5896),  INT16_C( 28650), -INT16_C( 14335), -INT16_C(  5965) } }
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
    { { UINT16_C(16366), UINT16_C(18233), UINT16_C(11907), UINT16_C(48769) },
      { -INT32_C(  1604534005),  INT32_C(   330036457), -INT32_C(   149089235), -INT32_C(  1324905320) } },
    { { UINT16_C(15870), UINT16_C(39284), UINT16_C(21719), UINT16_C(26322) },
      { -INT32_C(   174212623), -INT32_C(    23339925),  INT32_C(  2059279859),  INT32_C(  1056077718) } },
    { { UINT16_C( 2087), UINT16_C(37115), UINT16_C(16814), UINT16_C(57285) },
      {  INT32_C(   551473337),  INT32_C(  1208051004), -INT32_C(   932635250), -INT32_C(  1798361270) } },
    { { UINT16_C(31337), UINT16_C(42030), UINT16_C(24141), UINT16_C(11936) },
      {  INT32_C(  1498905550), -INT32_C(    20272923), -INT32_C(  1183842126), -INT32_C(   227515568) } },
    { { UINT16_C(49862), UINT16_C(14423), UINT16_C(54098), UINT16_C(29175) },
      {  INT32_C(    95035627), -INT32_C(   297498649),  INT32_C(  2090855195), -INT32_C(  1333408247) } },
    { { UINT16_C(39132), UINT16_C(22031), UINT16_C( 5727), UINT16_C(35125) },
      { -INT32_C(  1389880577),  INT32_C(   263314837), -INT32_C(   770811833), -INT32_C(  1903920705) } },
    { { UINT16_C(61238), UINT16_C(34406), UINT16_C(55038), UINT16_C(51259) },
      {  INT32_C(   176013093),  INT32_C(   963311694),  INT32_C(   581005142),  INT32_C(  2017387570) } },
    { { UINT16_C(59052), UINT16_C(64213), UINT16_C(14238), UINT16_C(59317) },
      { -INT32_C(  1897566396), -INT32_C(   916418712), -INT32_C(   140840190),  INT32_C(  2034928905) } }
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
    { { UINT32_C(3482227690), UINT32_C(1264588417) },
      {  INT64_C( 6953026414930263737),  INT64_C( 8213453428290475312) } },
    { { UINT32_C( 698416382), UINT32_C(1397799666) },
      { -INT64_C( 4307325506891900630), -INT64_C( 5226522582593554039) } },
    { { UINT32_C(1914063491), UINT32_C( 990000926) },
      { -INT64_C( 6100944502747307706), -INT64_C( 4528602699021776345) } },
    { { UINT32_C(3942452416), UINT32_C(3317720436) },
      { -INT64_C( 1678884271372245465),  INT64_C( 9199809157723513403) } },
    { { UINT32_C(1727208411), UINT32_C(3332711251) },
      {  INT64_C( 5019449461794357147),  INT64_C(  286814725310965820) } },
    { { UINT32_C(3820449018), UINT32_C( 944002671) },
      {  INT64_C(  658823838754956670), -INT64_C( 7474429435094114049) } },
    { { UINT32_C(1305735140), UINT32_C(1791615043) },
      { -INT64_C( 2035067311733928207),  INT64_C( 8065668128802511056) } },
    { { UINT32_C(2573024389), UINT32_C(2383572333) },
      { -INT64_C( 3496687191848179183), -INT64_C( 9106550386587963544) } }
  };

int main(){
    f1();
    f2();
    f3();
    
    return 0;
}

void f1(){
    printf("qrshrun_high_s16:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_s16) / sizeof(test_vec_s16[0])) ; i++) {
        int16x8_t a = vld1q_s16(test_vec_s16[i].a);
        uint8x8_t  r = vld1_u8(test_vec_s16[i].r);
        print_uint8x16(vqrshrun_high_s16(r, a, 1));
        print_uint8x16(vqrshrun_high_s16(r, a, 3));
        print_uint8x16(vqrshrun_high_s16(r, a, 5));
        print_uint8x16(vqrshrun_high_s16(r, a, 6));
        print_uint8x16(vqrshrun_high_s16(r, a, 8));
    }
    
}

void f2(){
    printf("qrshrun_high_s32:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_s32) / sizeof(test_vec_s32[0])) ; i++) {
        int32x4_t a = vld1q_s32(test_vec_s32[i].a);
        uint16x4_t r = vld1_u16(test_vec_s32[i].r);
        print_uint16x8(vqrshrun_high_s32(r, a, 3));
        print_uint16x8(vqrshrun_high_s32(r, a, 6));
        print_uint16x8(vqrshrun_high_s32(r, a, 10));
        print_uint16x8(vqrshrun_high_s32(r, a, 13));
        print_uint16x8(vqrshrun_high_s32(r, a, 16));

        
    }
    
}

void f3(){
    printf("qrshrn_high_s64:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_s64) / sizeof(test_vec_s64[0])) ; i++) {
        int64x2_t a = vld1q_s64(test_vec_s64[i].a);
        uint32x2_t  r = vld1_u32(test_vec_s64[i].r);
        print_uint32x4(vqrshrun_high_s64(r, a, 6));
        print_uint32x4(vqrshrun_high_s64(r, a, 13));
        print_uint32x4(vqrshrun_high_s64(r, a, 19));
        print_uint32x4(vqrshrun_high_s64(r, a, 26));
        print_uint32x4(vqrshrun_high_s64(r, a, 32));
    }
    
}