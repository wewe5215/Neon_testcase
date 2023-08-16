#include "print_output.h"
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();

static const struct {
    int8_t r[8];
    int16_t a[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r6[8];
    int8_t r8[8];
  } test_vec_s16[] = {
    { { -INT8_C( 123), -INT8_C(  96), -INT8_C(  78),  INT8_C(  55), -INT8_C( 106),  INT8_C( 121),  INT8_C(  65),  INT8_C( 110) },
      {  INT16_C( 17489), -INT16_C( 13897), -INT16_C( 15964), -INT16_C( 31986), -INT16_C( 14437),  INT16_C( 11700),  INT16_C( 29840), -INT16_C(  9747) } },
    { {  INT8_C(  81),  INT8_C( 113), -INT8_C(  84),  INT8_C(  92),  INT8_C( 116), -INT8_C(  44),  INT8_C(  95), -INT8_C(  80) },
      { -INT16_C( 24196), -INT16_C( 12741), -INT16_C( 20535), -INT16_C( 14789), -INT16_C( 31367),  INT16_C( 20125),  INT16_C( 31476), -INT16_C(  3558) } },
    { { -INT8_C(  64),  INT8_C( 111),  INT8_C(  92), -INT8_C(  68), -INT8_C(  12),  INT8_C(  28), -INT8_C( 127), -INT8_C( 116) },
      {  INT16_C( 14681),  INT16_C( 13369),  INT16_C( 22055),  INT16_C( 28761), -INT16_C(  5701), -INT16_C( 23057),  INT16_C( 18894),  INT16_C(  4645) } },
    { { -INT8_C(  75), -INT8_C( 105), -INT8_C(   6), -INT8_C(  32), -INT8_C(  55),  INT8_C( 123), -INT8_C(   4),  INT8_C(   2) },
      {  INT16_C( 14751), -INT16_C( 24728),  INT16_C( 29861), -INT16_C( 15554), -INT16_C(  8471),  INT16_C(  4976), -INT16_C( 16385), -INT16_C(  7793) } },
    { { -INT8_C(  36),      INT8_MAX,  INT8_C(  79), -INT8_C(  11), -INT8_C(  32), -INT8_C(  22), -INT8_C( 124), -INT8_C(  84) },
      {  INT16_C( 26373),  INT16_C(  8867), -INT16_C(  7812), -INT16_C(  2801), -INT16_C(  8260),  INT16_C( 23375), -INT16_C( 21112), -INT16_C( 14942) } },
    { { -INT8_C(  86), -INT8_C( 100), -INT8_C( 109), -INT8_C( 126),  INT8_C(  29),  INT8_C( 123), -INT8_C( 122), -INT8_C(  39) },
      {  INT16_C(  7488), -INT16_C( 26905),  INT16_C( 29630),  INT16_C( 27621), -INT16_C(  1635),  INT16_C( 15826), -INT16_C( 16371), -INT16_C( 31096) } },
    { {  INT8_C(  45), -INT8_C(  58), -INT8_C(  77), -INT8_C( 119),  INT8_C(  63), -INT8_C(  32),  INT8_C(  66), -INT8_C(   4) },
      {  INT16_C(  7454),  INT16_C( 24642),  INT16_C(   347), -INT16_C( 21878), -INT16_C(  7068), -INT16_C( 20914),  INT16_C(  7127), -INT16_C( 21571) } },
    { { -INT8_C(  12), -INT8_C(  32), -INT8_C(  31),  INT8_C(  67),  INT8_C(  17),  INT8_C(   4),  INT8_C(  19), -INT8_C(  82) },
      {  INT16_C( 14952),  INT16_C(   476), -INT16_C( 22828),  INT16_C( 30762),  INT16_C( 31030), -INT16_C( 13121),  INT16_C(  9411),  INT16_C( 25805) } }
  };

static const struct {
    int16_t r[4];
    int32_t a[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec_s32[] = {
    { {  INT16_C(  5420),  INT16_C( 20512), -INT16_C( 31368),  INT16_C( 21319) },
      { -INT32_C(  1794592298),  INT32_C(  1718566559), -INT32_C(    79978991),  INT32_C(  1983557475) } },
    { {  INT16_C(  8924),  INT16_C(  1578),  INT16_C( 27125),  INT16_C(  7556) },
      {  INT32_C(   587252527), -INT32_C(   647965957),  INT32_C(  1310489966),  INT32_C(  1964015166) } },
    { { -INT16_C( 23608),  INT16_C( 14821),  INT16_C( 22479), -INT16_C(  6780) },
      {  INT32_C(  1522393729),  INT32_C(   990405273),  INT32_C(   194219272),  INT32_C(  1197981175) } },
    { {  INT16_C( 16983), -INT16_C( 23474),  INT16_C( 10961),  INT16_C( 11960) },
      {  INT32_C(   705725686), -INT32_C(   257213587),  INT32_C(    34524587), -INT32_C(  1292894515) } },
    { {  INT16_C( 21412), -INT16_C( 12926), -INT16_C( 20888),  INT16_C( 17944) },
      {  INT32_C(  1357408422),  INT32_C(   974836364),  INT32_C(   294859421),  INT32_C(  2101269167) } },
    { {  INT16_C( 14213),  INT16_C(  3913), -INT16_C(  7534),  INT16_C( 21038) },
      { -INT32_C(  1267603059),  INT32_C(   527420900), -INT32_C(   234279170),  INT32_C(  1601504729) } },
    { { -INT16_C( 28122),  INT16_C( 11364), -INT16_C(    41), -INT16_C( 17893) },
      {  INT32_C(  1299360873),  INT32_C(   120897336),  INT32_C(   956748349), -INT32_C(   998170684) } },
    { {  INT16_C( 10135),  INT16_C( 31590),  INT16_C( 11084),  INT16_C( 17456) },
      { -INT32_C(   669667285), -INT32_C(  1614370399),  INT32_C(   715121523),  INT32_C(   587966419) } }
  };

  static const struct {
    int32_t r[2];
    int64_t a[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec_s64[] = {
    { { -INT32_C(  1444876187), -INT32_C(   732064427) },
      {  INT64_C( 3854894980665946194),  INT64_C( 8345263523887248971) } },
    { { -INT32_C(  1707558645), -INT32_C(  1586076513) },
      { -INT64_C( 6707788376594497471), -INT64_C( 1226634615498383421) } },
    { { -INT32_C(   497065740),  INT32_C(  1445834898) },
      {  INT64_C( 8001153219238961270),  INT64_C( 4377469737198390758) } },
    { { -INT32_C(   548895936),  INT32_C(  1597861681) },
      { -INT64_C( 4137339402318269391), -INT64_C( 5957945389555508384) } },
    { {  INT32_C(  1842422922),  INT32_C(  1863259422) },
      {  INT64_C( 7964731052541579506),  INT64_C( 2442283504187914105) } },
    { { -INT32_C(   863719058), -INT32_C(    51753654) },
      { -INT64_C( 3641369576625434408), -INT64_C( 4297513630649967139) } },
    { {  INT32_C(   274293632),  INT32_C(   796197747) },
      { -INT64_C( 4783285835317123381), -INT64_C( 5195658752590984899) } },
    { {  INT32_C(  1416156662), -INT32_C(  1927827321) },
      { -INT64_C( 6304655449917022466),  INT64_C( 6451602799191894966) } }
  };

  static const struct {
    uint8_t r[8];
    uint16_t a[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r8[8];
  } test_vec_u16[] = {
    { { UINT8_C( 52), UINT8_C(110), UINT8_C( 48), UINT8_C(127), UINT8_C(145), UINT8_C(154), UINT8_C(118), UINT8_C( 93) },
      { UINT16_C(61735), UINT16_C(61930), UINT16_C(43166), UINT16_C(17044), UINT16_C(61314), UINT16_C(14307), UINT16_C(13958), UINT16_C(47484) } },
    { { UINT8_C( 12), UINT8_C(218), UINT8_C(225), UINT8_C( 65), UINT8_C(174), UINT8_C(120), UINT8_C( 44), UINT8_C(138) },
      { UINT16_C(32149), UINT16_C( 8492), UINT16_C( 1704), UINT16_C(51023), UINT16_C(43624), UINT16_C(54607), UINT16_C(17586), UINT16_C(28107) } },
    { { UINT8_C( 66), UINT8_C(180), UINT8_C(203), UINT8_C(176), UINT8_C( 72), UINT8_C(173), UINT8_C(119), UINT8_C(135) },
      { UINT16_C(10973), UINT16_C(50583), UINT16_C(58301), UINT16_C(40089), UINT16_C(  993), UINT16_C(37072), UINT16_C( 5507), UINT16_C(56704) } },
    { { UINT8_C(195), UINT8_C( 48), UINT8_C(237), UINT8_C(165), UINT8_C(151), UINT8_C( 21), UINT8_C(104), UINT8_C(110) },
      { UINT16_C(23010), UINT16_C(11365), UINT16_C(11833), UINT16_C(47994), UINT16_C( 9718), UINT16_C(28304), UINT16_C(37597), UINT16_C(46726) } },
    { { UINT8_C(151), UINT8_C( 86), UINT8_C( 54), UINT8_C(178), UINT8_C( 12),    UINT8_MAX, UINT8_C(225), UINT8_C(106) },
      { UINT16_C(41833), UINT16_C(19740), UINT16_C(56724), UINT16_C(17778), UINT16_C( 3399), UINT16_C(30065), UINT16_C(  332), UINT16_C( 1504) } },
    { { UINT8_C(110), UINT8_C( 28), UINT8_C(251), UINT8_C( 98), UINT8_C( 58), UINT8_C(225), UINT8_C(110), UINT8_C( 31) },
      { UINT16_C(19575), UINT16_C(48995), UINT16_C(50925), UINT16_C( 8684), UINT16_C(34493), UINT16_C(27122), UINT16_C(25941), UINT16_C(21475) } },
    { { UINT8_C(103), UINT8_C(119), UINT8_C(181), UINT8_C( 22), UINT8_C(108), UINT8_C(233), UINT8_C(189), UINT8_C(159) },
      { UINT16_C( 8246), UINT16_C(20166), UINT16_C(16249), UINT16_C(34480), UINT16_C(60634), UINT16_C(57663), UINT16_C(20156), UINT16_C(43170) } },
    { { UINT8_C( 97), UINT8_C( 54), UINT8_C(  3), UINT8_C(175), UINT8_C(211), UINT8_C( 89), UINT8_C( 70), UINT8_C( 36) },
      { UINT16_C(61455), UINT16_C(33659), UINT16_C(45094), UINT16_C(55604), UINT16_C(63655), UINT16_C(18906), UINT16_C(34086), UINT16_C(17837) } }
  };


  static const struct {
    uint16_t r[4];
    uint32_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec_u32[] = {
     { { UINT16_C(11515), UINT16_C(56724), UINT16_C(29226), UINT16_C(39010) },
      { UINT32_C(1327324489), UINT32_C( 861541704), UINT32_C(1041216955), UINT32_C(2597963354) } },
    { { UINT16_C( 4881), UINT16_C(46681), UINT16_C(18976), UINT16_C(43495) },
      { UINT32_C(3155205702), UINT32_C(2311789105), UINT32_C(1577545922), UINT32_C(2963899160) } },
    { { UINT16_C( 7259), UINT16_C(64830), UINT16_C(53735), UINT16_C(59662) },
      { UINT32_C( 853443395), UINT32_C( 924532494), UINT32_C(1799302565), UINT32_C( 328879937) } },
    { { UINT16_C( 7300), UINT16_C(13886), UINT16_C(60356), UINT16_C(18220) },
      { UINT32_C(3520385062), UINT32_C(1902265947), UINT32_C(1958342690), UINT32_C(4083448517) } },
    { { UINT16_C(52945), UINT16_C(26508), UINT16_C(22384), UINT16_C(54918) },
      { UINT32_C(3820404930), UINT32_C(3857108177), UINT32_C(1243087465), UINT32_C( 166460830) } },
    { { UINT16_C(36656), UINT16_C(13104), UINT16_C(55738), UINT16_C(42324) },
      { UINT32_C(1580874396), UINT32_C(2132853925), UINT32_C(2241061938), UINT32_C(2139337663) } },
    { { UINT16_C(40530), UINT16_C(40780), UINT16_C(51618), UINT16_C(14764) },
      { UINT32_C( 280434717), UINT32_C( 538398062), UINT32_C(3647578689), UINT32_C(3534786249) } },
    { { UINT16_C(44577), UINT16_C(46573), UINT16_C( 4080), UINT16_C(55028) },
      { UINT32_C(3526068156), UINT32_C(3203009810), UINT32_C(2033564502), UINT32_C(2257401823) } }
  };


  static const struct {
    uint32_t r[2];
    uint64_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec_u64[] = {
    { { UINT32_C(3725420213), UINT32_C(2853251059) },
      { UINT64_C( 4616196863405086591), UINT64_C( 1481492961733953541) } },
    { { UINT32_C(2420054159), UINT32_C(2439756532) },
      { UINT64_C(  258277031999162605), UINT64_C( 7868157611086422504) } },
    { { UINT32_C(3240020435), UINT32_C(4169784202) },
      { UINT64_C(15444835347369046869), UINT64_C(18436473213551224630) } },
    { { UINT32_C( 880234685), UINT32_C( 701563847) },
      { UINT64_C(17520482062911376104), UINT64_C( 1083098973719063194) } },
    { { UINT32_C(2244817019), UINT32_C(3971307011) },
      { UINT64_C( 2965752511546104870), UINT64_C(15739239050598471150) } },
    { { UINT32_C(2544660036), UINT32_C(1532806077) },
      { UINT64_C( 5332064191089056150), UINT64_C(14756909172010690856) } },
    { { UINT32_C(3404101443), UINT32_C(1468537534) },
      { UINT64_C( 9981975300612371642), UINT64_C(14880608678333960351) } },
    { { UINT32_C( 381025713), UINT32_C(3813351308) },
      { UINT64_C( 8149435611365995467), UINT64_C( 6854463686671593842) } }
  };


  int main(){
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
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
        int8x8_t  r = vld1_s8(test_vec_s16[i].r);
        int8x16_t rst = vqmovun_high_s16(r, a);
        printf("{ ");
        for(int j = 0;j < 16;j ++){
            test_codegen_i8(rst[j]);
            if(j != 15)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f2(){

    for (size_t i = 0 ; i < (sizeof(test_vec_s32) / sizeof(test_vec_s32[0])) ; i++) {
        int32x4_t a = vld1q_s32(test_vec_s32[i].a);
        int16x4_t r = vld1_s16(test_vec_s32[i].r);
        int16x8_t rst = vqmovun_high_s32(r, a);

        printf("{ ");
        for(int j = 0;j < 8;j ++){
            test_codegen_i16(rst[j]);
            if(j != 7)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f3(){

    for (size_t i = 0 ; i < (sizeof(test_vec_s64) / sizeof(test_vec_s64[0])) ; i++) {
        int64x2_t a = vld1q_s64(test_vec_s64[i].a);
        int32x2_t  r = vld1_s32(test_vec_s64[i].r);
        int32x4_t rst = vqmovun_high_s64(r, a);

        printf("{ ");
        for(int j = 0;j < 4;j ++){
            test_codegen_i32(rst[j]);
            if(j != 3)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f4(){

    for (size_t i = 0 ; i < (sizeof(test_vec_u16) / sizeof(test_vec_u16[0])) ; i++) {
        uint16x8_t a = vld1q_u16(test_vec_u16[i].a);
        uint8x8_t  r = vld1_u8(test_vec_u16[i].r);
        uint8x16_t rst = vqmovun_high_u16(r, a);

        printf("{ ");
        for(int j = 0;j < 16;j ++){
            test_codegen_u8(rst[j]);
            if(j != 15)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f5(){

    for (size_t i = 0 ; i < (sizeof(test_vec_u32) / sizeof(test_vec_u32[0])) ; i++) {
        uint32x4_t a = vld1q_u32(test_vec_u32[i].a);
        uint16x4_t  r = vld1_u16(test_vec_u32[i].r);
        uint16x8_t rst = vqmovun_high_u32(r, a);

        printf("{ ");
        for(int j = 0;j < 8;j ++){
            test_codegen_u16(rst[j]);
            if(j != 7)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f6(){

    for (size_t i = 0 ; i < (sizeof(test_vec_u64) / sizeof(test_vec_u64[0])) ; i++) {
        uint64x2_t a = vld1q_u64(test_vec_u64[i].a);
        uint32x2_t  r = vld1_u32(test_vec_u64[i].r);
        uint32x4_t rst = vqmovun_high_u64(r, a);

        printf("{ ");
        for(int j = 0;j < 4;j ++){
            test_codegen_u32(rst[j]);
            if(j != 3)printf(", ");
        }
        printf(" }\n");
    }
    
}