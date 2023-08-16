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
    { { -INT8_C(  65),  INT8_C(  67), -INT8_C(  48), -INT8_C(   6), -INT8_C(   4),  INT8_C(  12),  INT8_C( 101),  INT8_C(  35) },
      {  INT16_C( 19333),  INT16_C( 23203),  INT16_C(  1682), -INT16_C( 13175), -INT16_C( 22459), -INT16_C(  7024),  INT16_C( 29487),  INT16_C( 15621) } },
    { { -INT8_C(  90), -INT8_C(  89), -INT8_C(  80), -INT8_C(  27), -INT8_C(  67),  INT8_C(  51),  INT8_C(  17),  INT8_C( 118) },
      {  INT16_C( 27001),  INT16_C(  8560),  INT16_C( 10400),  INT16_C( 19388),  INT16_C( 32266), -INT16_C( 13884),  INT16_C(  8312),  INT16_C( 16176) } },
    { {  INT8_C( 110), -INT8_C(  53), -INT8_C(  54), -INT8_C( 119), -INT8_C(  24),  INT8_C(  80), -INT8_C(  99), -INT8_C(  83) },
      { -INT16_C( 15078), -INT16_C(  5352),  INT16_C( 29990),  INT16_C( 21906), -INT16_C(  2337),  INT16_C( 11973),  INT16_C( 15803),  INT16_C( 19464) } },
    { {  INT8_C(  33),  INT8_C(  92), -INT8_C(  16),  INT8_C(  86), -INT8_C(  80), -INT8_C( 112),  INT8_C(  93), -INT8_C(  18) },
      { -INT16_C(   549),  INT16_C(  1604), -INT16_C(  6877),  INT16_C( 20765), -INT16_C(  7482),  INT16_C( 27847), -INT16_C( 22808),  INT16_C( 22584) } },
    { { -INT8_C(  64),  INT8_C(  59), -INT8_C(   3),  INT8_C(  89), -INT8_C(  57),  INT8_C( 109),  INT8_C(  25),  INT8_C(  90) },
      {  INT16_C( 25413),  INT16_C( 18454), -INT16_C( 32653),  INT16_C(  3515),  INT16_C(  4742), -INT16_C(  6974), -INT16_C(  8898),  INT16_C(  8864) } },
    { { -INT8_C( 122), -INT8_C(  30), -INT8_C(  38),  INT8_C( 100),  INT8_C(  65), -INT8_C(  43),  INT8_C(  85), -INT8_C(  71) },
      {  INT16_C(   841), -INT16_C( 16906), -INT16_C(  8088), -INT16_C( 21265), -INT16_C( 16149),  INT16_C( 32691),  INT16_C( 17044),  INT16_C( 18321) } },
    { {  INT8_C(  50),  INT8_C(  38),  INT8_C(  36), -INT8_C(  14), -INT8_C(  36), -INT8_C(  84),  INT8_C(   0), -INT8_C(  18) },
      {  INT16_C(   254), -INT16_C( 20033), -INT16_C(  9079), -INT16_C(  8497), -INT16_C(  2662), -INT16_C(  7219),  INT16_C(   603), -INT16_C(  5736) } },
    { { -INT8_C(  38),  INT8_C( 103),  INT8_C(  23), -INT8_C(  53),  INT8_C(  58),  INT8_C(  90),  INT8_C( 104), -INT8_C(  25) },
      {  INT16_C( 32644),  INT16_C( 22370),  INT16_C( 18262),  INT16_C( 19772),  INT16_C( 29294), -INT16_C(  7172), -INT16_C(  7581),  INT16_C(  1341) } }
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
    { { -INT16_C(  4770),  INT16_C( 20831), -INT16_C( 16268), -INT16_C( 28389) },
      {  INT32_C(   816788865),  INT32_C(   213086101), -INT32_C(  1650562541), -INT32_C(  1998724300) } },
    { {  INT16_C(  1162),  INT16_C(  3061), -INT16_C( 11017), -INT16_C(  2793) },
      {  INT32_C(   449798497),  INT32_C(  1952434572),  INT32_C(  1028066381), -INT32_C(   797616751) } },
    { {  INT16_C(  7042), -INT16_C( 16096), -INT16_C( 18783), -INT16_C( 29090) },
      { -INT32_C(  2052082100), -INT32_C(  1395268058),  INT32_C(  1779284001),  INT32_C(   403425405) } },
    { { -INT16_C(  3075),  INT16_C( 21584),  INT16_C(   401),  INT16_C( 32486) },
      {  INT32_C(  1130399382), -INT32_C(   611339550), -INT32_C(   845521969),  INT32_C(   152441534) } },
    { { -INT16_C( 21138),  INT16_C(  4956), -INT16_C( 23530),  INT16_C( 11378) },
      { -INT32_C(    97832454), -INT32_C(  1206416096),  INT32_C(   755974729),  INT32_C(  1794982860) } },
    { {  INT16_C( 14112),  INT16_C( 18007), -INT16_C( 27977),  INT16_C( 32458) },
      {  INT32_C(   551136246), -INT32_C(   193544433),  INT32_C(   644377774), -INT32_C(  1432537430) } },
    { {  INT16_C( 26084),  INT16_C( 10518),  INT16_C(  3643), -INT16_C( 23720) },
      {  INT32_C(   209361689), -INT32_C(  1118674336),  INT32_C(  1543383519), -INT32_C(  1217514750) } },
    { { -INT16_C( 13353), -INT16_C( 29423),  INT16_C( 21810),  INT16_C( 14387) },
      { -INT32_C(  1985715694),  INT32_C(  1222291587), -INT32_C(  1034778829),  INT32_C(  1739439004) } }
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
    { { -INT32_C(   466875297),  INT32_C(   755895648) },
      {  INT64_C( 2981774409270693087),  INT64_C( 7109630125891380984) } },
    { {  INT32_C(  1588741214), -INT32_C(  1248422894) },
      { -INT64_C( 1348105263819914161),  INT64_C( 6278850728128457522) } },
    { {  INT32_C(  1852881481),  INT32_C(   860041260) },
      {  INT64_C( 3292726627115730135), -INT64_C( 2647988942019762238) } },
    { { -INT32_C(   826017646), -INT32_C(   561334640) },
      {  INT64_C( 2223873087727311197),  INT64_C( 5525423610048315645) } },
    { { -INT32_C(   569175652), -INT32_C(  1743119834) },
      {  INT64_C( 5147450309747424112), -INT64_C( 7291850426118956472) } },
    { {  INT32_C(    17142824),  INT32_C(   896407698) },
      { -INT64_C( 1227841125073959643), -INT64_C( 5041800972457947582) } },
    { {  INT32_C(   945258734),  INT32_C(   519427449) },
      {  INT64_C( 6713316207046746750),  INT64_C( 4308297428312032675) } },
    { {  INT32_C(   993411027),  INT32_C(   647571676) },
      {  INT64_C( 1161321915060888860),  INT64_C( 4367211887982110921) } }
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
    { { UINT8_C(238), UINT8_C(116), UINT8_C(143), UINT8_C(197), UINT8_C(220), UINT8_C(240), UINT8_C( 79), UINT8_C(230) },
      { UINT16_C(27042), UINT16_C(47574), UINT16_C( 7222), UINT16_C(30487), UINT16_C(52889), UINT16_C(41661), UINT16_C(20545), UINT16_C(45411) } },
    { { UINT8_C( 80), UINT8_C( 39), UINT8_C(142), UINT8_C(201), UINT8_C(250), UINT8_C(178), UINT8_C( 28), UINT8_C(250) },
      { UINT16_C(46340), UINT16_C(57476), UINT16_C(51391), UINT16_C(51170), UINT16_C(38194), UINT16_C(35054), UINT16_C(55061), UINT16_C(48848) } },
    { { UINT8_C( 65), UINT8_C(144), UINT8_C(105), UINT8_C(213), UINT8_C(169), UINT8_C( 72), UINT8_C(158), UINT8_C( 12) },
      { UINT16_C(47783), UINT16_C( 8310), UINT16_C( 7234), UINT16_C( 7636), UINT16_C(50339), UINT16_C(15492), UINT16_C( 8726), UINT16_C(39275) } },
    { { UINT8_C( 97), UINT8_C(153), UINT8_C( 20), UINT8_C(202), UINT8_C(192), UINT8_C(115), UINT8_C( 12), UINT8_C( 95) },
      { UINT16_C(43034), UINT16_C(22433), UINT16_C(29126), UINT16_C(58817), UINT16_C(63372), UINT16_C(27767), UINT16_C(17509), UINT16_C(14041) } },
    { { UINT8_C(221), UINT8_C(217), UINT8_C(136), UINT8_C(200), UINT8_C( 29), UINT8_C(152), UINT8_C( 70), UINT8_C(101) },
      { UINT16_C(62655), UINT16_C(27919), UINT16_C( 5941), UINT16_C(17336), UINT16_C(57446), UINT16_C(10098), UINT16_C(56864), UINT16_C(42823) } },
    { { UINT8_C(183), UINT8_C(141), UINT8_C(188), UINT8_C(205), UINT8_C(140), UINT8_C(228), UINT8_C( 87), UINT8_C(143) },
      { UINT16_C(17582), UINT16_C(21676), UINT16_C( 9603), UINT16_C(61731), UINT16_C(60643), UINT16_C(30242), UINT16_C(62421), UINT16_C(  779) } },
    { { UINT8_C(191), UINT8_C(230), UINT8_C(104), UINT8_C(135), UINT8_C(201), UINT8_C(193), UINT8_C(148), UINT8_C( 80) },
      { UINT16_C(41652), UINT16_C(50351), UINT16_C(25028), UINT16_C(56248), UINT16_C(51856), UINT16_C( 6834), UINT16_C(25952), UINT16_C(12274) } },
    { { UINT8_C(194), UINT8_C(174), UINT8_C( 78), UINT8_C( 82), UINT8_C( 37), UINT8_C( 61), UINT8_C( 40), UINT8_C( 23) },
      { UINT16_C(12072), UINT16_C( 3483), UINT16_C(12251), UINT16_C(24924), UINT16_C(28599), UINT16_C(64959), UINT16_C(17202), UINT16_C(58310) } }
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
     { { UINT16_C( 1813), UINT16_C(19849), UINT16_C(53546), UINT16_C(43720) },
      { UINT32_C( 614426629), UINT32_C(  63648377), UINT32_C(2947862823), UINT32_C(3389708007) } },
    { { UINT16_C(57970), UINT16_C( 8992), UINT16_C(47946), UINT16_C(13269) },
      { UINT32_C(2849228156), UINT32_C(4123066282), UINT32_C( 275279199), UINT32_C(2280198835) } },
    { { UINT16_C(25815), UINT16_C(53232), UINT16_C(49518), UINT16_C(55848) },
      { UINT32_C(2862299373), UINT32_C(3370457095), UINT32_C(4268450115), UINT32_C( 384359929) } },
    { { UINT16_C(19680), UINT16_C(36244), UINT16_C( 8179), UINT16_C(51544) },
      { UINT32_C(1328079361), UINT32_C( 767562585), UINT32_C(2655690073), UINT32_C(3217837085) } },
    { { UINT16_C( 9667), UINT16_C(49386), UINT16_C(62315), UINT16_C(63523) },
      { UINT32_C(2967598673), UINT32_C(2323028049), UINT32_C(2597944626), UINT32_C(2563032938) } },
    { { UINT16_C(51689), UINT16_C(28516), UINT16_C(26164), UINT16_C( 1626) },
      { UINT32_C(2486282434), UINT32_C(3624770958), UINT32_C(2066731907), UINT32_C(1305459855) } },
    { { UINT16_C(34511), UINT16_C(45861), UINT16_C(27318), UINT16_C( 6521) },
      { UINT32_C(3305217957), UINT32_C(  25039386), UINT32_C(3773245961), UINT32_C(2967948061) } },
    { { UINT16_C(59307), UINT16_C(11201), UINT16_C(50133), UINT16_C(34751) },
      { UINT32_C(1155417387), UINT32_C(3318996763), UINT32_C(1206045763), UINT32_C(1131288313) } }
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
    { { UINT32_C(1443492860), UINT32_C(2843329012) },
      { UINT64_C(14924895494802370230), UINT64_C(12891019238584277920) } },
    { { UINT32_C(1832149755), UINT32_C( 869126544) },
      { UINT64_C( 9797387520469021488), UINT64_C(  929219529536010651) } },
    { { UINT32_C( 191306914), UINT32_C(3980581195) },
      { UINT64_C(13893243554758096733), UINT64_C( 1579102529674796285) } },
    { { UINT32_C(3562212794), UINT32_C(2681077755) },
      { UINT64_C( 6872895307994526167), UINT64_C(  819605677338445096) } },
    { { UINT32_C(3698590747), UINT32_C(2568243207) },
      { UINT64_C(10807566427943484967), UINT64_C(13909489500636754730) } },
    { { UINT32_C(1983530783), UINT32_C( 424230695) },
      { UINT64_C( 4348599254494756402), UINT64_C(15396918982052926473) } },
    { { UINT32_C(3389393637), UINT32_C(2310046052) },
      { UINT64_C( 9032999240371131873), UINT64_C( 8763502628136845169) } },
    { { UINT32_C( 987357676), UINT32_C(1271655130) },
      { UINT64_C(15485922264544431045), UINT64_C(  616930701768902077) } }
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
    printf("rshrn_high_s16:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_s16) / sizeof(test_vec_s16[0])) ; i++) {
        int16x8_t a = vld1q_s16(test_vec_s16[i].a);
        int8x8_t  r = vld1_s8(test_vec_s16[i].r);
        print_int8x16(vrshrn_high_s16(r, a, 1));
        print_int8x16(vrshrn_high_s16(r, a, 3));
        print_int8x16(vrshrn_high_s16(r, a, 5));
        print_int8x16(vrshrn_high_s16(r, a, 6));
        print_int8x16(vrshrn_high_s16(r, a, 8));
    }
    
}

void f2(){
    printf("rshrn_high_s32:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_s32) / sizeof(test_vec_s32[0])) ; i++) {
        int32x4_t a = vld1q_s32(test_vec_s32[i].a);
        int16x4_t r = vld1_s16(test_vec_s32[i].r);
        print_int16x8(vrshrn_high_s32(r, a, 3));
        print_int16x8(vrshrn_high_s32(r, a, 6));
        print_int16x8(vrshrn_high_s32(r, a, 10));
        print_int16x8(vrshrn_high_s32(r, a, 13));
        print_int16x8(vrshrn_high_s32(r, a, 16));

        
    }
    
}

void f3(){
    printf("rshrn_high_s64:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_s64) / sizeof(test_vec_s64[0])) ; i++) {
        int64x2_t a = vld1q_s64(test_vec_s64[i].a);
        int32x2_t  r = vld1_s32(test_vec_s64[i].r);
        print_int32x4(vrshrn_high_s64(r, a, 6));
        print_int32x4(vrshrn_high_s64(r, a, 13));
        print_int32x4(vrshrn_high_s64(r, a, 19));
        print_int32x4(vrshrn_high_s64(r, a, 26));
        print_int32x4(vrshrn_high_s64(r, a, 32));
    }
    
}

void f4(){
    printf("rshrn_high_u16:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_u16) / sizeof(test_vec_u16[0])) ; i++) {
        uint16x8_t a = vld1q_u16(test_vec_u16[i].a);
        uint8x8_t  r = vld1_u8(test_vec_u16[i].r);

        print_uint8x16(vrshrn_high_u16(r, a, 1));
        print_uint8x16(vrshrn_high_u16(r, a, 3));
        print_uint8x16(vrshrn_high_u16(r, a, 5));
        print_uint8x16(vrshrn_high_u16(r, a, 6));
        print_uint8x16(vrshrn_high_u16(r, a, 8));
    }
    
}

void f5(){
    printf("rshrn_high_u32:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_u32) / sizeof(test_vec_u32[0])) ; i++) {
        uint32x4_t a = vld1q_u32(test_vec_u32[i].a);
        uint16x4_t  r = vld1_u16(test_vec_u32[i].r);
        print_uint16x8(vrshrn_high_u32(r, a, 3));
        print_uint16x8(vrshrn_high_u32(r, a, 6));
        print_uint16x8(vrshrn_high_u32(r, a, 10));
        print_uint16x8(vrshrn_high_u32(r, a, 13));
        print_uint16x8(vrshrn_high_u32(r, a, 16));
    }
    
}

void f6(){
    printf("rshrn_high_u64:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_u64) / sizeof(test_vec_u64[0])) ; i++) {
        uint64x2_t a = vld1q_u64(test_vec_u64[i].a);
        uint32x2_t  r = vld1_u32(test_vec_u64[i].r);
        print_uint32x4(vrshrn_high_u64(r, a, 6));
        print_uint32x4(vrshrn_high_u64(r, a, 13));
        print_uint32x4(vrshrn_high_u64(r, a, 19));
        print_uint32x4(vrshrn_high_u64(r, a, 26));
        print_uint32x4(vrshrn_high_u64(r, a, 32));
    }
    
}